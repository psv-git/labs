<!DOCTYPE html> 
<html>
    <head>
        <?php 
        $charset = $_GET['charset'];
        header('Content-type: text/html; charset=' . $charset);
        ?>
        <title>Кодировка HTML-страницы</title>
    </head> 
    <body>
        <h1>Кодировка</h1> 
        <p>Когда кодировка документа задана неверно, некоторые символы отображаются как «иероглифы», а некоторые нет.</p> 
    </body>
</html> 
