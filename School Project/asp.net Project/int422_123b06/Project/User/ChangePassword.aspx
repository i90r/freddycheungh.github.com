<%@ Page Title="" Language="C#" MasterPageFile="~/Project/Masterpages/user.Master" AutoEventWireup="true" CodeBehind="ChangePassword.aspx.cs" Inherits="int422_123b06.Project.User.ChangePassword" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <p>
        Current Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="tbCurPwd" runat="server"></asp:TextBox>
    <br />
        New Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        <asp:TextBox ID="tbNewPwd" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator id="rPwdValidator" runat="server"
                                      ControlToValidate="tbNewPwd" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
    <br />
        Confirmed Password:&nbsp; 
        <asp:TextBox ID="tbConfirmedPwd" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator id="rConfirmedPwdValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ErrorMessage="Required" />
        <asp:CompareValidator id="pwdCompareValidator" runat="server"
                                      ControlToValidate="tbConfirmedPwd" ForeColor="red"
                                      Display="Static" ControlToCompare="tbNewPwd" />
    </p>
    <p>
        <asp:Label ID="lblError" runat="server"></asp:Label>
    </p>
    <p>
        <asp:Button ID="btnChange" runat="server" onclick="btnChange_Click" 
            Text="Change" />
    </p>
</asp:Content>
