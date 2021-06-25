<?php
header("Content-type: text/plain");

$firstArray  = array(2, 3, 5, 7, 11, 13, 17, 19, 23, 29);
$secondArray = array(
    'count' => 'Подсчитывает количество элементов массива или что-то в объекте',
    'is_array' => 'Определяет, является ли переменная массивом',
    'array_merge' => 'Сливает один или большее количество массивов',
    'empty' => 'Проверяет, пуста ли переменная',
    'print_r' => 'Выводит удобочитаемую информацию о переменной'
);
$thirdArray  = array(
    [1, 1, 1, 1],
    [1, 1, 1, 1],
    [1, 1, 1, 1],
    [1, 1, 1, 1]
);

echo 'a) FirstArray: ', PHP_EOL;
echo implode(" ", $firstArray), PHP_EOL;
echo PHP_EOL, 'b) SecondArray: ', PHP_EOL;
array_walk($secondArray, function ($value, $key) { echo "$key $value", PHP_EOL; });
echo PHP_EOL, 'c) ThirdArray: ', PHP_EOL;
array_walk($thirdArray, function ($value, $key) { echo implode(" ", $value), PHP_EOL; });
