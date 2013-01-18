using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Text;

namespace int422_123b06.Classes
{
    public class Lab3FileManager
    {
    // Reference to the current application instance
    System.Web.HttpApplication _context;

    // Upload folder for this app
    string _uploadFolder;
    public string name;

    /// <summary>
    /// Create a new instance of the file manager
    /// </summary>
    public Lab3FileManager()
    {
        // Get a reference to the current application instance
        _context = System.Web.HttpContext.Current.ApplicationInstance;
        // Get the uploads folder's file system path
        _uploadFolder = _context.Server.MapPath("~/uploads/");
    }

    /// <summary>
    /// A string array of file names in the "uploads" folder
    /// </summary>
    public List<string> FileList
    {
        get 
        {
            Directory.GetFiles(_uploadFolder).ToList(); 
            return null; 
        }
    }

    /// <summary>
    /// Upload to the file system
    /// </summary>
    /// <param name="fu">Reference to the file upload web server control</param>
    /// Throws exception if operation was not successful
    public void UploadFile(ref System.Web.UI.WebControls.FileUpload fu)
    {
        // Get the file name of the file to be uploaded
        string fn = fu.FileName;

        // Concat
        string uploadedFile = _uploadFolder + fn;

        // Perform the upload task
        try
        {
                if (fu.FileBytes.Length < 1000)
                {
                    throw new fileTooSmall();
                }
                if (fu.FileBytes.Length > 10000)
                {
                    throw new fileTooBig();
                }
                fu.SaveAs(uploadedFile);
                // Store the file name in session state
                _context.Session["uploadedFile"] = uploadedFile;
            }
        catch (Exception ex)
        {
            throw ex;
        }

    } // UploadFile

    /// <summary>
    /// Make a copy of a file in the uploads folder
    /// </summary>
    /// <param name="fileName">Name of the file to be copied</param>
    /// <param name="userName">User name, which will be added to the file copy</param>
    /// Throws exception if operation was not successful
    public void CopyFile(string fileName, string userName)
    {
        string newLine = Environment.NewLine; // New line constant
        string newFileName = string.Empty;
        string copiedfile=string.Empty;
        newFileName = _uploadFolder + fileName;
        newFileName = newFileName.Replace(".txt", "");
        copiedfile = newFileName + "copy.txt";
        try
        {
            File.Copy(_uploadFolder + fileName, copiedfile, true);
       
        }
        catch (Exception ex)
        {
            throw ex;
        }

        StringBuilder sb = new StringBuilder();

        // Date and time stamp
        sb.Append(userName + newLine);
        sb.Append("Today's date is:     " + DateTime.Now.ToLongDateString() + newLine);
        sb.Append("The current time is: " + DateTime.Now.ToLongTimeString() + newLine + newLine);

        string sourcePath = copiedfile;

        // Working fields
        StreamWriter sw = null;
        string sourceText = string.Empty;

        // Go ahead and do it
        try
        {
            sourceText = File.ReadAllText(sourcePath);
            sw = File.CreateText(sourcePath);
            // Dump the stringbuilder first
            sw.Write(sb.ToString());
            // Append the example1.txt file
            sw.Write(sourceText);

        }
        catch (Exception ex)
        {
            throw ex;
        }
        finally
        {
            sw.Close();
        } // try-catch-finally

    }

    /// <summary>
    /// Gets the text contents of a file in the uploads folder
    /// </summary>
    /// <param name="fileName">Name of the desired file</param>
    /// <returns>String value of the file's contents</returns>
    ///Throws exception if operation was not successful
    public string GetFileContents(string fileName)
    {

        try
        {
            // Setup a StreamReader to the text file 
            StreamReader sr = File.OpenText(_uploadFolder + fileName);
            // Setup a StringBuilder that accumulates the file data
            StringBuilder sb = new StringBuilder();

            // Loop through the file...
            while (sr.EndOfStream == false)
            {
                sb.Append(sr.ReadLine() + Environment.NewLine);
            }
            // Close the StreamReader
            sr.Close();
            // sb now contains all of the file data; put it into the textbox
            //tbResults.Text = sb.ToString();
            return sb.ToString();

        }
        catch (Exception ex)
        {
            throw ex;
        }
    } //GetFileContents

    /// <summary>
    /// Search within a file in the uploads folder
    /// </summary>
    /// <param name="fileName">Name of the file to be searched</param>
    /// <param name="s">Search text</param>
    /// <returns>String of results, formatted for a text box web server control</returns>
    ///Throws exception if operation was not successful
    public string SearchFileContents(string fileName, string searchText)
    {
        try
        {
            if(fileName.Contains(searchText))
            {
                
            }
            return "";
        }
        catch (Exception ex)
        {
            
            throw ex;
        }
    }// SearchFileContents
}
public class fileTooSmall : ApplicationException
    {
        public fileTooSmall(string msg = "File must be larger than 1.000 bytes")
            : base(msg)
        {
        }
    }

public class fileTooBig : ApplicationException
{
    public fileTooBig(string msg = "File must be smaller than 10.000 bytes")
        : base(msg)
    {
    }
}
}//end of namespace
