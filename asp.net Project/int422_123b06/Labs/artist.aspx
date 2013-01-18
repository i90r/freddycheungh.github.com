<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="artist.aspx.cs" Inherits="int422_123b06.Labs.artist" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            DataKeyNames="album_id,artist_id" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="album_id" HeaderText="album_id" ReadOnly="True" 
                    SortExpression="album_id" />
                <asp:BoundField DataField="artist_id" HeaderText="artist_id" ReadOnly="True" 
                    SortExpression="artist_id" />
                <asp:BoundField DataField="a_name" HeaderText="a_name" 
                    SortExpression="a_name" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="Data Source=mssql.warp.senecac.on.ca;Initial Catalog=int422_123b06;User ID=int422_123b06;Password=jpTQ6753" 
            ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [Album]">
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
