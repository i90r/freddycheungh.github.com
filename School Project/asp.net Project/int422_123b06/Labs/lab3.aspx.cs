using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using System.Text;
using int422_123b06.Classes;

namespace int422_123b06.Labs
{
    public partial class lab3 : System.Web.UI.Page
    {
        string container = string.Empty;
        string pn = string.Empty;
        string fileSource = string.Empty;
        string fileTarget = string.Empty;
        string fileData = string.Empty;
        string fname = string.Empty;
        string userName="Freddy Cheungh";

        Lab3FileManager fileMgr;

        public Lab3FileManager fileManager
        {
            get
            {
                if (Session["fileManager"] == null)
                {
                    return new Lab3FileManager();
                }
                else return (Lab3FileManager)Session["fileManager"];
            }
            set
            {
                Session["fileManager"] = value;
            }
        }
       
        protected void Page_Load(object sender, EventArgs e)
        {

            if (!IsPostBack)
            {
                Session.Remove("fileManager");
              //btnCopy.Enabled = false;
            }

            fname = fileUploader.FileName;
            pn = Server.MapPath("/uploads");
            fileSource = Path.Combine(pn, fname);

            // Clear the messages
            lblResult.Text = string.Empty;
            lblCopyError.Text = string.Empty;

        } //Page_Load

        protected void btnUpload_Click(object sender, EventArgs e)
        {
            fileMgr = new Lab3FileManager();
            string fileExtension = System.IO.Path.GetExtension(fileUploader.FileName);
            try
            {
                if (fileExtension == ".txt")
                {
                    fileMgr.UploadFile(ref fileUploader);
                    lblResult.Text = "File has been uploaded successfully.";
                    lblResult.ForeColor = System.Drawing.Color.Green;
                }
                else
                {
                    lblResult.Text = "File is not a text file";
                    lblResult.ForeColor = System.Drawing.Color.Red;
                }
            }
            catch (Exception ex)
            {
                lblResult.Text = ex.Message;
                lblResult.ForeColor = System.Drawing.Color.Red;
            }
     
            // needs to fix

            container=Path.GetFileName(fileSource);

            ddlUpload.Items.Add(container);

            //btnCopy.Enabled = true;
           

        }// btnUpload_Click

        protected void btnCopy_Click(object sender, EventArgs e)
        {
            lblCopyError.Text = string.Empty;
            fileMgr = new Lab3FileManager();

            try
            {
                fileMgr.CopyFile(fileManager.name, userName);
                lblCopyError.Text = "The file copy was successful";
                lblCopyError.ForeColor = System.Drawing.Color.Green;
            }
            catch (Exception ex)
            {
                
                lblCopyError.Text = ex.Message;
                lblCopyError.ForeColor = System.Drawing.Color.Red;
            }

            container = Path.GetFileName(fileSource);

            ddlUpload.Items.Add(container);

        }//btnCopy_Click

        protected void ddlUpload_SelectedIndexChanged(object sender, EventArgs e)
        {
            
            tbText.Text = string.Empty;
            fileMgr = new Lab3FileManager();
        try
        {
            tbText.Text = fileMgr.GetFileContents(ddlUpload.SelectedValue);
        }
        catch (Exception ex)
        {
            tbText.Text = ex.Message;
            tbText.ForeColor = System.Drawing.Color.Red;
        }

        } // ddlUpload_SelectedIndexChanged

        protected void btnSearch_Click(object sender, EventArgs e)
        {
            fileMgr = new Lab3FileManager(); 
            fileMgr.SearchFileContents(ddlUpload.SelectedValue, tbSearch.Text);
        } //protected void btnSearch_click
    }//public partial class lab3 : System.Web.UI.Page
}//namespace int422_123b06.Labs
