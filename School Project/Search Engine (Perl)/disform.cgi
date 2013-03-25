#!/usr/bin/perl

use CGI qw/:standard/;
use LWP::Simple; 
use HTML::HeadParser; 
use CGI::Carp qw(fatalsToBrowser warningsToBrowser); #DEBUG

### If query string is empty display the enter URL form ###
if (length ($ENV{'QUERY_STRING'})==0){
  my $URL = shift;
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

    $URL =~ s/<([^>]|\n)*>//g;

    print $cgi->start_html();
    print "<form action='assign2.cgi' method='post'>
        <input type='hidden' name='submit' value='Submit'>
        <p>$error_message</p>
        <p>
          Please enter a URL in the following format (wihtout brackets):<br/>
          'http://www.exampleaddress.com'<br/>
          <input type='text' name='url' value=$URL>
        </p>
        <input type='submit' name='submit' value='Submit'>
      </form>";
    print $cgi->end_html();
  }

  ### PROCESS THE FORM ###
  sub process_form{
    if(validate_form()){
      print $URL;
      my $site = get ("$URL"); 
      my $head = HTML::HeadParser->new;
      $head->parse("$site"); 
      my $test =  $head->header('X-Meta-Description') . "<br/>"; 
      print $test;
      print $head->header('X-Meta-Robots') . "\n\n"; 
      print end_html();
    }
  }

  ### VALIDATE THE FORM ###
  sub validate_form{
    $URL = $query->param("url");
    my $error_message = "";
    my $check = 0;

    if($URL =~ m/([hHtTpPsS]{4,5}\:\/\/[wW]{0,3}\.?[a-zA-Z0-9-]{2,}\.[a-zA-Z]{2,})/){
      $URL = "$1";
      $check=1;
    }

    if($check){
      return 1;
    }
    else{
      $error_message = "
        <font color='red'><b>The url you have entered is invalid, please try again</b></font><br/>";
      display_form ( $error_message, $URL);
      return 0;
    }
  }
}
elsif(){
  
}
