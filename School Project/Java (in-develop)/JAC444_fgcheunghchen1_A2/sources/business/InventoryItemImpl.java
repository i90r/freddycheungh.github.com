// Address.java

package business;

import java.io.*;
import java.util.*;
import useful.*;

/**
* Represents a real Address object
  <p>Used as a learning tool, just a few variables.</p>
 @author B. Perry
 @author --add your name here ---
 @version 1 - 2007-05-22
*/
public class InventoryItemImpl
{
   //----static data
  private static String[] prompts =
  {
    "number    : ",
    "street    : ",
    "suite     : ", 
    "city      : ",
    "province  : ",
    "postcode  : ",
    "country   : "
  }
      
	 //----instance data
   
   /** explanation number */
   private String number;
   /** explanation street */
   private String street;
   /** explanation suite */
   private String suite;
   /** explanation city */
   private String city;
   /** explanation province */
   private String province;
   /** explanation postcode */
   private String postcode;
   /** explanation country */
   private String country;

   //---constructors
   
   /**
   * No param constuctor.  Should initalize all references to avoid
   * NullPointerException later.  Allows primitive variables to
   * get default values.  Expects most instance variables
   * to be populated by an update() method.
   */
   public InventoryItemImpl()
   {
     number="";
     street="";
     suite="";
     city="";
     province="";
     postcode="";
     country="";
     // any primitives get default initialization
   }
   
   //---methods (in sequence by method name)
   
   //-----------------------------------------------------------------formatDisplay()
   /**
   In Order to test a class properly it is essential to be able to
   display the status of objects (ALL the data within the object).
    <p>Formats the contents of the object into a String so that when
       displayed (by the application) it will make a "pretty" display.</p>
   */
   public int formatDisplay(StringBuffer temp)
   {
     int retval = 0;
     temp.append("\n" + "+++++++++Address+++++++++");     
     temp.append("\n" + "number   : " + number);
     temp.append("\n" + "street   : " + street);
     temp.append("\n" + "suite    : " + suite);
     temp.append("\n" + "city     : " + city);
     temp.append("\n" + "province : " + province);
     temp.append("\n" + "postcode : " + postcode);
     temp.append("\n" + "country  : " + country);
     temp.append("\n" + "+++++end Address+++++++++");     
	   return retval;
   }

   //---------------------------------------------------------------------getData()
   /**
     * <p>This is the ORIGINAL version of getData(...) in the getData(...)
     * method of all Business Classes. </p>
     * <p>Reads the prompts array in a loop.
     * Gets data from the BufferedReader (param #3)and appends it to a 
     * StringBuffer (param #2).  The appended data is in CSV format:
     * <pre>
     * ~Field1~Field2~ ... Fieldn~
     * </pre>
     * where '~' is a marker for the separator (param#4)
     * 
     * </p>
    */
    public static int getData(StringBuffer sb, BufferedReader br, String sep) throws IOException
    {
      String   buf = ""; // to read into
      int      err = 0;  // used for return value
      int      k = 0;    // loop control

      sb.append(sep);  // start StringBuffer with separator char

      for (k = 0; k < prompts.length; k++)
      {
        System.err.print(prompts[k]);  // output prompt - leave cursor on same line
        System.err.flush();            // ensure that the data appears
        buf = br.readLine();           // read the input/response
        if (buf == null)
        {
           // at end of file
           err = -1;
           break;
        }
        //--- data entered may not contain a separator character
        if (  buf.indexOf(sep) >= 0  )
        {
          err = -2;                     // set return code
          break;                       // finish - break out of loop
        }
        //--- deal with empty input field 
        if ( buf.equals("") )
        {
          buf = "\t";                   // tab to indicate empty field
        }
        //--- data item is OK so add it to StringBuffer
        sb.append(buf + sep);          // append separator
      } // end for()

      return err;                      // return result/status code
    } // endof getData()
  

  //----------------------------------------------------------------------update()
  /**
   * update() -  inserts data from the StringBuffer, (param #1) into an empty 
   * object.  The format of the StringBuffer is that provided by getData(...)
   * in CSV format ... separator is first character of StringBuffer
   */
  public int update(StringBuffer sb)
  {
    int             err = 0;  // used to indicate status (0 = normal)
    String          sep;      // separator value used by CSV format data
    StringTokenizer tk;       // to extract data
    String          temp;    // for extracted data

    //--- get separator (value is first character of StringBuffer)
    sep = String.valueOf(sb.charAt(0));
    //--- create tokenizer (to extract data items)
    tk = new StringTokenizer(sb.toString(), sep);

    //--- now get tokens and update instance variables
    //    only make change if data is not equal to a single tab 

    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      number = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      street = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      suite = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      city = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      province = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      postcode = new String(temp);           
    }                                        
                                             
    temp = tk.nextToken();                   
    if (! temp.equals("\t"))                 
    {                                        
      // is String - no conversion needed    
      country = new String(temp);           
    }                                        
                                             
    return err; // indicate OK (i.e. no error)
  } // end of update

} // end class
