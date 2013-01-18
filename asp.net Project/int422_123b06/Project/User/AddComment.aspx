<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/user.Master" AutoEventWireup="true" CodeBehind="AddComment.aspx.cs" Inherits="int422_123b06.Project.User.AddComment" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    Select an 
    existing student:<br />
    <br />
    <asp:DropDownList ID="ddlStudent" runat="server" AutoPostBack="True" 
        onselectedindexchanged="ddlStudent_SelectedIndexChanged">
        <asp:ListItem Selected="True" Value="-1">No Student Available</asp:ListItem>
    </asp:DropDownList>
    <br />
    <br />
    Add a new student:<br />
    <br />
    Student ID:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:TextBox ID="tbStudentId" runat="server" MaxLength="9"></asp:TextBox>
    &nbsp;*
    <asp:RequiredFieldValidator ID="rfvStudentId" runat="server" 
        ControlToValidate="tbStudentId" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
    <asp:RegularExpressionValidator ID="regexStudentId" runat="server" 
        
    ErrorMessage="Student ID must be numbers only. Must be a 9 numbers starting with 0 or 8 starting with any numeral characters." ForeColor="Red" 
        ValidationExpression="[0]{0,1}[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]" 
        ValidationGroup="tbStudentId" ControlToValidate="tbStudentId" 
    Display="Dynamic"></asp:RegularExpressionValidator>
    <br />
    Student Name:&nbsp;&nbsp; 
    <asp:TextBox ID="tbStudentName" runat="server"></asp:TextBox>
    <br />
    <br />
    * Indicates required fields<br />
    <br />
    Comment:<br />
    <br />
    <asp:TextBox ID="tbComment" runat="server" Height="221px" Width="956px" 
        TextMode="MultiLine"></asp:TextBox>
&nbsp;<br />
    <br />
    <asp:Button ID="btnAdd" runat="server" Text="Add Comment" 
        onclick="btnAdd_Click" />
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:Button ID="btnNewComment" runat="server" onclick="btnNewComment_Click" 
    Text="Add New Comment" />
    <br />
    <br />
    <asp:Label ID="lblError" runat="server"></asp:Label>
</asp:Content>
