// HelloWorldOO.java - application class

import java.io.*;

/**
 * Application which will convert an user input string.
 * <p>
 * This program will take the user input (variable name) and it will transform
 * it into a ordinary phrase. For instance, user inputs "currentPosition" as his
 * variable name, this program with take that input and convert it into a more
 * human readable string, in this case "Current Position".
 * </p>
 * <p>
 * This application will consist on several private methods such as, 
 * varNameToPrompt(String), init(), run(String), wrap() and main().
 * Each of these will be explain below.
 * </p>
 * 
 * @version 1.0
 * @author Freddy Cheungh
 */
public class Lab2A_1
{
	// ============================================static data
	// none

	// ============================================instance data
	/** Private instace of the BufferedReader, used to read and accept user inputs*/
	private BufferedReader br;

	// ============================================constructors
	// none defined ( :. default constructor provided by compiler )

	// ============================================methods
	// =========================(alphabetic by method name)

	// --------------------------------------------init()
	/**
	 * Performs one-time intialization at start of this application. It will do the following:
	 * <p>
	 * <li><ol>Prompt the user a request.</ol>
	 * <ol>Store the user input into a variable called buf.</ol>
	 * <ol>Return the stored variable.</ol>
	 * </p>
	 */
	private String init()
	{
		String buf = "";
		br = new BufferedReader(new InputStreamReader(System.in)); // initializes br
		try 
		{
			System.out.println("Please enter a variable name:");
			buf = br.readLine();	//stores the user input into buf

		} 
		catch (IOException e) 		//catches java's unhandled exceptions
		{
			e.printStackTrace();	//will store/print it into a stack tracer
		}

		return buf;
	} // end of init()

	// --------------------------------------------run(String data)
	/**
	 * Accepts data and will simply display it to the user. This method will
	 * be called once everything is succesfully executed.
	 * @param data
	 * 		  contains the final string to be outputed
	 */
	private void run(String data)
	{
		System.out.println("You have chosen '" + data + "' as a variable name.");
	} // end of run(String data)

	//-------------------------------------varNameToPrompt(String data)
	/**
	 * Accepts a string (which will be the user input). It will take the string,
	 * check if the string is empty or not, if so, it will display an error message.
	 * If it's not empty, it will perform the following:
	 * <p>
	 * Trim any leading and following white space.
	 * </p>
	 * <p>
	 * Uppercase the first character.
	 * </p>
	 * <p>
	 * A single space is inserted before the first of any substring of upper case characters
	 * </p>
	 */
	private String varNameToPrompt(String data)
	{  
		if (data.length() <= 0 || data.trim().length() == 0) //check if user inputs something or not
		{
		 	System.out.println("You have not entered a variable name.");
		}
		else
		{
			data = data.trim(); // trims leading white spaces
			String temp = data; 
			int caps =0; 		// check for how many uppercase char
			for (int i = 0; i < data.length(); i++)
			{
				if (Character.isUpperCase(data.charAt(i)) && i > 0) // will execute if an uppercase char is found
				{
					// Will separate the string, add a space and then concatenate the two splitted string back together
					temp = temp.substring(0, i + caps).concat(" " + data.substring(i , data.length()));	
					caps++;
				}
			}
			// uppercase the first letter of the string
			data = data.substring(0, 1).toUpperCase() + temp.substring(1, temp.length());
		}
		return data;
	} // end of varNameToPrompt(String data)
	
	// --------------------------------------------wrap()
	/**
	 * Performs one-time cleanup just before the application ends.
	 * <p>
	 * Outputs a message showing the program has been terminated. In other
	 * cases, it will close network connections and terminate input/output
	 * files.
	 * </p>
	 */
	private int wrap() 
	{
		int retval = 0;
		System.out.println("+++program ending+++");
		return retval;
	} // end of wrap()
	
	// --------------------------------------------main()
	/**
	 * This is the first method called. It makes an object of its own class then
	 * calls methods init(), varNameToPromt(String), run(String) and wrap() in that sequence. 
	 */
	public static void main(String[] args) throws IOException 
	{
		Lab2A_1 theApp = new Lab2A_1(); // make object of own class
		// create and instantiate variables
		String varName = "", data = "";
		varName = theApp.init(); 
		data = theApp.varNameToPrompt(varName);
		theApp.run(data);
		theApp.wrap(); 
	} // end of main()

} // end of class
