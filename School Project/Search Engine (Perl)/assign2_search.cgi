#!/usr/bin/perl

use CGI qw/:standard/;
#use LWP::Simple; 
#use DBI; 
#use CGI::Carp qw(fatalsToBrowser warningsToBrowser); #DEBUG

my $query = new CGI;
print $query->header();

if($query->param("submit")){
  process_form ( );
}
else{
  display_form ( );
}

### DISPLAY THE FORM ###
sub display_form{
  my $cgi = new CGI;
  my $error_message = shift;

  print $cgi->start_html();
  menu();
  print "<form action='assign2_search.cgi' method='post'>
      <input type='hidden' name='submit' value='Submit'>
      <p>$error_message</p>
      <p>
        Search name:<br/>
        <input type='text' name='name' value='$cname'>
      </p>
      <p>
        Search author:<br/>
        <input type='text' name='author' value='$cauthor'>
      </p>
      <p>
        Search keyword:<br/>
        <input type='text' name='keyword' value='$ckeyword'>
      </p>
      <p>
        Search URL:<br/>
        <input type='text' name='url' value='$curl'>
      </p>
      <input type='submit' name='submit' value='Submit'>
    </form>";
  print $cgi->end_html();
}

### PROCESS THE FORM ###
sub process_form{
  if(validate_form()){
    print 'TESTTTT';
    #$connection = DBI->connect("DBI:mysql:host=db-mysql;database=int322_122a25", "int322_122a25", "heGZ2258") or #die("Can't connect to the database: " . DBI->errstr);
      
    #$connection->disconnect;
  }
}

### VALIDATE THE FORM ###
sub validate_form{
  $name = $query->param("name");
  $author = $query->param("author");
  $keyword = $query->param("keyword");
  $url = $query->param("url");
  my $error_message = "";
  my $check = 1;
  
  ### CHECK NAME ###
  if($name =~ m/([a-zA-Z\s]{0,})/){
	$cname = $name;
    $name = "$1";
  }
  if($cname ne $name){
    $error_message .= "
      <font color='red'><b>Name can only contain alphabetical characters and spaces.</b></font><br/>";
    $check = 0;
  }
  
  ### CHECK AUTHOR ###
  if($author =~ m/([a-zA-Z\s]{0,})/){
	$cauthor = $author;
    $author = "$1";
  }
  if($cauthor ne $author){
    $error_message .= "
      <font color='red'><b>Author can only contain alphabetical characters and spaces.</b></font><br/>";
    $check = 0;
  }
  
  ### CHECK KEYWORD ###
  if($keyword =~ m/([a-zA-Z]*)/){
	$ckeyword = $keyword;
    $keyword = "$1";
  }
  if($ckeyword ne $keyword){
    $error_message .= "
      <font color='red'><b>Keyword can only contain alphabetical characters.</b></font><br/>";
    $check = 0;
  }
  
  ### CHECK URL ###
  if($url =~ m/([a-zA-Z0-9:\/~\?=\+&]*\.?[a-zA-Z0-9:\/~\?=\+&]*)/){
	$curl = $url;
    $url = "$1";
  }
  if($curl ne $url){
    $error_message .= "
      <font color='red'><b>URL can only contain alphabetical characters and the following characters :/.~?=+&.</b></font><br/>";
    $check = 0;
  }
  
  ### CHECK IF ALL ARE EMPTY ###
  if(!$cname && !$cauthor && !$ckeyword && !$curl){
	$error_message .= "
      <font color='red'><b>Please provide at least one search criteria</b></font><br/>";
    $check = 0;
  }
  
  if(check==0){
    display_form ($error_message, $name, $author, $keyword, $url);
    return 0;
  }
  else{
    return 1;
  }
}

### MENU ###
sub menu{
  print "<a href='assign2.cgi'>Enter URL</a>
  <a href='assign2_search.cgi'>Search</a>";
}

