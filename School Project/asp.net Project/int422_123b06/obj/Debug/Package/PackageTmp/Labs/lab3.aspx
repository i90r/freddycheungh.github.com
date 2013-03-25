<%@ Page Title="" Language="C#" MasterPageFile="~/Labs/labs.Master" AutoEventWireup="true" CodeBehind="lab3.aspx.cs" Inherits="int422_123b06.Labs.lab3" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <asp:Panel ID="Panel1" runat="server" Height="487px" Width="1388px">
        <asp:FileUpload ID="fileUploader" runat="server" />
        <br />
        <br />
        <asp:Button ID="btnUpload" runat="server" onclick="btnUpload_Click" 
            Text="Upload Button" />
        <br />
        <br />
        <asp:Label ID="lblResult" runat="server"></asp:Label>
    </asp:Panel>
</asp:Content>
