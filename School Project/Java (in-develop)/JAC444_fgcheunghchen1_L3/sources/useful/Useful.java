package Useful;

import java.io.*;

/**
 * Application which displays a welcome message on standard output.
 * <p>This program  illustrates a "divide and conquer' strategy
 * to make the program more Object Oriented </p>
 *  @version 1.0
 *  @author Brian Perry
 */
public class Useful
{
	//============================================static data
	// none

	//============================================instance data
	/** Private instace of the BufferedReader, used to read and accept user inputs*/
	private BufferedReader br;
	
	//============================================constructors
	// none defined ( :. default constructor provided by compiler )

	//============================================methods
	//=========================(alphabetic by method name)

	public static String convertDate(String incoming, String informat, String outformat)
	{
		String convertedDate = "";
		//* DD-MM-YYYY
		//* MM/DD/YYYY
		//* YYYYMMDD
		//* DD-MON-YYYY

		//Day = DD
		//Month = MM  or MON
		//Year = YYYY
		char x, y;
		
		String[] monthArr = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
		String day = "", month = "", year = "";
		
		int check = 0, count = 0, monthNum = 0;
		int incomingSlash = 0, incomingDash = 0, incomingDot = 0;
		while (check == 0)
		{
/*			if(check == 0)
			{*/
			if (incoming.length() == informat.length())
			{
				for (int i = 0; i < incoming.length(); i++)
				{
					x = incoming.charAt(i);
					y = informat.charAt(i);
					if (incoming.charAt(i) == '\\' && informat.charAt(i) == '\\')
					{
						incomingSlash = incomingSlash + 1;
					}
					else if (incoming.charAt(i) == '-' && informat.charAt(i) == '-')
					{
						incomingDash = incomingDash + 1;
					}
					else if (incoming.charAt(i) == '.' && informat.charAt(i) == '.')
					{
						incomingDot = incomingDot + 1;
					}
				}
				if (incomingDash == 1 || incomingSlash == 1 || incomingDot == 1)
				{
					//convertedDate = "HELLO!";
					return "Error"; //return empty string
				}
				else if (incomingDash == 2 || incomingSlash == 2 || incomingDot == 2)
				{
					if (informat.contains("MON"))
					{
						month = incoming.substring(informat.indexOf("MON"), informat.indexOf("MON") + 3);
						for (int i = 0; i < monthArr.length; i++)
						{
							System.out.println("THIS IS FOR LOOP");
							if (monthArr[i].equals(month))
							{
								monthNum = i + 1;
								//outformat = outformat.replace("MM", Integer.toString(monthNum));
								System.out.println("THIS IS MONTHNUM: " + monthNum);
							}
						}
					}
					else 
					{
						System.out.println("NO FOR LOOP BUT INSTEAD IN ELSE \n");
						
						
						month = incoming.substring(informat.indexOf("MM"), informat.indexOf("MM") + 2);
						System.out.println("THIS IS MONTH: " + month);
						System.out.println("THIS IS MONTH: " + Integer.parseInt(month));
						System.out.println("THIS IS MONTH: " + monthNum);
						if (monthNum == Integer.parseInt(month))
						{
							month = monthArr[monthNum - 1];
							System.out.println("THIS IS MONTH: " + month);
						}
						
					}
					day = incoming.substring(informat.indexOf("DD"), informat.indexOf("DD") + 2);
					year = incoming.substring(informat.indexOf("YYYY"), informat.indexOf("YYYY") + 4);
					outformat = outformat.replace("YYYY", year);
					outformat = outformat.replace("DD", day);
					if (outformat.contains("MM"))
					{
						//outformat = outformat.replace("MM", Integer.toString(monthNum));
						outformat = outformat.replace("MM", Integer.toString(monthNum));
					}
					
					//System.out.println("MEETING 2" + day + year + month);
					System.out.println("OUTFORMAT:" + outformat);
					check = check + 1;
				}
				else if (incomingDash == 0 || incomingSlash == 0 || incomingDot == 0)
				{
					if (informat.contains("MON"))
					{
						month = incoming.substring(informat.indexOf("MON"), informat.indexOf("MON") + 3);
					}
					else 
					{
						month = incoming.substring(informat.indexOf("MM"), informat.indexOf("MM") + 2);
					}
					day = incoming.substring(informat.indexOf("DD"), informat.indexOf("DD") + 2);
					year = incoming.substring(informat.indexOf("YYYY"), informat.indexOf("YYYY") + 4);
					System.out.println("Hello in ELSE" + day + year);
					check = check + 1;
				}
			}
			else
			{
				//return empty string
				check = check + 1;
				System.out.println("OHAYO" + day + year);
			}
			//}
		} // while		

		return convertedDate;
	}

} // end of class
