package Lab3;

import java.io.*;
import Useful.*;

/**
 * Application which displays a welcome message on standard output.
 * <p>This program  illustrates a "divide and conquer' strategy
 * to make the program more Object Oriented </p>
 *
 * <p>The basic design of this application will be used for most
 * applications in this and the following Java course(s). This
 * design is no accident!  It is based on he idea that things
 * have a "correct" place, which the experience of many professional
 * programmers have confirmed has many advantages</p>
 *
 * <p>The biggest single advantage of this is the way the main()
 * int(), run() and wrap() to organize the rest of the program. It sets
 * the practice that will be extended later.  There is no need for
 * any other instructions to be added to main() so that code will
 * NEVER have to be written again (for the rest of your programming
 * life!).</p>

 * <p>For the time being you are asked to take that as true and follow
 * this example so that the advantages can be revealed in due course.</p> 
 *
 *  @version 1.0
 *  @author Freddy Cheungh
 */
public class Lab3
{
	//============================================static data
	// none

	//============================================instance data
	/** In which to store args from command line  */
	private String[] names;   // to store command-line args  as instance var(s)
	/** Private instace of the BufferedReader, used to read and accept user inputs*/
	private BufferedReader br;
	//private FileInputStream fstream;
	//private DataInputStream input;
	private FileReader input;
	private String incoming, inFormat, outFormat;
	
	

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
	private String init()
	{
		String temp = "";
		
		br = new BufferedReader(new InputStreamReader(System.in));
		
		//buf = br.readLine();
/*		
		while(buf!=null)
		{
			System.out.println("this is buf " + buf);
			buf = br.readLine();
		}
	*/
		
		return temp;
		
		//------------------------------------------------------------
		//../data/filename
/*		String buf = "";
		try
		{
			  Sets up a file reader to read the file passed on the command
			line one character at a time 
			input = new FileReader(args[0]);
			              
			 Filter FileReader through a Buffered read to read a line at a
			time 
			br= new BufferedReader(input);
       
			String line;    // String that holds current file line
			int count = 0;  // Line number of count 
      
			// Read first line
			line = br.readLine();
			count++;
			
			String[] temp = new String[3];
			//String[] temp = { " ", " ", " "};
			// Read through file one line at time. Print line # and line
			while (line != null)
			{
				try{
				System.out.println(count+": "+line);
				temp = line.split("\\,");
				line = br.readLine();  
			
				incoming = temp[0];
				inFormat = temp[1];
				outFormat = temp[2];
				
				
				DateFormat formatter;
				Date date;
				formatter = new SimpleDateFormat(outFormat);
				date = (Date)formatter.parse(incoming);
				String s = formatter.format(date);
				System.out.println("Today is " + s);
				Date date = new SimpleDateFormat(inFormat).parse(incoming);
				Date newDate = new SimpleDateFormat(outFormat).format(date);
				System.out.println("this is date: " + newDate);
				
				//run();
				System.out.println("This is split: " + temp[0].trim() + " + " + incoming );
				System.out.println("This is split: " + temp[1].trim());
				System.out.println("This is split: " + temp[2].trim());
				System.out.println("This is LINE: " + line);
			    count++;
				}
				catch (ParseException e)
				  {System.out.println("Exception :"+e);  }  
			}
			System.out.println("This is TEMP: " + temp);
			System.out.println("This is LINE: " + line);
		}
		catch(NullPointerException e)
		{
			System.err.println("Error: " + e.getMessage());
			//e.printStackTrace();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return buf;
		*/
		
		
		//---------------------------------------------------------------
		
/*		String buf = "";
		int i = 0;
		String[] temp;
		// Open file
		File file = new File("test.txt");
		try
		{
		//fileReader = new FileReader("Lab3.txt");
		//br = new BufferedReader(fileReader);
		//fstream = new FileInputStream("C:\\Users\\Freddy\\JAC444\\JAC444_fgcheunghchen1_L3\\sources\\Lab3\\Lab3.txt");
			fstream = new FileInputStream(file);
			input = new DataInputStream(fstream);
			br = new BufferedReader(new InputStreamReader(input));
			buf = br.readLine();
			if (buf.length()!=0)
			{
				temp = buf.split(",");
				dates[i] = temp[i];
				i++;
			}
		}
		catch (IOException e) 		//catches java's unhandled exceptions
		{
			e.printStackTrace();	//will store/print it into a stack tracer
		}
		System.out.println(dates);
		//System.out.println("dates: " + dates[0] + " + " + dates[1]);
		return buf;*/
	} // end of init()

	//--------------------------------------------run()
	/**
	 * Controls the major part of the application (typically in 
	 * a loop which reads input file(s).  But, in this example,
	 * the task is trivial.
	 */
	private void run() throws IOException
	{
		Useful date = new Useful();
		String[] temp;
		String buf = "", test ="", incoming = "", inFormat = "", outFormat = "";
		buf = br.readLine();
				
		while ( buf != null)
		{
			System.out.println("this is buf " + buf);
			temp = buf.split("\\,");
			incoming = temp[0].trim();
			inFormat = temp[1].trim();
			outFormat = temp[2].trim();
		
			test = date.convertDate(incoming, inFormat, outFormat);
			System.out.println("this is test " + test);
			buf = br.readLine();  
		
		
			
			
			//buf = br.readLine();
		}
			
		System.out.println("Hello World!");
	}  // end of run()

	//--------------------------------------------usage()
	/**
	 * Displays a help message for how to use this application
	 */
	private void usage()
	{
		System.err.println("USAGE IS: " +
				"java HelloWorldOO # any args ignored");
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
		try	
		{
			br.close();
			System.out.println("+++program ending+++");
		}
		catch (IOException e) 		//catches java's unhandled exceptions
		{
			e.printStackTrace();	//will store/print it into a stack tracer
		}
		return retval;
	}  // end of wrap()

	//--------------------------------------------main()
	/**
	 * This is the first method called. It makes an object or its
	 * own class then calls methods init(), run() and wrap() in that
	 * sequence. Thus it clearly and completely controls the application
	 * (but the major work is delegated to be done in the init(), run() and
	 * wrap() methods).
	 */
	public static void main(String[] args) throws IOException
	{
		Lab3 theApp = new Lab3(); // make object of own class
		File file = new File("README.txt");
		System.out.println(file.getCanonicalPath());

		theApp.init();                        // then call its methods
		theApp.run();
		theApp.wrap();
	} // end of main()

} // end of class
