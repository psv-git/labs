<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>Лабораторная работа №1.</h1>

        <br/>


        <h2 style="color: red">1. (#10) Настройте на своем компьютере web-сервер. Разместите на сервере следующие ресурсы:</h2>

        <p><a href="./index.php">index.php</a></p>
        <p><a href="./images/web_technologies.png">/images/web_technologies.png</a></p>
        <p><a href="./media/Water.mp4">/media/Water.mp4</a></p>

        <h2>Запросите каждый из ресурсов в браузере.</h2>
        <h2>Для каждого ресурса определите следующие HTTP-заголовки при помощи Chrome Developer Tools:</h2>
        <h3>- Content-Type</h3>
        <h3>- Content-Length</h3>
        <h3>- Server</h3>

        <br/>


        <h2 style="color: red">2. (#5 за каждое задание) На сервере были размещены различные ресурсы. В некоторый момент времени ресурсы перестали работать. Требуется выяснить причину, по которой каждый ресурс не работает и зафиксировать в тетради.</h2>

        <p>a. <a href="./lw1/mysql_is_a_database_server.html">mysql_is_a_database_server.html</a> - нет такого файла.</p>
        <p>b. <a href="./lw1/all_begin_from_http.html">all_begin_from_http.html</a> - не установлен charset, ошибка кодировки. Кодировка Chrome по умолчанию ISO-8859-1</p>
        <p>c.<a href="./lw1/nginx_is_fast_http_server.txt">nginx_is_fast_http_server.txt</a> - работает</p>
        <p>d. <a href="./lw1/php_is_a_server_scripting_language.php">php_is_a_server_scripting_language.php</a> - заголовок Location, переадресация на http://fi2.php.net/manual/ru/ </p>
        <p>e. <a href="./lw1/php_is_run_by_web_server.php">php_is_run_by_web_server.php</a> - заголовок Status:502 - Bad Gateway. Сервер получил некорректный ответ от шлюза, к которому он обратился, пытаясь выполнить запрос.</p>
        <p>f. <a href="./lw1/web_is_funny_place.php">web_is_funny_place.php</a> - - заголовок Status:500 - Internal Server Error. Ошибка сервера. Сервер столкнулся с непредвиденными обстоятельствами, которые не позволяют ему выполнить запрос.</p>
        <p>g. <a href="./lw1/javascript_is_a_client_side_language.php?how_to_work=hardly">javascript_is_a_client_side_language.php?how_to_work=hardly</a> - заголовок Status:400 Bad Request - Запрос содержит синтаксическую ошибку и не может быть принят сервером.</p>

        <p>Кириллица 256 символов - 0400(1024)-04FF(1279) </p>

        <p>BOM, порядок байтов</p>
        <p>
            UTF-8:                                       EF BB BF <br>
            UTF-16BE:    Big-endian                      FE FF  <br>
            UTF-16LE:    Little-endian                   FF FE  <br>
            UTF-32BE:    Big-endian                      00 00 FE FF  <br>
            UTF-32LE:    Little-endian                   FF FE 00 00 <br>
        </p>

        <br/>


        <h2 style="color: red">3. (#20) Определите для чего требуется параметр charset у заголовка Content-Type. Что произойдет, если charset будет не задан или будет задан не верно? Для решения этой задачи используйте поисковик Google и доступные в Интернете ресурсы.</h2>

        <p><a href="./lw1/charset.php?charset=utf-8">charset=utf-8</a></p>
        <p><a href="./lw1/charset.php?charset=windows-1251">charset=windows-1251</a></p>
        <p><a href="./lw1/charset.php?charset=">charset=</a></p>

        <br/>


    </body>
</html>
