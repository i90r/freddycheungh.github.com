// HelloWorldOO.java - application class

import java.io.*;

/**
 * Accepts a user input and calculates possibilities
 * <p>
 * This application will accept an user input. It will take the user input 
 * and calculate the possible combinations with upper and lower case letters.
 * It will also take in consideration the period, changing it into a '>'
 * </p>
 * @version 1.0
 * @author Freddy Cheungh
 */
public class Lab2A_2 
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

	public int checkCase(String data)
	{
		int retval = 0, possibleCombination = 1 << data.length();
		String test = data.toLowerCase();	//holds the String data sent by the user
		String [] track = new String[possibleCombination];	//initialize an array of string. Use to store combination
		if (data.length() <= 0 || data.trim().length() == 0 || data.length() > 8) //check if user inputs something or not
		{
		 	System.out.println("You must enter an 8 character long name ");
		 	System.out.println("(only alphabetic characters and a period is accepted)");
		 	init();
		}
		else
		{
			// declare and initialize variables
			
			for (int i = 0; i < possibleCombination; i++) 
			{
				StringBuilder buffer = new StringBuilder(test);	//created an instance of StringBuilder and initialized it with test.
				for (int j = 0; j < data.length(); j++) 
				{
					if(test.charAt(j) == '.')	//if a period is found, it will be substitute with a '>'
					{
						buffer.setCharAt(j, '>');
						test = test.substring(0, j) + ">" + test.substring(j + 1);
					}
					else if((i & 1 << j) != 0) 	// otherwise, it will simply turn the current character to upper case
					{
						String s = data.substring(j, j + 1).toUpperCase();
						buffer.replace(j, j + 1, s);
					}
				}
				System.out.println(buffer);
			}			
		}
		run(data.toString(), track.length);	//calls the method run
		return retval;
	} // public int checkCase(String data)
	
	// --------------------------------------------init()
	/**
	 * It will run once the program starts. Prompts the user a question, and waits for the user to 
	 * input an answer. Once the user inputs something, it will take the user input and store it 
	 * in a variable, which will be returned and used for checking.
	 */
	private String init()
	{	
		String buf = "";
		br = new BufferedReader(new InputStreamReader(System.in));
		try
		{
			System.out.println("Enter an 8 character long name (only alphabetic characters and a period is accepted): ");
			buf = br.readLine();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return buf;
		
	} // end of init()

	// --------------------------------------------run()
	/**
	 * It will be called on checkCase method. It will simply output the results to the user.
	 * @param data
	 * 			  contains the user input
	 * @param num
	 * 			  contains the number of combination possibles
	 */
	private void run(String data, int num) 
	{
		System.out.println("\nSummary:\n");
		System.out.println("The value of the paramenter                                        : " + data);
		System.out.println("The number of words in the array                                   : " + num);
		System.out.println("The number of words in the array that match the paramter           : " + "1");
		System.out.println("The number of words in the array that do NOT match the paramter    : " + --num);
		
	} // end of run()

	// --------------------------------------------wrap()
	/**
	 * Method that will terminate the program. In this case it will only show a message
	 * saying that the program has ended.
	 */
	private int wrap() 
	{
		int retval = 0;
		System.out.println("+++program ending+++");
		return retval;
	} // end of wrap()

	// --------------------------------------------main()
	/**
	 * Called once the program is run. This method will call init(), checkCase(String)
	 * and wrap in this respective order.
	 */
	public static void main(String[] args) throws IOException 
	{
		Lab2A_2 theApp = new Lab2A_2(); // make object of own class
		// Declare variables.
		String parameter = "";
		parameter = theApp.init();
		theApp.checkCase(parameter);
		theApp.wrap();
	} // end of main()
	
} // end of class
