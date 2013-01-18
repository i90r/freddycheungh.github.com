using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Classes;

namespace int422_123b06.UserControls
{
    public partial class MailUserControl : System.Web.UI.UserControl
    {
        Mail send;
        protected void Page_Load(object sender, EventArgs e)
        {
            tbTo.Enabled = true;
            tbFrom.Enabled = true;
            tbSubject.Enabled = true;
            tbMessage.Enabled = true;
            tbCc.Enabled = true;
            btnSend.Enabled = true;
        }

        protected void btnSend_Click(object sender, EventArgs e)
        {
            bool valid = false;
            if (tbCc.Text == null)
            {
                send = new Mail(tbTo.Text, tbFrom.Text, tbSubject.Text, tbMessage.Text);
            }
            else
            {
                send = new Mail(tbTo.Text, tbFrom.Text, tbSubject.Text, tbMessage.Text, tbCc.Text);
            }
            valid = send.sendMail();
            tbTo.Enabled = false;
            tbFrom.Enabled = false;
            tbSubject.Enabled = false;
            tbMessage.Enabled = false;
            tbCc.Enabled = false;
            btnSend.Enabled = false;
            //Empties the strings
            tbTo.Text = string.Empty;
            tbFrom.Text = string.Empty;
            tbSubject.Text = string.Empty;
            tbMessage.Text = string.Empty;
            tbCc.Text = string.Empty;
        }
    }
} 