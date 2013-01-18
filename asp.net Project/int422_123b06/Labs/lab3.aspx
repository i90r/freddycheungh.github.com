<%@ Page Title="" Language="C#" MasterPageFile="~/Labs/labs.Master" AutoEventWireup="true" CodeBehind="lab3.aspx.cs" Inherits="int422_123b06.Labs.lab3" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <asp:Panel ID="Panel1" runat="server" Height="487px" Width="1388px">
        <asp:FileUpload ID="fileUploader" runat="server" />
        <br />
        <br />
        <asp:Button ID="btnUpload" runat="server" onclick="btnUpload_Click" 
            Text="Upload File" />
        <br />
        <br />
        <asp:Label ID="lblResult" runat="server"></asp:Label>
        <br />
        <br />
        Copy :
        <asp:Button ID="btnCopy" runat="server" onclick="btnCopy_Click" 
            Text="Copy File" />
        <br />
        <br />
        <asp:Label ID="lblCopyError" runat="server"></asp:Label>
        <br />
        <br />
        <asp:DropDownList ID="ddlUpload" runat="server" AutoPostBack="True" 
            onselectedindexchanged="ddlUpload_SelectedIndexChanged">
            <asp:ListItem Selected="True" Value="-1">Please select a file to read</asp:ListItem>
        </asp:DropDownList>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="tbSearch" runat="server" Width="231px"></asp:TextBox>
        <asp:Button ID="btnSearch" runat="server" onclick="btnSearch_Click" 
            Text="Search" />
        <br />
        <br />
        <asp:TextBox ID="tbText" runat="server" Height="187px" TextMode="MultiLine" 
            Width="1326px"></asp:TextBox>
        <br />
    </asp:Panel>
</asp:Content>
