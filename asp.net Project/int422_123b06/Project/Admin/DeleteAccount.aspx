<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/admin.Master" AutoEventWireup="true" CodeBehind="DeleteAccount.aspx.cs" Inherits="int422_123b06.Project.Admin.DeleteAccount" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    Select an account to be deleted:<br />
&nbsp;<asp:DropDownList ID="ddlDelete" runat="server" AutoPostBack="True" 
        onselectedindexchanged="ddlDelete_SelectedIndexChanged">
    </asp:DropDownList>
    <br />
    <br />
    Do you wish to delete the data from the database?<br />
    <br />
    <asp:CheckBox ID="cbDelete" runat="server" Text="Delete from database?" />
    <br />
    <br />
    <asp:Label ID="lblError" runat="server"></asp:Label>
    <br />
    <br />
    <asp:Button ID="btnDelete" runat="server" onclick="btnDelete_Click" 
        Text="Delete" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="btnCancel" runat="server" onclick="btnCancel_Click" 
        Text="Cancel" />
</asp:Content>
