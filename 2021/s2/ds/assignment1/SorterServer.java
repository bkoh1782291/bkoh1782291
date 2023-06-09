// Brian Koh Lit Yang
// a1782291

import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class SorterServer extends SorterImplementation {
	public SorterServer() {
	}

	public static void main(String args[]) {
		try {
			// Instantiating the implementation class
			SorterImplementation obj = new SorterImplementation();

			// Exporting the object of implementation class
			// (here we are exporting the remote object to the stub)
			Sorter stub = (Sorter) UnicastRemoteObject.exportObject(obj, 0);

			// Binding the remote object (stub) in the registry
			Registry registry = LocateRegistry.createRegistry(1234);

			registry.bind("Sorter", stub);

			System.err.println("Server ready");
		} catch (Exception e) {
			System.err.println("Server exception: " + e.toString());
			e.printStackTrace();
		}
	}
}