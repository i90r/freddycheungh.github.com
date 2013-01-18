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
    public partial class ChangePassword : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnChange_Click(object sender, EventArgs e)
        {
            try
            {
                //Will create an instance of MembershipUser which will hold all the information from
                //the current user
                MembershipUser curUser = Membership.GetUser(User.Identity.Name);
                //calls the method in the manager class which will change the password
                Manager.changePwd(tbCurPwd.Text, tbNewPwd.Text, curUser);
                lblError.Text = "Password successfully changed!";
                lblError.ForeColor = System.Drawing.Color.Green;
            }
            catch (Exception ex)
            {
                if (ex is UnableToChangePassword)
                {
                    lblError.Text = ex.Message;
                    lblError.ForeColor = System.Drawing.Color.Red;
                }
            }
            //Empty the textboxes
            tbCurPwd.Text = string.Empty;
            tbNewPwd.Text = string.Empty;
            tbConfirmedPwd.Text = string.Empty;
        }
    }
}