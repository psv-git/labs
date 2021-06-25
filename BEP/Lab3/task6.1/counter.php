<?php
header("Content-type: text/plain");
set_error_handler("myErrorHandler");
$argumentsArray = getArgumentsArray();
if (count($argumentsArray) != 1) {
    trigger_error("", E_USER_ERROR);
}
$str = getArgumentValue($argumentsArray, 'string');
if (strlen($str) == 0) {
    trigger_error("", E_USER_ERROR);
}
$countArray = getSymbolsCount($str);
printSymbolsCount($countArray);

// FUNCTIONS ==================================================================

function getSymbolsCount($str)
{
    $str = strtolower($str);
    return count_chars($str, 1);
}

function printSymbolsCount($countArray)
{
    $spaceCode = 32;
    foreach ($countArray as $symbolCode => $count) {
        $symbol = chr($symbolCode);
        if ($symbolCode == $spaceCode) {
            echo "\"$symbol\"", " - ", $count, "\n";
        } else {
            echo $symbol, " - ", $count, "\n";
        }
    }
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
