using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Classes;

namespace int422_123b06.Labs
{
    public partial class Lab2 : System.Web.UI.Page
    {
        SenecaStudent students;
       
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                pnlEnter.Visible = true;
                pnlInfo.Visible = false;
                pnlEmail.Visible = false;
                rblSemester.Enabled = false;
                btnSubmit.Enabled = false;
            } //if (!IsPostBack)
        }
        protected void ddlProgram_SelectedIndexChanged(object sender, EventArgs e)
        {
            int semEnrolled = 0 ;
            rblSemester.Items.Clear();
            btnSubmit.Enabled = false;
            if (ddlProgram.SelectedValue != "-1")
            {
                rblSemester.Enabled = true;
               
                if (ddlProgram.SelectedValue == "0")
                {
                    semEnrolled = 6;
                }
                if (ddlProgram.SelectedValue == "1")
                {
                    semEnrolled = 4;
                }
                if (ddlProgram.SelectedValue == "2")
                {
                    semEnrolled = 2;
                }
                if (ddlProgram.SelectedValue == "3")
                {
                    semEnrolled = 4;
                }
                if (ddlProgram.SelectedValue == "4")
                {
                    semEnrolled = 6;
                }
                if (ddlProgram.SelectedValue == "5")
                {
                    semEnrolled = 8;
                }
                for (int x = 1; x <= semEnrolled; x++)
                {
                    rblSemester.Items.Add("Semester " + x);
                }
            } //if (ddlProgram.SelectedValue != "-1")
        }
        protected void rblSemester_SelectedIndexChanged(object sender, EventArgs e)
        {
            lblLnameError.Text = string.Empty;
            lblFnameError.Text = string.Empty;
            lblEmailError.Text = string.Empty;
            if (rblSemester.SelectedValue != null)
            {
                Session["student"] = new SenecaStudent(tbFirstName.Text, tbLastName.Text, tbEmailID.Text, tbSenecaID.Text, ddlProgram.SelectedItem.Text, rblSemester.SelectedItem.Text);
                students = (SenecaStudent)Session["student"];
            } //if (rblSemester.SelectedValue != null)
            lblFirstName.Text = students.getFirstName();
            lblLastName.Text = students.getLastName();
            lblSenecaID.Text = students.getSenecaID();
            lblEmailID.Text = students.getEmail();
            lblProgram.Text = students.getProgram();
            lblSemester.Text = students.getSemester();
            try
            { //check if first name contains number
                string num = tbFirstName.Text;
                char a;
                for (int j = 0; j < num.Length; j++)
                {
                    for (int i = 0; char.IsNumber(num[j]); i++)
                    {
                        a = num[i];
                    }
                }
            }
            catch (Exception)
            {
                lblFnameError.Text = "First name must not contain any number";
                lblFirstName.Focus();
            } //try && catch

            try
            { //check if last name contains number

                string num = tbLastName.Text;
                char a;
                for (int j = 0; j < num.Length; j++)
                {
                    for (int i = 0; char.IsNumber(num[j]); i++)
                    {
                        a = num[i];
                    }
                }
            }
            catch (Exception)
            {
                lblLnameError.Text = "Last name must not contain any number";
                lblLastName.Focus();
            } //try && catch

            if (tbEmailID.Text.Contains("@"))
            {
                lblEmailError.Text = "Email ID is the part of the college email address before the (@) sign";
            }

            if (lblFnameError.Text == "" && lblLnameError.Text == "" && lblEmailError.Text == "")
            {
                btnSubmit.Enabled = true;   //enables the submit button
            } //if (lblFnameError.Text == "" && lblLnameError.Text == "" && lblEmailError.Text == "")
        }
        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            pnlEnter.Visible = false;
            pnlInfo.Visible = true;
        }
        protected void btnEmail_Click(object sender, EventArgs e)
        {
            pnlInfo.Visible = false;
            pnlEmail.Visible = true;
        }

        protected void btnStartOver_Click(object sender, EventArgs e)
        {
            pnlEnter.Visible = true;
            pnlInfo.Visible = false;
            pnlEmail.Visible = false;
            rblSemester.Enabled = false;
            btnSubmit.Enabled = false;
            rblSemester.Items.Clear();
            ddlProgram.SelectedValue = "-1";
            tbFirstName.Text = string.Empty;
            tbLastName.Text = string.Empty;
            tbEmailID.Text = string.Empty;
            tbSenecaID.Text=string.Empty;
        }
    }
}