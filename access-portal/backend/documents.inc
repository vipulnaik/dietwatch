<?php

$documentSelectQuery = "select * from documents order by publication_date;";
$documentSelectResult = $mysqli -> query($documentSelectQuery);
if ($documentSelectResult -> num_rows > 0) {
  print '<h4 id="documents">Documents (' . ($documentSelectResult -> num_rows) . ' in number)</h4>';
  print "\n";
  print '<table id="myTableDocuments" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr>';
  print '<th>Title (URL linked)</th>';
  print '<th>Publication date</th>';
  print '<th>Author</th>';
  print '<th>Publisher</th>';
  print '<th>Other participants and mentioned people</th>';
  print '<th>Tags</th>';
  print '<th>Animal types</th>';
  print '<th>People clusters</th>';
  print '<th>Notes</th>';
  print '</tr>';
  print "</thead>\n<tbody>\n";
  for ($i = 0; $i < $documentSelectResult -> num_rows; $i++) {
    $row = $documentSelectResult -> fetch_assoc();
    print "<tr>\n";
    print '<td><a href="'.$row['url'].'">'.$row['title'].'</a></td>'."\n";
    print '<td>'.$row['publication_date']."</td>\n";
    if ($row['author'] != '') {
      # Change this to check if author is in list
      print '<td>'.explodePersonPsv($row['author'])."</td>\n";
    } else {
      print "<td></td>\n";
    }

    print '<td>'.$row['publisher']."</td>\n";

    print '<td>'.explodePersonPsv($row['other_participants_and_mentioned_people'])."</td>\n";
    print '<td>'.explodeTagPsv($row['tags'])."</td>\n";
    print '<td>'.explodeAnimalTypePsv($row['animal_types'])."</td>\n";
    print '<td>'.explodePeopleClusterPsv($row['people_clusters'])."</td>\n";
    print '<td>'.cleanNotes($row['notes'])."</td>\n";
    print "</tr>\n";
  }
  print "</tbody>\n</table>\n";
} else {
  print '<h4 id="documents">Documents (none yet!)</h4>';
}
?>