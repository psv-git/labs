<?php
$translateDictionary = array(
    'Known' => 'Известный'
);
$isWordCorrect = true;

$word = getWord($isWordCorrect);
if (!$isWordCorrect) {
    exitWithCode(400);
}
if (array_key_exists($word, $translateDictionary)) {
    echo $translateDictionary[$word];
} else {
    exitWithCode(404);
}

// FUNCTIONS ==================================================================

function getWord(&$isWordCorrect)
{
    if (!isset($_GET['word'])) {
        $isWordCorrect = false;
    } else {
        if (strlen($_GET['word']) == 0) {
            $isWordCorrect = false;
        }
        return $_GET['word'];
    }
}

function exitWithCode($code)
{
    switch ($code) {
        case 400:
            header("Status: 400");
            break;
        case 404:
            header("Status: 404");
            break;
        default:
            break;
    }
    exit();
}
