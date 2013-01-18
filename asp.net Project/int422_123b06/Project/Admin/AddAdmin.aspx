<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/admin.Master" AutoEventWireup="true" CodeBehind="AddAdmin.aspx.cs" Inherits="int422_123b06.Project.Admin.AddAdmin" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3>Add an Administrator:</h3>
User Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:TextBox ID="tbUserName" runat="server" Width="126px"></asp:TextBox>
    *<asp:RequiredFieldValidator id="rfvUserName" runat="server"
                                      ControlToValidate="tbUserName" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
<br />
Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:TextBox ID="tbPassword" runat="server" TextMode="Password" Width="127px"></asp:TextBox>
    *<asp:RequiredFieldValidator id="rPwdValidator" runat="server"
                                      ControlToValidate="tbPassword" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
<br />
Confirm Password:&nbsp;&nbsp;&nbsp; 
        <asp:Textbox id="tbConfirmedPwd" runat="server" TextMode="Password" 
    Width="128px" />
        *<asp:RequiredFieldValidator id="rConfirmedPwdValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
        <asp:CompareValidator id="pwdCompareValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ControlToCompare="tbPassword"
                                      
        ErrorMessage="Confirm password must match password." />
<br />
Email:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; 
<asp:TextBox ID="tbEmail" runat="server" Width="128px"></asp:TextBox>
    *<asp:RequiredFieldValidator id="rfvEmail" runat="server"
                                      ControlToValidate="tbEmail" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
    <br />
    Security Question:&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:DropDownList ID="ddlQuestion" runat="server">
        <asp:ListItem Selected="True" Value="-1">What is your favorite animal?</asp:ListItem>
        <asp:ListItem>What is your favorite color?</asp:ListItem>
        <asp:ListItem>Where were you born?</asp:ListItem>
        <asp:ListItem>Which is your favorite country to visit?</asp:ListItem>
        <asp:ListItem>Which is your favorite soccer team?</asp:ListItem>
        <asp:ListItem>What is your favorite sport?</asp:ListItem>
    </asp:DropDownList>
&nbsp;*
    <asp:RequiredFieldValidator ID="rfvDdl" runat="server" 
        ControlToValidate="ddlQuestion" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
<br />
Answer:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:TextBox ID="tbAnswer" runat="server" Width="129px"></asp:TextBox>
    *<asp:RequiredFieldValidator id="rfvAnswer" runat="server"
                                      ControlToValidate="tbAnswer" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
<br />
<br />
    * Indicates required fields<br />
    <br />
<asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
<br />
<br />
<asp:Button ID="btnSubmit" runat="server" onclick="btnSubmit_Click" 
    Text="Create" />
<br />
</asp:Content>
