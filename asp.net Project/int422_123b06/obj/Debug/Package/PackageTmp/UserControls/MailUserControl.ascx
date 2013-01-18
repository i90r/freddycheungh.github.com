<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="MailUserControl.ascx.cs" Inherits="int422_123b06.UserControls.MailUserControl" %>
<p>
    Compose Email</p>
    <div>To:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="tbTo" runat="server" Width="268px"></asp:TextBox>
        <br />
        From:&nbsp;&nbsp;&nbsp;&nbsp; 
        <asp:TextBox ID="tbFrom" runat="server" Width="268px"></asp:TextBox>
        <br />
        cc:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        <asp:TextBox ID="tbCc" runat="server" Width="269px"></asp:TextBox>
        <br />
      Subject:&nbsp;
        <asp:TextBox ID="tbSubject" runat="server" Width="270px"></asp:TextBox>
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        Message:<br />
        <asp:TextBox ID="tbMessage" runat="server" Height="210px" Width="667px" 
            TextMode="MultiLine"></asp:TextBox>
        <br />
        <br />
        <asp:Button ID="btnSend" runat="server" Text="Send" onclick="btnSend_Click" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</div>

