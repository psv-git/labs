<?php
// устанавливаем свой обработчик ошибок
set_error_handler("myErrorHandler");

// получаем и проверяем параметры запроса
checkParametresCount();
$arg1Value = getArgumentValue('arg1');
$arg2Value = getArgumentValue('arg2');
$operation = getOperation();

// выбираем операцию
echo calculate($arg1Value, $arg2Value, $operation);

// FUNCTIONS ================================================================

function checkParametresCount()
{
    if (count($_GET) != 3) {
        trigger_error("<b style=\"color: red\">Bad parameters count.</b>", E_USER_ERROR);
    }
}

function getArgumentValue($argNumber)
{
    if (!isset($_GET[$argNumber])) {
        trigger_error("<b style=\"color: red\">$argNumber not found.</b>", E_USER_ERROR);
    } else {
        $argumentValue = $_GET[$argNumber];
        if (!is_numeric($argumentValue)) {
            trigger_error("<b style=\"color: red\">$argumentValue not a number.</b>", E_USER_ERROR);
        }
        return floatval($argumentValue);
    }
}

function getOperation()
{
    if (!isset($_GET['operation'])) {
        trigger_error("<b style=\"color: red\">Operation not found.</b>", E_USER_ERROR);
    } else {
        $operation = $_GET['operation'];
        if ($operation != 'add' && $operation != 'sub' && $operation != 'mul' && $operation != 'div') {
            trigger_error("<b style=\"color: red\">Undefined operation.</b>", E_USER_ERROR);
        }
        return $operation;
    }
}

function add($val1, $val2)
{
    return $val1 + $val2;
}

function sub($val1, $val2)
{
    return $val1 - $val2;
}

function mul($val1, $val2)
{
    return $val1 * $val2;
}

function div($val1, $val2)
{
    if ($val2 == 0) {
        trigger_error("<b style=\"color: red\">Division by zero.</b>", E_USER_ERROR);
        return;
    }
    return $val1 / $val2;
}

function calculate($arg1, $arg2, $op)
{
    $res = 0;
    switch ($op) {
    case "add":
        $res = add($arg1, $arg2);
        break;
    case "sub":
        $res = sub($arg1, $arg2);
        break;
    case "mul":
        $res = mul($arg1, $arg2);
        break;
    case "div":
        $res = div($arg1, $arg2);
        break;
    default:
        break;
    }
    return $res;
}

function myErrorHandler($errno, $errstr, $errfile, $errline)
{
    if (!(error_reporting() & $errno)) {
        // Этот код ошибки не включен в error_reporting,
        // так что пусть обрабатываются стандартным обработчиком ошибок PHP
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
    // Не запускаем внутренний обработчик ошибок PHP
    return true;
}
