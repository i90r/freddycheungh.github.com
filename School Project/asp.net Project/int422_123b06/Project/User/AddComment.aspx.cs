using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Project.Entities;
using int422_123b06.Classes;
using System.Web.Security;

namespace int422_123b06.Project.User
{
    public partial class AddComment : System.Web.UI.Page
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
                btnNewComment.Visible = false;
                lblError.Text = string.Empty;
                tbStudentId.Text = student;
                //Bind all the element from the comments table
                using (var context = new projectEntities())
                {
                    ddlStudent.DataSource = context.students;
                    ddlStudent.DataTextField = "student_id";
                    ddlStudent.DataValueField = "student_id";
                    ddlStudent.DataBind();
                    ddlStudent.Items.Insert(0, new ListItem("-Select Student-", "0"));
                    ddlStudent.SelectedIndex = 0;
                }
                Session.Remove("manager");
            }
        }

        protected void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                //gets the data of the current user logged in
                string strName = HttpContext.Current.User.Identity.Name.ToString();
                if (ddlStudent.SelectedValue == "0")
                {
                    //calls a method to check the student id 
                    string id = Manager.studentIdCheck(tbStudentId.Text);
                    //calls the method that will store the data into the database
                    Manager.addNewStudentComment(strName, id, tbStudentName.Text, tbComment.Text);
                    lblError.Text = "Comment added successfully!";
                    lblError.ForeColor = System.Drawing.Color.Green;

                }
                else
                {
                    //Calls the method that will store the data into the database. This one is called
                    //if the user selects a student from the dropdownlist
                    Manager.addComment(strName, ddlStudent.SelectedValue, tbStudentName.Text, tbComment.Text);
                    lblError.Text = "Comment added successfully!";
                    lblError.ForeColor = System.Drawing.Color.Green;
                }
                btnNewComment.Visible = true;
            }
            catch (Exception ex)
            {
                lblError.Text = ex.InnerException.ToString();
                //Manager.GetInnerException(ex);
                //lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
            }
        }

        protected void ddlStudent_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (ddlStudent.SelectedValue != "0")
            {
                tbStudentId.Enabled = false;
                tbStudentName.Enabled = false;
                tbStudentId.Text = ddlStudent.SelectedValue;
            }
            else
            {
                tbStudentId.Enabled = true;
                tbStudentName.Enabled = true;
            }
        }

        protected void btnNewComment_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Project/User/AddComment.aspx");
        }
    }
}