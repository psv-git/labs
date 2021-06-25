<?php
if (isset($_SERVER['QUERY_STRING'])) {
    $query = $_SERVER['QUERY_STRING'];
    parse_str($query, $args);
    switch ($args['operation']) {
        case "add":
            echo add(floatval($args['arg1']), floatval($args['arg2']));
            break;
        case "sub":
            echo sub(floatval($args['arg1']), floatval($args['arg2']));
            break;
        case "mul":
            echo mul(floatval($args['arg1']), floatval($args['arg2']));
            break;
        case "div":
            echo div(floatval($args['arg1']), floatval($args['arg2']));
            break;
        default:
            break;
    }
}

function add($arg1, $arg2)
{
    return $arg1 + $arg2;
}

function sub($arg1, $arg2)
{
    return $arg1 - $arg2;
}

function mul($arg1, $arg2)
{
    return $arg1 * $arg2;
}

function div($arg1, $arg2)
{
    return $arg1 / $arg2;
}
