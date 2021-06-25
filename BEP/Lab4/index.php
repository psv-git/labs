<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    <h1>Лабораторная работа №4.</h1>

    <br/>


    <h1>Основные задания:</h1>

    <br/>


    <h2 style="color: red">1. (#5) Создайте в проекте директорию include. В этой директории создайте файлы common.inc.php, string.inc.php, request.inc.php. Подключите файлы string.inc.php и request.inc.php в файле common.inc.php.</h2>

    <br/>


    <h2 style="color: red">2. (#10) Разработайте функцию last($str). Функция last принимает строку символов и возвращает лишь последний символ из этой строки. Функция должна размещаться в файле string.inc.php. Для проверки функции разработайте программу /last.php. В GET-параметре str передается значение исходной  строки. Необходимо учесть, что 1) параметр может быть не передан, 2) строка может быть пустой.</h2> 

    <p><a href="./task2/last.php?str=hello">last 'hello'</a></p>
    <p><a href="./task2/last.php?str=">last empty</a></p>
    <p><a href="./task2/last.php?">last missing</a></p>

    <br/>


    <h2 style="color: red">3. (#10) Разработайте функцию withoutLast($str). Функция withoutLast принимает строку и возвращает ту же самую строку без последнего символа. Функция должна размещаться в файле string.inc.php. Для проверки функции разработайте программу without_last.php</h2>

    <p><a href="./task3/without_last.php?str=hello">without_last 'hello'</a></p>
    <p><a href="./task3/without_last.php?str=">without_last empty</a></p>
    <p><a href="./task3/without_last.php?">without_last missing</a></p>

    <br/>


    <h2 style="color: red">4. (#10) Разработайте функцию revers($str). Функция принимает строку в качестве параметра. Возвращает строку, состоящую из тех же символов, что и исходная строка, но символы идут в обратном порядке. Для решения этой задачи не используйте встроенные в язык PHP функции работы со строками (такие как reverse например). Для проверки функции разработайте программу reverse.php</h2>

    <p><a href="./task4/reverse.php?str=hello">reverse 'hello'</a></p>
    <p><a href="./task4/reverse.php?str=">reverse empty</a></p>
    <p><a href="./task4/reverse.php?">reverse missing</a></p>

    <br/>


    <h2 style="color: red">5. (#10) Разработайте PHP приложение check_identifier.php, которое проверят является ли переданный в GET параметр identifier индетификатором по правилу SR3. Программа должна выводить yes или no, а также поясняющую информацию в том случае, если передананя строка не является идентификатором. Задание должно быть выполнено без использования регулярных выражений.</h2>

    <p><a href="./task5/check_identifier.php?arg=_ident1">correct</a></p>
    <p><a href="./task5/check_identifier.php?arg=ident2">correct</a></p>
    <p><a href="./task5/check_identifier.php?arg=ident_3">correct</a></p>
    <p><a href="./task5/check_identifier.php?arg=4ident">incorrect</a></p>
    <p><a href="./task5/check_identifier.php?arg=">incorrect</a></p>
    <p><a href="./task5/check_identifier.php?">incorrect</a></p>

    <br/>


    <h1>Дополнительные задания:</h1>

    <br/>


    <h2 style="color: red">6. (#20) Разработайте приложение remove_extra_blanks.php. В запросе GET передается параметр text. Скрипт выводит в стандартный поток вывода этот же текст без лишних пробелов. Результирующая строка не должна содержать пробелов в начале и в конце строки. Внутри строки не может быть более одного пробела подряд.</h2>

    <p><a href="./task6/remove_extra_blanks.php?text=       Hello           World Hello World             ">correct</a></p>
    <p><a href="./task6/remove_extra_blanks.php?text=">empty</a></p>
    <p><a href="./task6/remove_extra_blanks.php?">incorrect</a></p>

    <br/>


    <h2 style="color: red">7. (#30) Разработайте программу для проверки надежности пароля password_strength.php. В GET параметре password передается пароль для анализа. Пароль может состоять только из английских символов в верхнем и нижнем регистрах, а также из цифр.</h2>
    
    <h3>Надежность пароля вычисляется по следующему принципу</h3>
    <p>1) Изначально считаем надежность равной 0.</p>
    <p>2) К надежности прибавляется (4*n), где n - количество всех симоволов пароля</p>
    <p>3) К надежности прибавляется +(n*4), где n - количество цифр в пароле</p>
    <p>4) К надежности прибавляется +((len-n)*2) в случае, если пароль содержит n символов в верхнем регистре</p>
    <p>5) К надежности прибавляется +((len-n)*2) в случае, если пароль содержит n символов в нижнем регистре</p>
    <p>6) Если пароль состоит только из букв вычитаем число равное количеству символов.</p>
    <p>7) Если пароль состоит только из цифр вычитаем число равное количеству символов.</p>
    <p>8) За каждый повторяющийся символ в пароле вычитается количество повторяющихся символов</p>
      <p>Например: abcd1a </p>
      <p>вычитаем -2 поскольку символ a встречается дважды.</p>

    <h3>Программа должна выводить на экран надежность пароля в виде числа.</h3>

    <p><a href="./task7/password_strength.php?password=a1D23D3efg">correct</a></p>
    <p><a href="./task7/password_strength.php?password=abaD">correct</a></p>
    <p><a href="./task7/password_strength.php?password=1234">correct</a></p>
    <p><a href="./task7/password_strength.php?password=">incorrect</a></p>
    <p><a href="./task7/password_strength.php?">incorrect</a></p>

    <br/>


    <h2 style="color: red">8. (#30) Необходимо разработать небольшой проект, состоящий из главного PHP файла, являющегося точкой входа в приложение, директории inc, где лежит произвольный набор подключаемых файлов и скрипта-автозагрузчика. Каждый из подключаемых файлов директории inc содержит обычный вывод с помощью функции echo.</h2>

    <h3>Пример структуры проекта:</h3>

    <p>inc</p>
    <p>| |_  autoload.inc.php</p>
    <p>| |_  hello.inc.php           - echo “Hello”;</p>
    <p>| |_  world.inc.php          - echo “World”;<p>
    <p>|</p>
    <p>|_ main.php</p>

    <h3>При добавлении новых PHP-файлов в директорию .inc происходит их автоматическое подключение, что можно проверить, запустив скрипт main.php. В приведенном выше примере будет выведена строка “HelloWorld.</h3>

    <p><a href="./task8/main.php">main.php</a></p>

    <br/>

  </body>
</html>
