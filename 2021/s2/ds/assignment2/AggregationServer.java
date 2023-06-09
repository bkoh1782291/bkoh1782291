/*
	Brian Koh Lit Yang
	a1782291
	Distributed Systems Assignment 2
	Aggregation Server
*/
import java.io.*;
import java.text.*;
import java.util.*;
import java.net.*;
import java.util.concurrent.*;

// Server class
public class AggregationServer
{
	/*
		ATOM Server object
		holds xml data, id, heartbeat values and lamport clocks in each object
		objects used for easy message manipulation
	*/
	String xml_data;
	int id = 0;
	String heartbeat_msg;
	int lamport;
	boolean first_http = true;

	public static int heartbeat_length = 12;
    public static int resend_count = 0;
	public static Deque<AggregationServer> deque = new ArrayDeque<AggregationServer>();
	public static AggregationServer object = new AggregationServer();
	// initializing port

	// function to hold the heartbeat method
	public static void heartbeat(){

		int timer = 0;
		// sending heartbeat message to the client
		try{
			while (timer > -1 && resend_count < 50)
			{
				TimeUnit.SECONDS.sleep(1);
				timer++;

				if (timer == 12 && Thread.currentThread().isAlive() == true)
				{
					resend_count++;
					System.out.println("\nClient {" + Thread.currentThread().getName() + "} is Alive !");
					timer = 0;
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("\nClient {" + Thread.currentThread().getName() + "} has Disconnected.");
			e.printStackTrace();
		}
	}


	public static void main(String[] args) throws IOException
	{
		int port = 4567;
		if (args.length > 0){
			port = Integer.parseInt(args[0]);
		}
		ServerSocket ss = new ServerSocket(port);

		// running infinite loop for getting client request
		while (true)
		{
			Socket s = null;
			try
			{
				System.out.println("Server started listening on port : " + Integer.toString(port));
				// socket object to receive incoming client requests
				s = ss.accept();

				System.out.println("A new client is connected : " + s);

				// obtaining input and out streams
				DataInputStream dis = new DataInputStream(s.getInputStream());
				DataOutputStream dos = new DataOutputStream(s.getOutputStream());

				System.out.println("Assigning new thread for this client");

				// create a new thread object
				Thread t = new ClientHandler(s, dis, dos);

				// Invoking the start() method
				t.start();
			}
			catch (Exception e)
			{
				System.out.println("Closing connection");
				s.close();
				e.printStackTrace();
			}
		}
	}

	// ClientHandler class
	/*
		handles both the content server and the GET client
		handles the request based on input recieved
		if PUT request, it will send appropriate headers and HTTP status codes
		if GET Request, it will send appropriate headers and pop contents off the queue
	*/
	public static class ClientHandler extends Thread
	{
		final DataInputStream dis;
		final DataOutputStream dos;
		final Socket s;

		// Constructor
		public ClientHandler(Socket s, DataInputStream dis, DataOutputStream dos)
		{
			this.s = s;
			this.dis = dis;
			this.dos = dos;
		}

		@Override
		public void run()
		{
			// creating new object for ATOM server
			object.xml_data = "";
			object.id++;

			String received;
			String output;
			String line;

			// Initializing an deque
			String xmloutput = "";

			while (true)
			{
				try {
					dos.writeUTF("Connection To ATOM Server Successful !");
					// receive the answer from client
					received = dis.readUTF();

					if(received.equals("exit"))
					{
						System.out.println("\n:-------------------------------------------------------------------: ");
						System.out.println("Client " + this.s + " sends exit...");
						System.out.println("Closing this connection.");
						System.out.println("Connection closed");
						System.out.println(":----------------------------------------------------------------------:\n ");
						this.s.close();
						break;
					}

					switch (received) {
						case "GET":
							// GET request from the output client server
							// Follow the HTTP protocol of GET <path> HTTP/1.0 followed by an empty line
							System.out.println("\n --------------------- GET REQUEST RECIEVED -------------------------- ");
							output = "GET " + "http://localhost:" + Integer.toString(s.getPort()) + " HTTP/1.1" + '\n' + "200 OK" + '\n';
							dos.writeUTF(output);

							// printing out headers
							object.lamport++;
							System.out.println("lamport clock : " + object.lamport);
							System.out.println("\nGET /atom.xml HTTP/1.1");
							System.out.println("User-Agent: ATOMClient/1.0");
							System.out.println("Content-Type: text/xml");
							System.out.println("Content-Length: " + xmloutput.length() + '\n');

							if (deque.isEmpty())
							{
								System.out.println("queue is empty!");
								break;
							}
							// writing xml back into GETClient
							dos.writeUTF(deque.pop().xml_data);
							break;
						case "PUT":
							// PUT request from the content server
							// Follow the HTTP protocol of PUT <path> HTTP/1.0 followed by an empty line
							System.out.println("\n --------------------- PUT REQUEST RECIEVED -------------------------- ");
							output = "PUT " + "http://localhost:" + Integer.toString(s.getPort()) + " HTTP/1.1" + '\n' + "200 OK" + '\n';
							dos.writeUTF(output);

							// reading xml from content server
							line = (String)dis.readUTF();

							// append xml string to queue
							xmloutput = xmloutput + line;

							// assigning xml output into serialized object
							object.xml_data = xmloutput;
							deque.push(object);

							// printing out headers
							object.lamport++;
							System.out.println("lamport clock : " + object.lamport);
							System.out.println("\nPUT /atom.xml HTTP/1.1");
							System.out.println("User-Agent: ATOMClient/1.0");
							System.out.println("Content-Type: text/xml");
							System.out.println("Content-Length: " + xmloutput.length());

							/* printing out HTTP status codes */
							if (object.first_http == true && !object.xml_data.isEmpty()){
								System.out.println("HTTP 201 - HTTP_CREATED");
								// object.lamport++;
							}
							else if (object.first_http == false && !object.xml_data.isEmpty()){
								System.out.println("HTTP 200 - OK");
								// object.lamport++;
							}
							else if (object.first_http == false && object.xml_data.isEmpty()){
								System.out.println("HTTP 204 - NO_CONTENT");
							}
							else {
								System.out.println("HTTP 500 - INTERNAL_ERROR");
							}
							break;
						default:
							dos.writeUTF("Invalid input");
							break;
					}

					// System.out.println(xmloutput);
					// resetting xml string
					xmloutput = "";

					// calling heartbeat method
					heartbeat();
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}
			try
			{
				// closing resources
				this.dis.close();
				this.dos.close();

			}
			catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}