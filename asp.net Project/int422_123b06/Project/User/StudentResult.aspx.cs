using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Classes;

namespace int422_123b06.Project.User
{
    public partial class StudentResult : System.Web.UI.Page
    {
        public Manager manager
        {
            get
            {
                if (Session["manager"] == null)
                {
                    return new Manager();
                }
                else return (Manager)Session["manager"];
            }
            set
            {
                Session["manager"] = value;
            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            string student = manager.StudentID;
            if (!IsPostBack)
            {
                try
                {
                    Manager.StudentResult(tableResult, student);
                }
                catch (Exception ex)
                {
                    lblError.Text = ex.Message;
                    lblError.ForeColor = System.Drawing.Color.Red;
                }
            }
        }

        protected void btnAuthor_Click(object sender, EventArgs e)
        {
            try
            {
                string student = manager.StudentID;
                Manager.displayAuthor(tableResult, student);
            }
            catch (Exception ex)
            {
                lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
            }
        }

        protected void btnDate_Click(object sender, EventArgs e)
        {
            try
            {
                string student = manager.StudentID;
                Manager.displayDate(tableResult, student);
            }
            catch (Exception ex)
            {
                lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
            }
        }
    }
}