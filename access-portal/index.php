<?php
include_once('doctype.inc');
include_once('analytics.inc');
print '<script src="change-theme.js"></script>';
include_once('strip-commas.inc');
include_once('backend/stringFunctions.inc');
include_once('backend/cachingFunctions.inc');
print "<title>Diet Watch: Documents and People</title>";
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
include_once("backend/globalVariables/passwordFile.inc");
print '<body>';
print '<script>$(document).ready(function()
    {
        $("#myTableDocuments").tablesorter({textExtraction: stripCommas});
    }
); </script>'."\n";
print "<h3>Diet Watch: Documents and People</h3>";
print '<p><span id="changeThemeMenu" style="display: none;">Change <a href="javascript:;" onclick="change_theme_color()">color</a></span>   &thinsp;<!-- blank space to prevent cumulative layout shift --></p>';
include_once('preamble.inc');
print '<h4>Table of contents</h4>';
print '<ul>';
print '<li><a href="#documents">Documents</a></li>';
print '<li><a href="#people">People</a></li>';

print '</ul>';

include ("backend/documents.inc");
include ("backend/people.inc");

include_once("anchorjs.inc");
print '</body>';
?>
