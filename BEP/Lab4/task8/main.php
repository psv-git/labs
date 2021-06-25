<?php
require_once './inc/autoload.inc.php';
header("Content-type: text/plain");
requireFilesFromPath("./inc", ".inc.php");
