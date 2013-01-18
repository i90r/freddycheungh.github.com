<%@ Page Title="" Language="C#" MasterPageFile="~/Labs/labs.Master" AutoEventWireup="true" CodeBehind="Lab2.aspx.cs" Inherits="int422_123b06.Labs.Lab2" %>
<%@ Register src="../UserControls/WebUserControl1.ascx" tagname="WebUserControl1" tagprefix="uc1" %>
<%@ Register src="../UserControls/MailUserControl.ascx" tagname="MailUserControl" tagprefix="uc2" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <link href="lab2.css" rel="stylesheet" type="text/css" />
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    Lab 2<br />
    <asp:Panel ID="pnlEnter" runat="server" Height="348px" Width="1565px">
        <p>Please fill in the following fields:</p><br />
        <br />
        First Name:&nbsp;
        <asp:TextBox ID="tbFirstName" runat="server" ValidationGroup="Student" 
            Width="149px"></asp:TextBox>
        <asp:RequiredFieldValidator ID="rfvFirstName" runat="server" 
            ControlToValidate="tbFirstName" ErrorMessage="Please enter First Name" 
            ForeColor="Red" Display="Dynamic"></asp:RequiredFieldValidator>
        <asp:Label ID="lblFnameError" runat="server" ForeColor="Red"></asp:Label>
        <br />
        Last Name:&nbsp;
        <asp:TextBox ID="tbLastName" runat="server" ValidationGroup="Student" 
            Width="151px"></asp:TextBox>
        &nbsp;<asp:RequiredFieldValidator ID="rfvLastName" runat="server" 
            ControlToValidate="tbLastName" Display="Dynamic" 
            ErrorMessage="Please enter Last Name" ForeColor="Red"></asp:RequiredFieldValidator>
        <asp:Label ID="lblLnameError" runat="server" ForeColor="Red"></asp:Label>
        <br />
        Email ID :&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="tbEmailID" runat="server" ValidationGroup="Student" 
            Width="147px"></asp:TextBox>
        &nbsp;<asp:RequiredFieldValidator ID="rfvEmailID" runat="server" 
            ControlToValidate="tbEmailID" ErrorMessage="Please enter an Email" 
            ForeColor="Red" Display="Dynamic"></asp:RequiredFieldValidator>
        &nbsp;<asp:Label ID="lblEmailError" runat="server" ForeColor="Red"></asp:Label>
        <br />
        Seneca ID:&nbsp;&nbsp;
        <asp:TextBox ID="tbSenecaID" runat="server" ValidationGroup="Student" 
            Width="150px"></asp:TextBox>
        &nbsp;<asp:RegularExpressionValidator ID="revSenecaID" runat="server" 
            ControlToValidate="tbSenecaID" ErrorMessage="Please enter Seneca ID as following 0nnnnnnnn or 0nn-nnn-nnn. Numerics Only." 
            ForeColor="Red" 
            
            
            
            ValidationExpression="[0][0-9][0-9]-{0,1}[0-9][0-9][0-9]-{0,1}[0-9][0-9][0-9]"></asp:RegularExpressionValidator>
        <br />
        Program:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:DropDownList ID="ddlProgram" runat="server" ValidationGroup="Student" 
            AutoPostBack="True" onselectedindexchanged="ddlProgram_SelectedIndexChanged">
            <asp:ListItem Selected="True" Value="-1">Please Select a Program</asp:ListItem>
            <asp:ListItem Value="0">CPA </asp:ListItem>
            <asp:ListItem Value="1">CPD</asp:ListItem>
            <asp:ListItem Value="2">DAD</asp:ListItem>
            <asp:ListItem Value="3">CNS</asp:ListItem>
            <asp:ListItem Value="4">CTY</asp:ListItem>
            <asp:ListItem Value="5">BSD</asp:ListItem>
        </asp:DropDownList>
&nbsp;<br />
        <br />
        Semester Enrrolled:
        <asp:RadioButtonList ID="rblSemester" runat="server" AutoPostBack="True" 
            onselectedindexchanged="rblSemester_SelectedIndexChanged" 
            RepeatDirection="Horizontal">
        </asp:RadioButtonList>
        <br />
        <asp:Button ID="btnSubmit" runat="server" onclick="btnSubmit_Click" 
            Text="Submit" />
        <br />
    </asp:Panel>
    <asp:Panel ID="pnlInfo" runat="server" Height="440px">
        <br />
        <p>You have entered the following information:</p><br />
        <br />
        First Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblFirstName" runat="server"></asp:Label>
        <br />
        <br />
        Last Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblLastName" runat="server"></asp:Label>
        <br />
        <br />
        Email ID:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblEmailID" runat="server"></asp:Label>
        <br />
        <br />
        Seneca ID:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblSenecaID" runat="server"></asp:Label>
        <br />
        <br />
        Program:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblProgram" runat="server"></asp:Label>
        <br />
        <br />
        Semester Enrolled:
        <asp:Label ID="lblSemester" runat="server"></asp:Label>
        <br />
        <br />
        <br />
        <br />
        <br />
        <asp:Button ID="btnEmail" runat="server" onclick="btnEmail_Click" 
            Text="Send Email" />
    </asp:Panel>
    <asp:Panel ID="pnlEmail" runat="server" Height="559px">
        <uc2:MailUserControl ID="MailUserControl1" runat="server" />
        <br />
        <asp:Button ID="btnStartOver" runat="server" onclick="btnStartOver_Click" 
            Text="Start Over" />
    </asp:Panel>
</asp:Content>
