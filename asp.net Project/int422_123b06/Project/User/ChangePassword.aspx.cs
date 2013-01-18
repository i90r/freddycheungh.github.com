using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;
using int422_123b06.Classes;

namespace int422_123b06.Project.User
{
    public partial class ChangePassword : System.Web.UI.Page
    {
        

        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void btnChange_Click(object sender, EventArgs e)
        {
            try
            {
                //get the current logged in user information
                MembershipUser curUser = Membership.GetUser(User.Identity.Name);
                //calls the method in the manager class to change the password
                Manager.changePwd(tbCurPwd.Text, tbNewPwd.Text, curUser);
                lblError.Text = "Password successfully changed!";
                lblError.ForeColor = System.Drawing.Color.Green;
            }
            catch (Exception ex)
            {
                lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
            }
            tbCurPwd.Text = string.Empty;
            tbNewPwd.Text = string.Empty;
            tbConfirmedPwd.Text = string.Empty;
        }
    }
}