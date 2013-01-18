<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/admin.Master" AutoEventWireup="true" CodeBehind="AddUser.aspx.cs" Inherits="int422_123b06.Project.Admin.AddUser" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <h3>Add a User: </h3>First Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="tbFirstName" runat="server"></asp:TextBox>
        *
        <asp:RequiredFieldValidator ID="rfvFirstName" runat="server" 
            ControlToValidate="tbFirstName" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
        <br />
        Last Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        <asp:TextBox ID="tbLastName" runat="server"></asp:TextBox>
        *
        <asp:RequiredFieldValidator ID="rfvLastName" runat="server" 
            ControlToValidate="tbLastName" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
        <br />
        User Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;
          <asp:TextBox ID="tbUUserName" runat="server"></asp:TextBox>
        *
        <asp:RequiredFieldValidator ID="rfvUserName" runat="server" 
            ControlToValidate="tbUUserName" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
        <br />
        Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;
        <asp:TextBox ID="tbUPassword" runat="server" TextMode="Password"></asp:TextBox>
        *
        <asp:RequiredFieldValidator id="rPwdValidator" runat="server"
                                      ControlToValidate="tbUPassword" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
        <br />
        Confirm Password:&nbsp;&nbsp;&nbsp; 
        <asp:Textbox id="tbConfirmedPwd" runat="server" TextMode="Password" />
        *
        <asp:RequiredFieldValidator id="rConfirmedPwdValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
          <asp:CompareValidator id="pwdCompareValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ControlToCompare="tbUPassword"
                                      
            ErrorMessage="Confirm password must match password." />
        <br />
        Email:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;
        <asp:TextBox ID="tbUEmail" runat="server"></asp:TextBox>
        *
        <asp:RequiredFieldValidator ID="rfvEmail" runat="server" 
            ControlToValidate="tbUEmail" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
        <br />
        Security Question:&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:DropDownList ID="ddlQuestion" runat="server">
            <asp:ListItem>What is your favorite animal?</asp:ListItem>
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
        Answer:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;
        <asp:TextBox ID="tbUAnswer" runat="server"></asp:TextBox>
        *
        <asp:RequiredFieldValidator ID="rfvAnswer" runat="server" 
            ControlToValidate="tbUAnswer" ErrorMessage="Required" ForeColor="Red"></asp:RequiredFieldValidator>
<p>
        * Indicates required fields</p>
        <p>
        <asp:Label ID="lblMessage" runat="server" ForeColor="Black"></asp:Label>
    </p>
<p>
        <asp:Button ID="btnSubmit" runat="server" onclick="btnSubmit_Click" 
            Text="Create" />
    </p>
</asp:Content>
