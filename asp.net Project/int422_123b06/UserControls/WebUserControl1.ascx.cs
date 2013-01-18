using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using int422_123b06.Classes;            //scope 

namespace int422_123b06.UserControls
{
    public partial class WebUserControl1 : System.Web.UI.UserControl
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Person x = new Person();
        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            lblLabel.Text = tbEnter.Text;
        }
    }
}