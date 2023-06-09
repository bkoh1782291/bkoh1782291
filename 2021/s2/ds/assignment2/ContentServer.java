
/*
	Brian Koh Lit Yang
	a1782291
	Distributed Systems Assignment 2
	Content Client

	Content Server (content serving client)
	parses text input and serves it to the ATOM server
*/

import java.net.*;
import java.io.*;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.sound.sampled.Port;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.transform.Transformer;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import java.io.File;
import java.util.concurrent.*;
import java.util.Scanner;

public class ContentServer
{
	// initialize socket and input output streams
	private Socket socket = null;
	private DataInputStream input = null;
	private DataOutputStream out = null;
	public static int heartbeat_length = 12;
    public static int resend_count = 0;

	public static void main(String argv[]) throws IOException
	{
		AggregationServer object = new AggregationServer();
		/* DOM XML parser initialization and implementation */
		try {
			// initializing xml parser
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.newDocument();

			// root element
			Element rootElement = doc.createElement("feed");
			Element feed_pointer = rootElement;
			doc.appendChild(rootElement);
			Attr xml_lang = doc.createAttribute("xml-lang");
			xml_lang.setValue("en-US");
			rootElement.setAttributeNode(xml_lang);
			Attr xmlns = doc.createAttribute("xmlns");
			xmlns.setValue("http://www.w3.org/2005/Atom");
			rootElement.setAttributeNode(xmlns);

			/* -------------------------------- reading input ------------------------------------- */

			// reading input from text file using buffer
			File file = new File(argv[0]);

			BufferedReader br = new BufferedReader(new FileReader(file));

			String st;
			String part1, part2;
			int index = 0;

			while ((st = br.readLine()) != null)
			{
				// storing indexOf semi-colon for substr
				index = st.indexOf(":");

				if (index > 0) {
					part1 = st.substring(0, index);
					part2 = st.substring(index + 1);

					if (!part1.equals("author"))
					{
						Element first = doc.createElement(part1);
						feed_pointer.appendChild(first);
						first.appendChild(doc.createTextNode(part2));
						feed_pointer.appendChild(first);
					}
					else if (part1.equals("author"))
					{
						Element author = doc.createElement("author");
						Element name = doc.createElement("name");
						name.appendChild(doc.createTextNode(part2));
						author.appendChild(name);
						feed_pointer.appendChild(author);
					}
				}
				else if (index < 0)
				{
					// System.out.println("\n----------- entry found ---------- !");
					feed_pointer = rootElement;
					Element entry = doc.createElement("entry");
					feed_pointer.appendChild(entry);
					feed_pointer = entry;
				}
			}

			br.close(); // close the buffer

			// format and write the content into xml file
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			transformer.setOutputProperty(OutputKeys.INDENT, "yes");
			transformer.setOutputProperty(OutputKeys.DOCTYPE_PUBLIC, "yes");
			transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "4");

			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(new File("output.xml"));
			transformer.transform(source, result);

			// Output to console for testing
			// StreamResult consoleResult = new StreamResult(System.out);

			StringWriter writer = new StringWriter();
			transformer.transform(source, new StreamResult(writer));
			String xmlString = writer.getBuffer().toString();

			// System.out.println("test print ------------------ \n");
			// System.out.println(xmlString);

			// opening socket connection
			// writing to ATOM Server
			try{
				Scanner scn = new Scanner(System.in);

				// getting localhost ip
				InetAddress ip = InetAddress.getByName("localhost");

				int port = 4567;

				if (argv.length > 1){
					port = Integer.parseInt(argv[1]);
				}

				Socket s = new Socket();

				try{
					// establish the connection with server port 4567
					System.err.println("Attempting to Connect to server with port :" + port);
					s = new Socket(ip, port);
				}
				catch (IOException e){
					System.err.println("unable to connect with ATOM server, retry 3 times");
					int idx = 0;
					while(idx < 3)
					{
						System.out.println("Attempting to reconnect ...........");
						try
						{
							idx++;
							Thread.sleep(3 * 2000);
							s = new Socket("localhost", port);
							System.err.println("Connection succesful !");
							index++;
							break;
						}
						catch (InterruptedException|IOException e2)
						{
							System.out.println("unable to connect to server");
						}
					}
				}

				// obtaining input and out streams
				DataInputStream din = new DataInputStream(s.getInputStream());
				DataOutputStream dout = new DataOutputStream(s.getOutputStream());

				// exchange of information between client and client handler
				int flag = 0;
				while(flag == 0)
				{
					object.id += 1;
					object.lamport++;
					// System.out.println(din.readUTF());
					System.out.println(" ------------------ Enter a command [PUT | exit] --------------------- ");
					String tosend = scn.nextLine();

					// dout.writeUTF(xmlString);
					if (tosend.equals("PUT"))
					{
						dout.writeUTF("PUT");
						System.out.println(" <<<<<<<<<<<<<<<<<<<<<<<<<< PUT REQUEST SENT >>>>>>>>>>>>>>>>>>>>>>>>>>>> " + '\n');
						dout.writeUTF(xmlString);
					}
					else if(tosend.equals("exit"))
					{
						dout.writeUTF("exit");
						System.out.println("Closing this connection : " + s);
						s.close();
						System.out.println("Connection closed");
						break;
					}
					else
					{
						System.out.println("invalid option");
					}
					String recieved = din.readUTF();
					System.out.println(recieved);
					System.out.println("lamport clock: "+object.lamport+"\n");
					flag = 1;
				}

				int timer = 0;
				// sending heartbeat message to the server
				try{
					while (timer > -1 && resend_count < 50)
					{
						TimeUnit.SECONDS.sleep(1);
						timer++;
						// System.out.print(timer + " ");
						System.out.println("Type exit to close this connection :");
						String tosend = scn.nextLine();
						if(tosend.equals("exit"))
						{
							dout.writeUTF("exit");
							System.out.println("Closing this connection : " + s);
							s.close();
							System.out.println("Connection closed");
							break;
						}
						if (timer == 12)
						{
							resend_count++;
							System.out.println(timer + " ");
							System.out.println("\n Server Alive ! \n");
							timer = 0;
						}
					}
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}

				// closing resources
				scn.close();
				din.close();
				dout.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
