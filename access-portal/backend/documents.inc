<?php

print '<h4 id="documents">Documents</h4>';
$documentSelectQuery = "select * from documents;";
$documentSelectResult = $mysqli -> query($documentSelectQuery);
if ($documentSelectResult -> num_rows > 0) {
  print "\n";
  print '<table id="myTableDocuments" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr>';
  print '<th>Title (URL linked)</th>';
  print '<th>Publication date</th>';
  print '<th>Author</th>';
  print '<th>Publisher</th>';
  print '<th>Other participants</th>';
  print '<th>Tags</th>';
  print '<th>Notes</th>';
  for ($i = 0; $i < $documentSelectResult -> num_rows; $i++) {
    $row = $documentSelectResult -> fetch_assoc();
    print '<tr>';
    print '<td><a href="'.$row['url'].'">'.$row['title'].'</a></td>';
    print '<td>'.$row['publication_date'].'</td>';
    if ($row['author'] != '') {
      # Change this to check if author is in list
      print '<td>'.explodeDonorPsv($row['author']).'</td>';
    } else {
      print '<td></td>';
    }

    # Link to publisher as donor or donor?
    print '<td>'.$row['publisher'].'</td>';

    print '<td>'.explodePersonPsv($row['other_participants']).'</td>';
    print '<td>'.explodeTagPsv($row['document_scope']).'</td>';
    print '<td>'.cleanNotes($row['notes']).'</td>';
    print '</tr>';
  }
} else {
  print '<p>No documents yet!</p>';
}
?>