using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;
using int422_123b06.Project.Entities;
using int422_123b06.Classes;

namespace int422_123b06.Project.Admin
{
    public partial class DeleteAccount : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblError.Text = string.Empty;
                //Bind all the content in the table aspnet_Users
                Manager.loadDeleteUser(ddlDelete);
            }
        }

        protected void ddlDelete_SelectedIndexChanged(object sender, EventArgs e)
        {
            lblError.Text = string.Empty;
        }

        protected void btnDelete_Click(object sender, EventArgs e)
        { 
            bool toBeDeleted = false;
            if (cbDelete.Checked)
            {
                toBeDeleted = true;
            }
            try
            {
                //Calls the method to delete an account
                Manager.deleteAccount(ddlDelete.SelectedItem.Text, toBeDeleted);
                //If successfull, an message will be displayed indicating it was successfull
                lblError.Text = "Account successully deleted!";
                lblError.ForeColor = System.Drawing.Color.Green;
                //Updates the dropdownlist elements
                Manager.loadDeleteUser(ddlDelete);
            }
            catch (Exception ex)
            {
                lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
            }  
        }

        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Project/Admin/DeleteAccount.aspx");
        }
    }
}