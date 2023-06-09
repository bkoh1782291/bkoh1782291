/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	| FileReading.java						  |
	-------------------------------------------
	class file for holding functions for
	reading data from member files and writing output to files
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.*;

public class FileReading extends Council_Members{
    FileReading(int MID, int port) {
        super(MID, port);
    }

    public static String readLocalData(String Path)throws IOException {
        File file = new File(Path);
        String content = "";
        if (!file.exists()) {
            file.createNewFile();
        } else if (file.exists() && file.length() != 0) {
            content = "";
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line = br.readLine();
            do {
                content += line + "\n";
                line = br.readLine();
            } while (line != null);
            br.close();
        }
        return content;
    }

	/*
		function to write final proposed value into text files for storage.
	*/
	public static void write_toFile(Object content, String path_to_file, int MemberID)
	{
		String toWriteData = content.toString();
		FileWriter writer;
		try {
			writer = new FileWriter(path_to_file);
			writer.write(toWriteData);
			writer.flush();
			writer.close();
		} catch (IOException e) {
			System.out.println("Error in save to local Data. Please Check connection of M" + MemberID);
			e.printStackTrace();
		}
	}


}