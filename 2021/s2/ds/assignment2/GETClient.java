/*
	Brian Koh Lit Yang
	a1782291
	Distributed Systems Assignment 2
	GET Client
*/

import java.io.*;
import java.net.*;
import java.util.Scanner;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import java.io.File;
import org.xml.sax.InputSource;

import org.w3c.dom.NodeList;
import org.w3c.dom.Node;

// Client class
public class GETClient
{
	public static void stringToDom(String xmlSource) throws IOException
	{
        java.io.FileWriter fw = new java.io.FileWriter("feed.xml");
        fw.write(xmlSource);
        fw.close();
    }

	public static void print_XML_to_Text(String xml_input) throws Exception{

		/* parsing xml back into DOM style plain text */
		try {
			stringToDom(xml_input);
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse("feed.xml");

			doc.getDocumentElement().normalize();
			NodeList nList = doc.getElementsByTagName("feed");
			NodeList entryList = doc.getElementsByTagName("entry");

			for (int temp = 0; temp < nList.getLength(); temp++)
			{
				Node nNode = nList.item(temp);

				if (nNode.getNodeType() == Node.ELEMENT_NODE)
				{
					Element eElement = (Element) nNode;
					// appending output to string
					System.out.println("title:" + eElement.getElementsByTagName("title").item(0).getTextContent());
					System.out.println("subtitle:" + eElement.getElementsByTagName("subtitle").item(0).getTextContent());
					System.out.println("link:" + eElement.getElementsByTagName("link").item(0).getTextContent());
					System.out.println("updated:" + eElement.getElementsByTagName("updated").item(0).getTextContent());
					System.out.println("author:" + eElement.getElementsByTagName("name").item(0).getTextContent());
					System.out.println("id:" + eElement.getElementsByTagName("id").item(0).getTextContent());
				}
			}

			for (int temp = 0; temp < entryList.getLength(); temp++)
			{
				Node entryNode = entryList.item(temp);
				if (entryNode.getNodeType() == Node.ELEMENT_NODE)
				{
					Element eElement = (Element) entryNode;
					System.out.println("entry");
					System.out.println("title:" + eElement.getElementsByTagName("title").item(0).getTextContent());
					System.out.println("link:" + eElement.getElementsByTagName("link").item(0).getTextContent());
					System.out.println("id:" + eElement.getElementsByTagName("id").item(0).getTextContent());
					System.out.println("updated:" + eElement.getElementsByTagName("updated").item(0).getTextContent());
					System.out.println("summary:" + eElement.getElementsByTagName("summary").item(0).getTextContent());
				}
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws IOException
	{
		try
		{
			AggregationServer object = new AggregationServer();
			Scanner scn = new Scanner(System.in);

			// getting localhost ip
			InetAddress ip = InetAddress.getByName("localhost");
			int port = 4567;
			if (args.length > 0){
				port = Integer.parseInt(args[0]);
			}
			// establish the connection with server port 4567
			Socket s = new Socket(ip, port);

			// obtaining input and out streams
			DataInputStream dis = new DataInputStream(s.getInputStream());
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());

			// the following loop performs the exchange of
			// information between client and client handler
			while (true)
			{
				object.lamport++;
				System.out.println(dis.readUTF());
				System.out.println(" ------------------ Enter a command [GET | exit] --------------------- ");
				String tosend = scn.nextLine();
				dos.writeUTF(tosend);

				// If client sends exit,close this connection
				// and then break from the while loop
				String received = dis.readUTF();
				System.out.println(" --------------- HEADERS ------------------- \n" + received);

				System.out.println("Lamport Clock:" + object.lamport + "\n");

				if (tosend.equals("GET"))
				{
					try{
						String ATOM_XML = dis.readUTF();
						print_XML_to_Text(ATOM_XML);
					}
					catch(Exception e)
					{
						e.printStackTrace();
					}
				}
				else if(tosend.equals("exit"))
				{
					System.out.println("Closing this connection : " + s);
					s.close();
					System.out.println("Connection closed");
					break;
				}
				else
				{
					System.out.println("invalid option");
				}
			}
			// closing resources
			scn.close();
			dis.close();
			dos.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}