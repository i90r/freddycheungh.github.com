package useful;

import java.io.*;

/**
 * Interface that will establish the basic prototypes for methods 
 * used as a DataReader. 
 * 
 * <p>This interface will be used by DataReaderImpl_1.java.
 * DataReaderImpl_1 will simply take these methods and implements
 * the code in order to be used how it is required to.</p>
 * 
 *  @version 1.0
 *  @author Freddy Cheungh
 */
public interface DataReader
{
	public String readLine();
	public String resetMarker(String mkr);
	public void close();
}