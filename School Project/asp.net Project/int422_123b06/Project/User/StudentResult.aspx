<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/user.Master" AutoEventWireup="true" CodeBehind="StudentResult.aspx.cs" Inherits="int422_123b06.Project.User.StudentResult" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
    <h2>Search Results</h2><br />
    <asp:Table ID="tableResult" runat="server">
    </asp:Table>
    <br />
    <asp:Label ID="lblError" runat="server"></asp:Label>
    <br />
    <br />
    <asp:Button ID="btnAuthor" runat="server" onclick="btnAuthor_Click" 
        Text="Order By Author" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="btnDate" runat="server" onclick="btnDate_Click" 
        Text="Order By Date" />
</asp:Content>
