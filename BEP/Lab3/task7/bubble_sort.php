<?php
header("Content-type: text/plain");
set_error_handler("myErrorHandler");
$argumentsArray = getArgumentsArray();
if (count($argumentsArray) != 1) {
    trigger_error("", E_USER_ERROR);
}
$str = getArgumentValue($argumentsArray, 'numbers');
$numbersArray = getNumbersArray($str);
$numbersArray = bubbleSort($numbersArray);
echo implode(",", $numbersArray);

// FUNCTIONS ==================================================================

function bubbleSort($numbersArray)
{
    $arraySize = count($numbersArray);
    for ($i = 1; $i < $arraySize; $i++) {
        for ($j = $arraySize - 1; $j >= $i; $j--) {
            if($numbersArray[$j-1] > $numbersArray[$j]) {
            $tmp = $numbersArray[$j - 1];
            $numbersArray[$j - 1] = $numbersArray[$j];
            $numbersArray[$j] = $tmp;
            }
        }
    }
    return $numbersArray;
}

function getNumbersArray($str)
{
    if (strlen($str) == 0) {
        trigger_error("", E_USER_ERROR);
        return null;
    }
    $numbersArray = explode(",", $str);
    foreach ($numbersArray as $number) {
        if (!is_numeric($number)) {
            trigger_error("", E_USER_ERROR);
            return null;
        }
    }
    return $numbersArray;
}

function getArgumentsArray()
{
    $query = $_SERVER['QUERY_STRING'];
    parse_str($query, $argumentsArray);
    return $argumentsArray;
}

function getArgumentValue($argumentsArray, $arg)
{
    if (!isset($_GET[$arg])) {
        trigger_error("", E_USER_ERROR);
        return null;
    } else {
        return $argumentsArray[$arg];
    }
}

function myErrorHandler($errno, $errstr, $errfile, $errline)
{
    header("Content-type: text/html");
    if (!(error_reporting() & $errno)) {
        return false;
    }
    switch ($errno) {
        case E_USER_ERROR:
            header("Status: 400");
            exit(1);
            break;
        default:
            echo "<b>Undefined error: [$errno] $errstr<br /></b>";
            break;
    }
    return true;
}
