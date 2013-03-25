package useful;

import java.io.*;

/**
 * Applications which implements the interface DataReader
 * <p>This application will take the methods of the interface
 * and implement some use to it. The methods will work together
 * and take a data file (composed by data and comments). The main
 * function of this application is to read line by line and display
 * every line of data. When a comment is present, it will skip to 
 * a next line, and verify if it's a data line or a comment line.
 * If it's a comment line it will skip lines until a data line is
 * encountered, otherwise it will be ignored and not printed.</p>
 *
 *  @version 1.0
 *  @author Freddy Cheungh
 */
public class DataReaderImpl_1 implements DataReader
{
	//============================================static data
	// none

	//============================================instance data
	/** holds the comment marker text */
	private String marker;   
	/** is the stream based on standard input */
	private BufferedReader theReader;

	//============================================constructors
	/** This is the only constructor.  Create a BufferedReader based on 
	 * standard-input and set the reference, theReader to point to it.  
	 * Set the comment marker to “#”, the default value (which is the
	 *  Unix/Linux command-line standard for comments). */
	public DataReaderImpl_1()
	{
		marker = "#";	//sets the default value to the marker
		theReader = new BufferedReader(new InputStreamReader(System.in));
	}

	//============================================methods
	/**Each call to this method either returns the next data item or signals end-of-file.
	 * It bypasses comments in the test data stream.*/
	public String readLine()
	{
		String temp = null;	//stores the lines of input
		try
		{
			temp = theReader.readLine();	//reads the std input line by line
			if(temp == null)	//if it's null then return temp (this clears the null pointer exception)
			{
				return temp;
			}
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		if (marker != null)	//as long as the marker is not null (which means there is a comment marker)
							//it will go in, and process all the comments. If it's null, then it will print
							//everything
		{
			// if the marker is longer than the data line, it will not go in.
			if (temp.length() >= marker.length())
			{
				//simply verifies that is not the EOF, or if the marker is null, and as long it's not
				//an empty line. If all these conditions are met, it will go in this if statement and
				//will go to the next step.
				if (temp != null && !temp.isEmpty() && !temp.equals(marker))
				{
					//if there is a whole comment, this if statement will happen.
					if (temp.substring(0, marker.length()).equals(marker))
					{
						// if the value of the line is not equal to the value of the marker (eg: # = #)
						if (!temp.equals(marker))
						{
							while (temp.substring(0, marker.length()).equals(marker))
							{
								try
								{
									temp = theReader.readLine();
									if(temp == null)
									{
										return temp;
									}
								}
								catch (IOException e)
								{
									e.printStackTrace();
								}
							}
						}
						else
						{
							// will loop through all the whole line comments. Will stop when data is found.
							while (temp.substring(0, marker.length()).equals(marker))
							{
								try
								{
									temp = theReader.readLine();
									if (temp == null)	// if it's null, simply return temp (null value)
									{
										return temp;
									}
								}
								catch (IOException e)
								{
									e.printStackTrace();
								}
							}
						}
					}
					// it will happen if there is a comment marker on the line but not at the beggining of the line.
					// This means it will only happen with non full line comments.
					if (temp.contains(marker) && !temp.substring(0, marker.length()).equals(marker))
					{
						int index = temp.indexOf(marker);
						temp = temp.substring(0, index);
					}
				}
			} // if(temp.length() >= marker.length() && marker != null)
		} // if(marker != null)
		return temp;
	}
	/**
	 * Reset the marker using the parameter data. The marker provides 
	 * the information necessary to detect a comment.  Returns the
	 * old (previous) value of the marker text.
	 * */
	public String resetMarker(String mkr)
	{
		String prv_marker = marker;	//stores the previous marker value
		marker = mkr;	//resets the marker to the new value
		return prv_marker;
	}
	/**
	 * Call the close() method of the BufferdReader, theReader.
	 */
	public void close()
	{
		try
		{
			theReader.close();	//closes the bufferedReader connection
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
} //end class
