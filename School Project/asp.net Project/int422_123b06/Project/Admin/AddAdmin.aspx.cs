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
    public partial class AddAdmin : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                Manager.addAdminAccount(tbUserName.Text, tbPassword.Text,
                                        tbEmail.Text, ddlQuestion.SelectedValue,
                                        tbAnswer.Text);
                lblMessage.Text = "Account successfully created!";
                lblMessage.ForeColor = System.Drawing.Color.Green;
                
            }
            catch (Exception ex)
            {
                if (ex is NameCanNotBeNull)
                {
                    lblMessage.Text = ex.Message;
                    lblMessage.ForeColor = System.Drawing.Color.Red;
                }
                else if (ex is PwdCanNotBeNull)
                {
                    lblMessage.Text = ex.Message;
                    lblMessage.ForeColor = System.Drawing.Color.Red;
                }
                else if (ex is EmailCanNotBeNull)
                {
                    lblMessage.Text = ex.Message;
                    lblMessage.ForeColor = System.Drawing.Color.Red;
                }
                else if (ex is SecurityQuestionCanNotBeNull)
                {
                    lblMessage.Text = ex.Message;
                    lblMessage.ForeColor = System.Drawing.Color.Red;
                }
                else if (ex is AnswerCanNotBeNull)
                {
                    lblMessage.Text = ex.Message;
                    lblMessage.ForeColor = System.Drawing.Color.Red;
                }
            }
        }
    }
}
