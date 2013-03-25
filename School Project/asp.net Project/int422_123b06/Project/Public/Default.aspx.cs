using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace int422_123b06.Project.Public
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (User.IsInRole("admin"))
            {
                Response.Redirect("~/Project/Admin/DefaultAdmin.aspx");
            }
            else if (User.IsInRole("user"))
            {
                Response.Redirect("~/Project/User/DefaultUser.aspx");
            }
        }
    }
}