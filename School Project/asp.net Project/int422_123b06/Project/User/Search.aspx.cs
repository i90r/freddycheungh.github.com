using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Project.Entities;
using int422_123b06.Classes;

namespace int422_123b06.Project.User
{
    public partial class Search : System.Web.UI.Page
    {
        //sets the session
        //sessions is being used to pass the result of the search to the result page
        //in which it will display all the comments that the student has.
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
            if (!IsPostBack)
            {
                lblError.Text = string.Empty;
                btnYes.Visible = false;
                btnNo.Visible = false;
                //binds all the data from the comments table into the dropdownlist
                Manager.loadSearchUser(ddlStudent);
                Session.Remove("manager");
            }
        }

        protected void btnSearch_Click(object sender, EventArgs e)
        {
            //string check = tbSearch.Text;
            try
            {
                if (ddlStudent.SelectedValue == "0")
                {
                    //calls a method to check if the student id entered is correct
                    Manager.studentIdCheck(tbSearch.Text);
                    //calls the method that will search for the student entered
                    Manager.searchStudent(tbSearch.Text);
                    //stores the data in the textbox in case there is a match
                    //if so, this will be used on the result page
                    manager = new Manager(tbSearch.Text);
                    Response.Redirect("~/Project/User/StudentResult.aspx");
                }
                else
                {
                    //this methods does the same as the method above, but this is called
                    //when the user selects a student from the dropdownlist
                    Manager.searchStudent(ddlStudent.SelectedValue);
                    manager = new Manager(ddlStudent.SelectedValue);
                    Response.Redirect("~/Project/User/StudentResult.aspx");
                }
            }
            catch (Exception ex)
            {
                lblError.Text = ex.Message;
                lblError.ForeColor = System.Drawing.Color.Red;
                lblQuestion.Text = "Would you like to add a new student and a comment now?";
                btnYes.Visible = true;
                btnNo.Visible = true;
            }
        }

        //Yes button will simply redirect the user to the add comment page if they wish to add a comment to a new student
        protected void btnYes_Click(object sender, EventArgs e)
        {
            manager = new Manager(tbSearch.Text);
            Response.Redirect("~/Project/User/AddComment.aspx");
        }
        //No button will just refresh the page
        protected void btnNo_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Project/User/Search.aspx");
        }
    }
}