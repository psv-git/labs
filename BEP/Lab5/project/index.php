<?php
require_once './vendor/autoload.php';
Twig_Autoloader::register();

$loader = new Twig_Loader_Filesystem('./templates');
$twig = new Twig_Environment($loader, array('auto_reload' => true));

$page_title = "Page Title";
$site_title = "SITE TITLE";
$books = array(
    array('num' => '1', 'title' => 'PHP 7 в подлиннике'),
    array('num' => '2', 'title' => 'Java 9 Programming Blueprints'),
    array('num' => '3', 'title' => 'Mastering Java 9'),
    array('num' => '4', 'title' => 'Java 9 Concurrency Cookbook'),
    array('num' => '5', 'title' => 'Distributed Computing in Java 9'),
    array('num' => '6', 'title' => 'Java1. Basic syntax and semantics'),
    array('num' => '7', 'title' => 'Software Architecture with Python'),
    array('num' => '8', 'title' => 'Reactive Java 9'),
    array('num' => '9', 'title' => 'Getting Started with Clean Code Java SE 9')
);

echo $twig->render('top.html', array('page_title' => $page_title, 'site_title' => $site_title));
echo $twig->render('menu.html');
echo $twig->render('book.html', array('books' => $books));
echo $twig->render('sidebar.html');
echo $twig->render('footer.html');
?>
