<?php
$isArrayCorrect = true;
$arr = getArray($isArrayCorrect);
if (!$isArrayCorrect) {
    exitWithCode(400);
}
myReverse($arr);
print_r($arr, false);

// FUNCTIONS ==================================================================

function getArray(&$isArrayCorrect)
{
    if (!isset($_GET['arr'])) {
        $isArrayCorrect = false;
    } else {
        if (strlen($_GET['arr']) == 0) {
            $isArrayCorrect = false;
        }
        return explode(",", $_GET['arr']);
    }
}

function myReverse(&$arr)
{
    $arrLen = count($arr);
    for ($i = 0; $i < $arrLen / 2; $i++) {
        $tmp = $arr[$arrLen - $i - 1];
        $arr[$arrLen - $i - 1] = $arr[$i];
        $arr[$i] = $tmp;
    }
}

function exitWithCode($code)
{
    switch ($code) {
        case 400:
            header("Status: 400");
            break;
        default:
            break;
    }
    exit();
}
