using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace int422_123b06.Labs
{
    public partial class lab1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void SubmitId_Click(object sender, EventArgs e)
        {
            lblDdRoutesError.Text = string.Empty;
            lbNumberNeeded.Text = string.Empty;
            lblInvoice.Text = string.Empty;

            if (ddlRoutes.SelectedValue == "-1")
            {
                lblDdRoutesError.Text = "You must select a route.";
                tbTickets.Text = string.Empty;
                ddlRoutes.Focus();

            }//if(ddlRoutes.SelectedVAlue == "-1")

            else
            {
                int numTickets = 0;
                double Tcost = 0;
                int Tnum = 0;

                try
                {
                    numTickets = Convert.ToInt32(tbTickets.Text);
                }//try
                catch (Exception)
                {
                    lbNumberNeeded.Text = "You must enter a numeric value.";
                    tbTickets.Text = string.Empty;
                    tbTickets.Focus();
                    return;
                }//catch

                int err = 0; //Error Count

                switch (ddlRoutes.SelectedItem.Text)
                {
                    case ("Barrie"):
                        Tcost = Convert.ToDouble(lbBarrieCost.Text);
                        Tnum = Convert.ToInt32(lblBarrieTickets.Text);

                        if (numTickets <= 0 || numTickets > Convert.ToInt32(Tnum))
                        {
                            lbNumberNeeded.Text = "Number of tickets must be greater than 0 and less than or equal to the number of tickets available.";
                            err = 1;
                        }//if
                        if (err == 0)
                        {
                            lblBarrieTickets.Text = Convert.ToString(Tnum - numTickets);
                            lblInvoice.Text = "You have purchased " + tbTickets.Text + " Ticket(s) for " + ddlRoutes.Text + " and your total is $" + Convert.ToString(Tcost * numTickets);
                        }
                        if (Tnum == 0)
                        {
                            lbNumberNeeded.Text = "No tickets available to Barrie";
                        }
                        break; //Barrie
                    case ("London"):
                        Tcost = Convert.ToDouble(lbLondonCost.Text);
                        Tnum = Convert.ToInt32(lblLondonTickets.Text);
                        if (numTickets <= 0 || numTickets > Convert.ToInt32(Tnum))
                        {
                            lbNumberNeeded.Text = "Number of tickets must be greater than 0 and less than or equal to the number of tickets available";
                            err = 1;
                        }//if
                        if (err == 0)
                        {
                            lblLondonTickets.Text = Convert.ToString(Tnum - numTickets);
                            lblInvoice.Text = "You have purchased " + tbTickets.Text + " Ticket(s) for " + ddlRoutes.Text + " and your total is $" + Convert.ToString(Tcost * numTickets);
                        }
                        if (Tnum == 0)
                        {
                            lbNumberNeeded.Text = "No tickets available to London";
                        }
                        break; //London
                    case ("Montreal"):
                        Tcost = Convert.ToDouble(lbMontrealCost.Text);
                        Tnum = Convert.ToInt32(lblMontrealTickets.Text);
                        if (numTickets <= 0 || numTickets > Convert.ToInt32(Tnum))
                        {
                            lbNumberNeeded.Text = "Number of tickets must be greater than 0 and less than or equal to the number of tickets available";
                            err = 1;
                        }//if
                        if (err == 0)
                        {
                            lblMontrealTickets.Text = Convert.ToString(Tnum - numTickets);
                            lblInvoice.Text = "You have purchased " + tbTickets.Text + " Ticket(s) for " + ddlRoutes.Text + " and your total is $" + Convert.ToString(Tcost * numTickets);
                        }
                        if (Tnum == 0)
                        {
                            lbNumberNeeded.Text = "No tickets available to Montreal";
                        }
                        break; //Montreal
                    case ("Halifax"):
                        Tcost = Convert.ToDouble(lbHalifaxCost.Text);
                        Tnum = Convert.ToInt32(lblHalifaxTickets.Text);
                        if (numTickets <= 0 || numTickets > Convert.ToInt32(Tnum))
                        {
                            lbNumberNeeded.Text = "Number of tickets must be greater than 0 and less than or equal to the number of tickets available";
                            err = 1;
                        }//if
                        if (err == 0)
                        {
                            lblHalifaxTickets.Text = Convert.ToString(Tnum - numTickets);
                            lblInvoice.Text = "You have purchased " + tbTickets.Text + " Ticket(s) for " + ddlRoutes.Text + " and your total is $" + Convert.ToString(Tcost * numTickets);
                        }
                        if (Tnum == 0)
                        {
                            lbNumberNeeded.Text = "No tickets available to Halifax";
                        }
                        break; //Halifax
                    default:
                        Tcost = new Double();
                        Tnum = new Int32();
                        break; //Default
                }//Switch
                if (Tnum > 0 && numTickets <= Tnum && numTickets != 0)
                {
                    lbTransaction.Text += "* " + tbTickets.Text + " Tickets sold to " + ddlRoutes.Text + " for a total of $" + Convert.ToString(Tcost * numTickets) + "<br />";
                }
            }//else
        }//btnSubmit.click
    }
}