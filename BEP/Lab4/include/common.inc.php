<?php
require_once 'request.inc.php';
require_once 'string.inc.php';

function getArgumentsArray()
{
    $query = $_SERVER['QUERY_STRING'];
    parse_str($query, $argumentsArray);
    return $argumentsArray;
}

function getArgumentValue($argumentsArray, $arg)
{
    if (!isset($_GET[$arg])) {
        trigger_error("<b style=\"color: red\">$arg not found.</b>", E_USER_ERROR);
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
            echo "<b>Error [$errno] $errstr<br />";
            echo "Fatal error in string $errline from file $errfile</b>";
            exit(1);
            break;
        default:
            echo "<b>Undefined error: [$errno] $errstr<br /></b>";
            break;
    }
    return true;
}
