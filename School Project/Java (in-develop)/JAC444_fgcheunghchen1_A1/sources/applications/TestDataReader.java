package applications;

import java.io.*;
import useful.*;

/**
 * Application to test the DataReader
 * <p>This program includes the useful package. It simply
 * calls methods from the DataReaderImpl_1.java. It receives
 * standard inputs and will read the data line by line. 
 * will skip the comments and prints out the data.</p>
 *  
 *  @version 1.0
 *  @author Freddy Cheungh
 */
public class TestDataReader
{
	//============================================static data
	// none

	//============================================instance data
	/** Stores command-line args as instance var(s) */
	private String[] names;  
	/** Will hold the lines readed by the buffer */
	private String temp = null;	
	/** Holds the old marker value (if needed) */
	private String resetValue = null;
	/** Holds the value of the new marker */
	private String mkr = null;
    /** Creates a private instance of a class DataReaderImpl_1 an initializes with the default constructor*/
	private DataReaderImpl_1 reader = new DataReaderImpl_1();

	//============================================constructors
	// none defined ( :. default constructor provided by compiler )

	//============================================methods
	//=========================(alphabetic by method name)

	//--------------------------------------------init()
	/**
	 * Performs one-time intialization at start of application
	 * typically the following...
	 * <p>processes the command-line arguments.</p>
	 * <p>opens input and/output files or database(s)</p> 
	 * <p>opens network connections</p>
	 *
	 * @param args arguments from command-line
	 */
	private String init(String[] args)
	{
		String temp = "";
		if (args.length > 0)
		{
			//--- display the message on standard output

			// the following is necessary to capture the arguments 
			// as instance variables if they need to be processed in other methods
			names = new String[args.length];
			for (int k = 0; k < args.length; k++)
			{
				names[k] = args[k];    
			}
			System.out.println();
		}
		else
		{
			System.err.println("This program ignores any command line args!");
			usage();      // display usage message (run instructions)
		}
		return temp;
	} // end of init()
		
	//--------------------------------------------run()
	/**
	 * Controls the major part of the application (typically in 
	 * a loop which reads input file(s). 
	 * <p>This application will read each line of the input
	 * buffer and will check for a comment marker value. If marker is
	 * available, it will call a method called resetMarker within
	 * the DataReaderImpl_1 class.</p>
	 * <p>This application will also skip any comment that starts with
	 * the marker value, for instance if the marker is "//" then everything
	 * followed by a "//" will be ignored.</p>
	 */
	private void run()
	{
		temp = reader.readLine();
		//sets the marker to it's default value (#).
		if (!temp.isEmpty() && temp.equals("#"))
		{
			mkr = "#";
		}
		else if (!temp.isEmpty() && !temp.equals("#"))
		{
			mkr = temp; //sets the the new marker value equal to the first value of the std input.
		}
		else if (temp.isEmpty())
		{
			mkr = null;	//set the new marker to null if no marker value is found.
		}
		while (temp != null) 
		{
			System.out.println(temp); //prints the data
			resetValue = reader.resetMarker(mkr);		//resets the marker back to the marker assigned
													//by the .txt
			if (temp != null)	//if it's not end of file, it will keep reading.
			{
				temp = reader.readLine();
			}
			if (temp == null)	//if it's the EOF it will set temp to finish and break the loop
			{
				temp = "finish";
				break;
			}
		}
	}  // end of run()
	
	//--------------------------------------------usage()
	/**
	 * Displays a help message for how to use this application
	 */
	private void usage()
	{
		System.err.println("\n+++Beggining of the Program+++\n");
		System.err.println("USAGE IS: " 
				+ "it will read the file through redirection. Will take the first line of the .txt as a value to the marker\n");
	} // end of usage()
	
	//--------------------------------------------wrap()
	/**
	 * Performs one-time cleanup just before the application ends.
	 * <p>closes input and/output files or database(s)</p> 
	 * <p>closes network connections</p>
	 */
	private int wrap()
	{
		int retval = 0;
		reader.close();	//closes the bufferedreader connection.
		System.out.println("\n+++Program Ending+++");
		return retval;
	}  // end of wrap()
	
	/**
	 * Main() method, it will simply make a call of init(args),
	 * run() and wrap method. All the work will be done in those 
	 * methods. Main() will only be responsable for calling
	 * those three methods mentioned above. 
	 * */
	public static void main(String[] args) throws IOException
	{
		TestDataReader readerTest = new TestDataReader();
		readerTest.init(args);
		readerTest.run();
		readerTest.wrap();
	} // end of main()
} // end of class
