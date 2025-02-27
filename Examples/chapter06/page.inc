<?php
class Page
{
  // class Page's attributes
  var $content;
  var $title = 'TLA Consulting Pty Ltd';
  var $keywords = 'TLA Consulting, Three Letter Abbreviation, 
                   some of my best friends are search engines';
  var $buttons = array( 'Home'     => 'home.php', 
                        'Contact'  => 'contact.php', 
                        'Services' => 'services.php', 
                        'Site Map' => 'map.php'
                      );

  // class Page's operations

  function SetContent($newcontent)
  {
 $this->content = $newcontent;
  }

  function SetTitle($newtitle)
  {
    $this->title = $newtitle;
  }

  function SetKeywords($newkeywords)
  {
    $this->keywords = $newkeywords;
  }

  function SetButtons($newbuttons)
  {
    $this->buttons = $newbuttons;
  }

  function Display()
  {
    echo "<html>\n<head>\n";
    $this -> DisplayTitle();
    $this -> DisplayKeywords();
    $this -> DisplayStyles();
    echo "</head>\n<body>\n";
    $this -> DisplayHeader();
    $this -> DisplayMenu($this->buttons);
    echo $this->content;
    $this -> DisplayFooter();
    echo "</body>\n</html>\n";
  }

  function DisplayTitle()
  {
    echo '<title> $this->title </title>';
  }

  function DisplayKeywords()
  {
    echo "<META name=\"keywords\" content=\"$this->keywords\">";
  }

  function DisplayStyles()
  { 
?>   
  <style>
    h1 {color:white; font-size:24pt; text-align:center; 
        font-family:arial,sans-serif}
    .menu {color:white; font-size:12pt; text-align:center; 
           font-family:arial,sans-serif; font-weight:bold}
    td {background:black}
    p {color:black; font-size:12pt; text-align:justify; 
       font-family:arial,sans-serif}
    p.foot {color:white; font-size:9pt; text-align:center; 
            font-family:arial,sans-serif; font-weight:bold}
    a:link,a:visited,a:active {color:white}
  </style>
<?php
  }

  function DisplayHeader()
  { 
?>   
  <table width="100%" cellpadding ="12" cellspacing ="0" border ="0">
  <tr bgcolor ="black">
    <td align ="left"><img src = "logo.gif"></td>
    <td>
        <h1>TLA Consulting Pty Ltd</h1>
    </td>
    <td align ="right"><img src = "logo.gif"></td>
  </tr>
  </table>
<?php
  }

  function DisplayMenu($buttons)
  {
    echo "<table width='100%' bgcolor='white' cellpadding='4' 
                cellspacing='4'\n";
    echo "  <tr>\n";

    //calculate button size
    $width = 100/count($buttons);

    while (list($name, $url) = each($buttons))
    {
      $this -> DisplayButton($width, $name, $url, !$this->IsURLCurrentPage($url));
    }
    echo "  </tr>\n";
    echo "</table>\n";
  }

  function IsURLCurrentPage($url)
  {
    if(strpos( $GLOBALS['SCRIPT_NAME'], $url )==false)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  function DisplayButton($width, $name, $url, $active = true)
  {
    if ($active)
    {
      echo "<td width ='$width%'>
            <a href ='$url'>
            <img src ='s-logo.gif' alt ='$name' border ='0'></a>
            <a href ='$url'><span class='menu'>$name</span></a></td>";
    }  
    else
    {
      echo "<td width ='$width%'>
            <img src ='side-logo.gif'>
            <span class='menu'>$name</span></td>";
    }  
  }

  function DisplayFooter()
  {
?>
    <table width = "100%" bgcolor ="black" cellpadding ="12" border ="0">
    <tr>
      <td>
        <p class="foot">&copy; TLA Consulting Pty Ltd.</p>
        <p class="foot">Please see our 
                      <a href ="">legal information page</a></p>
      </td>
    </tr>
    </table>
<?php
  }
}
?>
