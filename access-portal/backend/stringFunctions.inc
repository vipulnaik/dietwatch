<?php

function printSmartLink($url, $title) {
  $stringToPrint = '<a href="'.$url.'">'.$title.'</a>';
  if (strlen($url) >= 32 and substr($url,0,31) == "https://www.lesswrong.com/posts") {
    $greaterWrongUrl = str_replace("https://www.lesswrong.com", "https://www.greaterwrong.com", $url);
    $readerUrl = str_replace("https://www.lesswrong.com", "https://lw2.issarice.com", $url);
    $stringToPrint .= ' (<a href="'.$greaterWrongUrl.'">GW</a>, <a href="'.$readerUrl.'">IR</a>)';
  } else if (strlen($url) >= 42 and substr($url,0,41) == "https://forum.effectivealtruism.org/posts") {
    $greaterWrongUrl = str_replace("https://forum.effectivealtruism.org", "https://ea.greaterwrong.com", $url);
    $readerUrl = str_replace("https://forum.effectivealtruism.org", "https://eaforum.issarice.com", $url);
    $stringToPrint .= ' (<a href="'.$greaterWrongUrl.'">GW</a>, <a href="'.$readerUrl.'">IR</a>)';
  }
  return $stringToPrint;
}

function cleanNotes($notes) {
  $notesList = explode(" ",$notes);
  $augmentedNotes = "";
  foreach ($notesList as $notesWord) {
    if (substr($notesWord,0,4) == "http") {
      $augmentedNotes = $augmentedNotes . printSmartLink($notesWord, $notesWord). " ";
    } else {
      $augmentedNotes = $augmentedNotes . $notesWord . " ";
    }
  }
  return $augmentedNotes;
}

function explodePersonCsv($personCsv) {
  return explodePersonCharSepValues($personCsv, ",");
}

function explodeTagCsv($tagCsv) {
  return explodeTagCharSepValues($tagCsv, ",");
}

function explodeAnimalTypeCsv($animalTypeCsv) {
  return explodeAnimalTypeCharSepValues($animalTypeCsv, ",");
}

function explodePeopleClusterCsv($peopleClusterCsv) {
  return explodePeopleClusterCharSepValues($peopleClusterCsv, ",");
}

function explodePersonPsv($personPsv) {
  return explodePersonCharSepValues($personPsv, "|");
}

function explodeTagPsv($tagPsv) {
  return explodeTagCharSepValues($tagPsv, "|");
}

function explodeAnimalTypePsv($animalTypePsv) {
  return explodeAnimalTypeCharSepValues($animalTypePsv, "|");
}

function explodePeopleClusterPsv($peopleClusterPsv) {
  return explodePeopleClusterCharSepValues($peopleClusterPsv, "|");
}

function explodePersonCharSepValues($personCsv, string $char) {
  $personsList = explode($char,$personCsv);
  $formattedString = '';
  foreach ($personsList as $person) {
    $formattedString = $formattedString . '<a href="/person.php?person='.urlencode($person).'">'.$person.'</a> ';
  }
  return $formattedString;
}

function explodeTagCharSepValues($tagCsv, string $char) {
  $tagsList = explode($char,$tagCsv);
  $formattedString = '';
  foreach ($tagsList as $tag) {
    $formattedString = $formattedString . '<a href="/tag.php?tag='.urlencode($tag).'">'.$tag.'</a> ';
  }
  return $formattedString;
}

function explodeAnimalTypeCharSepValues($animalTypeCsv, string $char) {
  $animalTypesList = explode($char,$animalTypeCsv);
  $formattedString = '';
  foreach ($animalTypesList as $animalType) {
    $formattedString = $formattedString . '<a href="/animal_type.php?tag='.urlencode($animalType).'">'.$animalType.'</a> ';
  }
  return $formattedString;
}

function explodePeopleClusterCharSepValues($peopleClusterCsv, string $char) {
  $peopleClustersList = explode($char,$peopleClusterCsv);
  $formattedString = '';
  foreach ($peopleClustersList as $peopleCluster) {
    $formattedString = $formattedString . '<a href="/people_cluster.php?tag='.urlencode($peopleCluster).'">'.$peopleCluster.'</a> ';
  }
  return $formattedString;
}

?>
