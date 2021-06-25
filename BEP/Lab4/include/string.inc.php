<?php

function last($str)
{
    $len = strlen($str);
    if ($len == 0) {
        trigger_error("<b style=\"color: red\">String is empty.</b>", E_USER_ERROR);
        return null;
    }
    return substr($str, -1);
}

function without_last($str)
{
    $len = strlen($str);
    if ($len == 0) {
        trigger_error("<b style=\"color: red\">String is empty.</b>", E_USER_ERROR);
        return null;
    }
    return substr($str, 0, -1);
}

function revers($str)
{
    $len = strlen($str);
    if ($len == 0) {
        trigger_error("<b style=\"color: red\">String is empty.</b>", E_USER_ERROR);
        return null;
    }
    for ($i = 0; $i < $len / 2; $i++) {
        $tmp = $str[$i];
        $str[$i] = $str[$len - $i - 1];
        $str[$len - $i - 1] = $tmp;
    }
    return $str;
}

function isIdentifier($str, &$hint)
{
    $len = strlen($str);
    if ($len == 0) {
        $hint = "String is empty.";
        return false;
    }
    $symbol = $str[0];
    if (!ctype_alpha($symbol) && $symbol != '_') {
        $hint = "First symbol '$symbol' is not allowed into identifier.";
        return false;
    }
    for ($i = 1; $i < $len; $i++) {
        $symbol = $str[$i];
        if (!ctype_alnum($symbol) && $symbol != '_') {
            $hint = "Symbol '$symbol' is not allowed into identifier.";
            return false;
        }
    }
    return true;
}

function removeExtraBlanks($str)
{
    $stringArray = array();
    $token = strtok($str, " ");
    while ($token !== false) {
        $stringArray[] = $token;
        $token = strtok(" ");
    }
    return implode(" ", $stringArray);
}

// a1D23D3efg = 40 + 16 + 16 + 12 - 2 - 2 = 80
// abaD = 16 + 6 + 2 - 4 - 2 = 18
function getPasswordStrength($str)
{
    $upperCaseCount = 0;
    $lowerCaseCount = 0;
    $digitCount = 0;
    $symbolsCount = strlen($str);
    $existedSymbols = count_chars($str, 1);
    $strength = 0; // 1
    $strength += $symbolsCount * 4; // 2
    foreach ($existedSymbols as $symbol => $count) {
        if ($count > 1) {
            $strength -= $count; // 8
        }
        if (is_numeric(chr($symbol))) {
            $digitCount += $count;
        } else {
            (ctype_lower(chr($symbol))) ? $lowerCaseCount += $count : $upperCaseCount += $count;
        }
    }
    $strength += $digitCount * 4; // 3
    if ($upperCaseCount > 0) {
        $strength += ($symbolsCount - $upperCaseCount) * 2; // 4
    }
    if ($lowerCaseCount > 0) {
        $strength += ($symbolsCount - $lowerCaseCount) * 2; // 5
    }
    if ($digitCount == 0 || $digitCount == $symbolsCount) {
        $strength -= $symbolsCount; // 6, 7
    }
    return $strength;
}
