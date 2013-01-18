<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="lab1.aspx.cs" Inherits="int422_123b06.Labs.lab1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>The Red Dog Bus Company</title>
    <style type="text/css">
        .style1 {
            width: 100%;
            border-style: solid;
            border-width: 1px;
        }
        .style2
        {
            width: 325px;
        }
    </style>
    <link href="Lab1.css" rel="stylesheet" type="text/css" />
</head>
<body>
    <h2>The Red Dog Bus Company</h2>
    <form id="form1" runat="server">
    <div>
     <table class="style1">
            <tr>
                <th class="style2">
                    Routes</th>
                <th>
                    Cost</th>
                <th>
                    Tickets Available</th>
            </tr>
            <tr>
                <td class="style2">
                    Barrie</td>
                <td>
                    $<asp:Label ID="lbBarrieCost" runat="server" Text="21.65"></asp:Label>
                </td>
                <td>
                    <asp:Label ID="lblBarrieTickets" runat="server" Text="42"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    London</td>
                <td>
                    $<asp:Label ID="lbLondonCost" runat="server" Text="34.20"></asp:Label>
                </td>
                <td>
                    <asp:Label ID="lblLondonTickets" runat="server" Text="42"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    Montreal</td>
                <td>
                    $<asp:Label ID="lbMontrealCost" runat="server" Text="90.70"></asp:Label>
                </td>
                <td>
                    <asp:Label ID="lblMontrealTickets" runat="server" Text="42"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    Halifax</td>
                <td>
                    $<asp:Label ID="lbHalifaxCost" runat="server" Text="153.00"></asp:Label>
                </td>
                <td>
                    <asp:Label ID="lblHalifaxTickets" runat="server" Text="42"></asp:Label>
                </td>
            </tr>
        </table>
    
    </div>
    <br />
    <div>
    <asp:DropDownList ID="ddlRoutes" runat="server" ValidationGroup="tickets">
        <asp:ListItem Selected="True" Value="-1">Please select a route</asp:ListItem>
        <asp:ListItem Value="Barrie">Barrie</asp:ListItem>
        <asp:ListItem>London</asp:ListItem>
        <asp:ListItem>Montreal</asp:ListItem>
        <asp:ListItem>Halifax</asp:ListItem>
    </asp:DropDownList>
    <asp:Label ID="lblDdRoutesError" runat="server" ForeColor="Red"></asp:Label>
    </div>
    <br />
    <div>
    &nbsp;How many tickets?<asp:TextBox ID="tbTickets" runat="server" 
        ValidationGroup="tickets"></asp:TextBox>
    <asp:RequiredFieldValidator ID="rfvTicketError" runat="server" 
        ControlToValidate="tbTickets" Display="Dynamic" 
        ErrorMessage="You must enter the number of tickets" ForeColor="Red"></asp:RequiredFieldValidator>
    <asp:Label ID="lbNumberNeeded" runat="server" ForeColor="Red"></asp:Label>
    </div>
    <br />
    <asp:Button ID="SubmitId" runat="server" onclick="SubmitId_Click" 
        style="margin-right: 4px" Text="Submit" ValidationGroup="tickets" />
    <br />
    <br />
    <asp:Label ID="lblInvoice" runat="server"></asp:Label>
    <br />
    <br />
    <h3> Transactions:</h3>
    <asp:Label ID="lbTransaction" runat="server"></asp:Label>
    </div>
    </form>
</body>
</html>
