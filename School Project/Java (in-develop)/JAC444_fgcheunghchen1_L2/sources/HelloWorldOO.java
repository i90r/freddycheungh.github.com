// HelloWorldOO.java - application class

import java.io.*;

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
*  @author Brian Perry
*/
public class HelloWorldOO
{
  //============================================static data
  // none

  //============================================instance data
  /** In which to store args from command line  */
  private String[] names;   // to store command-line args  as instance var(s)
  
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
  * a loop which reads input file(s).  But, in this example,
  * the task is trivial.
  */
  private void run()
  {
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
    System.out.println("+++program ending+++");
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
  public static void main(String[] args)
    throws IOException
  {
    HelloWorldOO theApp = new HelloWorldOO(); // make object of own class

    theApp.init(args);                        // then call its methods
    theApp.run();
    theApp.wrap();
  } // end of main()

} // end of class
