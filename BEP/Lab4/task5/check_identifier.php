<?php
require_once '../include/common.inc.php';
header("Content-type: text/plain");

set_error_handler("myErrorHandler");

$argumentsArray = getArgumentsArray();
if (count($argumentsArray) != 1) {
    trigger_error("<b style=\"color: red\">Bad parameters count.</b>", E_USER_ERROR);
}

$str = getArgumentValue($argumentsArray, 'arg');
if (!isIdentifier($str, $hint)) {
    echo "no\n", $hint;
} else {
    echo "yes";
}
