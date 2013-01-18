<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/user.Master" AutoEventWireup="true" CodeBehind="Search.aspx.cs" Inherits="int422_123b06.Project.User.Search" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

        Select a Student:<br />
&nbsp;<asp:DropDownList ID="ddlStudent" runat="server" AutoPostBack="True">
            <asp:ListItem Selected="True" Value="-1">No Student Avaliable</asp:ListItem>
        </asp:DropDownList>
        <br />
        <br />
        Search:&nbsp;
        <asp:TextBox ID="tbSearch" runat="server" Width="174px" MaxLength="9"></asp:TextBox>
        &nbsp;<asp:RegularExpressionValidator ID="regexSearch" runat="server" ForeColor="Red" 
            ValidationExpression="[0]{0,1}[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]" 
            ControlToValidate="tbSearch" ValidationGroup="regex" 
            SetFocusOnError="True">Enter a student id starting with a 0 or without a 0</asp:RegularExpressionValidator>
        <br />
        <br />
        <asp:Button ID="btnSearch" runat="server" onclick="btnSearch_Click" 
            Text="Search" />
        &nbsp;<br />
        <br />
        <asp:Label ID="lblError" runat="server"></asp:Label>
        <br />
<asp:Label ID="lblQuestion" runat="server"></asp:Label>
        <br />
        <br />
        <asp:Button ID="btnYes" runat="server" onclick="btnYes_Click" Text="Yes" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="btnNo" runat="server" onclick="btnNo_Click" Text="No" />
&nbsp;
</asp:Content>
