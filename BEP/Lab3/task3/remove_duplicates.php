<?php
if ($argc != 2) {
    echo 'Incorrect number of arguments!', PHP_EOL;
    echo 'Usage php remove_duplicates.php <string>', PHP_EOL;
} else {
    $uniqArray = removeDuplicates($argv[1]);
    echo implode("", $uniqArray), PHP_EOL;
}

function removeDuplicates($str) {
    return array_unique(str_split($str));
}
