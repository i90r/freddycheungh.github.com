using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;
using int422_123b06.Classes;

namespace int422_123b06.Project.Admin
{
    public partial class AddUser : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                Manager.addUserAccount(tbFirstName.Text, tbLastName.Text, tbUUserName.Text,
                                       tbUPassword.Text, tbUEmail.Text, ddlQuestion.SelectedValue,
                                       tbUAnswer.Text);
                lblMessage.Text = "Account successfully created!";
                lblMessage.ForeColor = System.Drawing.Color.Green;
            }
            catch (Exception ex)
            {
                lblMessage.Text = ex.Message;
                lblMessage.ForeColor = System.Drawing.Color.Red;
            }

        }
    }
}
