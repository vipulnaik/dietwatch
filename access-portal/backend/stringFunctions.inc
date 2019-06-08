<?php

function cleanNotes($notes) {
  $notesList = explode(" ",$notes);
  $augmentedNotes = "";
  foreach ($notesList as $notesWord) {
    if (substr($notesWord,0,4) == "http") {
      $augmentedNotes = $augmentedNotes . '<a href="'.$notesWord.'">'.$notesWord.'</a> ';
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

function explodePersonPsv($personPsv) {
  return explodePersonCharSepValues($personPsv, "|");
}

function explodeTagPsv($tagPsv) {
  return explodeTagCharSepValues($tagPsv, "|");
}

function explodeAnimalTypePsv($animalTypePsv) {
  return explodeAnimalTypeCharSepValues($animalTypePsv, "|");
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

function explodeTagAnimalTypeSepValues($animalTypeCsv, string $char) {
  $animalTypesList = explode($char,$animalTypeCsv);
  $formattedString = '';
  foreach ($animalTypesList as $animalType) {
    $formattedString = $formattedString . '<a href="/animal_type.php?tag='.urlencode($animalType).'">'.$animalType.'</a> ';
  }
  return $formattedString;
}

?>
