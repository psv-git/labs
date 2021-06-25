<?php
if ($argc > 1) {
    echo 'Numbers of arguments: ', $argc - 1, PHP_EOL;
    echo 'Arguments: ', implode(" ", array_slice($argv, 1)), PHP_EOL;
} else {
    echo 'No parameters were specified!', PHP_EOL;
}
