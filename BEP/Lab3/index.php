<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>Лабораторная работа №3.</h1>

        <br/>


        <h1>Основные задания:</h1>

        <br/>


        <h2 style="color: red">1. (#5) Напишите PHP-скрипт print_args.php, выполняющий вывод параметров, переданных в качестве аргументов командной строки, а также их количество.Программа должна корректно обрабатывать ситуацию, когда параметры не были указаны. В этом случае выводится информационное сообщение “No parameters were specified!”.</h2>
        <h2>Внимание! Данная программа запускается из командной строки, а не из браузера.</h2>

        <h4>Пример:</h4>
        <p>php print_args.php Hello World!</p>

        <p>Вывод:</p>
        <p>Number of arguments: 2</p>
        <p>Arguments: Hello World!</p>

        <br/>


        <h2 style="color: red">2. (#5) Разработайте PHP-скрипт print_arrays.php, который выводит информацию о массивах. Выполните вывод информации о массивах в браузер пользователя любым удобным способом. Формат вывода – text/plain.</h2> 
        <h2>Для этого прямо в коде программы создайте и заполните данными 3 массива:</h2>
        <h3>a. Массив с числовым индексом, содержащий первые 10 простых чисел;</h3>
        <h3>b. Ассоциативный массив, содержащий пары название PHP функции - ее описание:</h3>
        <h3>- count;</h3>
        <h3>- is_array;</h3>
        <h3>- array_merge;</h3>
        <h3>- empty;</h3>
        <h3>- print_r</h3>

        <h4>Например:</h4> 
        <p>[‘array_key_exists’ => ‘Проверяет существование элемента массива с указанным индексом’]</p>

        <h3>c. Многомерный массив (массив массивов), описывающий единичную матрицу размером 4x4;</h3>

        <p><a href="./task2/print_arrays.php">print_arrays</a></p>

        <br/>


        <h2 style="color: red">3. (#10) Разработайте PHP-скрипт remove_duplicates.php, который удалит все повторяющиеся символы из переданной строки. Входные данные задаются как аргумент командной строки. В случае, если аргумент не задан, или заданы лишние, программа должна вывести информационное сообщение.</h2>

        <h4>Пример:</h4>

        <p>php remove_duplicates.php Hello World</p>
        <p>Incorrect number of arguments!</p>
        <p>Usage php remove_duplicates.php &lt;string&gt;</p>

        <br/>
        <p>php remove_duplicates.php 'Hello World !!'</p>
        <p>Helo Wrd!</p>

        <br/>


        <h2 style="color: red">4. (#15) Разработайте PHP-скрипт translator.php – переводчик с английского языка на русский. Слово для перевода задается в GET-параметре word. Все переводы хранятся прямо в коде скрипта. Программа должна корректно обрабатывать ситуации, когда параметр word отсутствует, или задан неверно. В этом случае сервер возвращает код ответа 400. В случае, если запрошен перевод неизвестного слова, возвращается код ответа 404.</h2>

        <h4>Пример:</h4>

        <p>/translator.php?word=Keyboard</p>
        <p>Клавиатура</p>

        <p><a href="./task4/translator.php?word=Known">Known</a></p>
        <p><a href="./task4/translator.php?word=Unknown">Unknown</a></p>
        <p><a href="./task4/translator.php?">Missing</a></p>
        <p><a href="./task4/translator.php?word=">Incorrect</a></p>

        <br/>


        <h2 style="color: red">5. (#20) Разработайте PHP-скрипт reverse_array.php, выполняющий реверсирование одномерного массива произвольной длины и вывод результата в браузер пользователя. Входной массив передается как строчный GET-параметр arr. Значения внутри строки отделены символом-разделителем запятой. Программа должна корректно обрабатывать ситуации, когда параметр arr отсутствует, или задан неверно. В этом случае сервер возвращает код ответа 400.</h2>

        <h3>Для получения массива из строки используйте функцию explode.<h3> 
        <h3>Ограничения:<h3>
        <h3>- Нельзя использовать встроенные средства языка такие как: реверс массива или строки;</h3>
        <h3>- Нельзя использовать функцию echo для вывода значения.</h3>

        <h4>Пример:</h4>
        <p>/reverse_array.php?arr=1,2,3,4,5</p>
        <p>Array ( [0] => 5 [1] => 4 [2] => 3 [3] => 2 [4] => 1 )</p>

        <p><a href="./task5/reverse_array.php?arr=1">Correct</a></p>
        <p><a href="./task5/reverse_array.php?arr=1,2,3,4">Correct</a></p>
        <p><a href="./task5/reverse_array.php?arr=1,2,3,4,5">Correct</a></p>
        <p><a href="./task5/reverse_array.php?arr=">Incorrect</a></p>
        <p><a href="./task5/reverse_array.php">Missing</a></p>

        <br/>


        <h1>Дополнительные задания:</h1>

        <br/>


        <h2 style="color: red">6. (#20) Разработайте PHP-скрипт counter.php, выполняющий подсчет вхождений каждого символа во входной строке, передаваемой с помощью GET-параметра string. Программа должна корректно обрабатывать ситуации, когда параметр string отсутствует, или задан неверно. В этом случае сервер возвращает код ответа 400. Регистр символов учитывается: то есть символы H и h являются разными.</h2>

        <h2>Формат вывода данных: символ – количество повторений, каждая пара выводится на новой строке.</h2>

        <h4>Пример:</h4>
        <p>/counter.php?string=Hello World</p>
        
        <p>H – 1</p>
        <p>e – 1</p>
        <p>l  - 3</p>
        <p>o – 2</p>
        <p>W – 1</p>
        <p>r – 1</p>
        <p>d – 1</p>
        <p>" " – 1</p>

        <p><a href="./task6/counter.php?string=Hello World">Correct</a></p>
        <p><a href="./task6/counter.php?string=This is a test string">Correct</a></p>
        <p><a href="./task6/counter.php?string=">Incorrect</a></p>
        <p><a href="./task6/counter.php">Missing</a></p>

        <br/>


        <h2 style="color: red">6.1 (#5) Не учитывать регистр. То есть символы H и h – одно и то же.</h2>

        <p><a href="./task6.1/counter.php?string=Hello World">Correct</a></p>
        <p><a href="./task6.1/counter.php?string=This is a test string">Correct</a></p>
        <p><a href="./task6.1/counter.php?string=">Incorrect</a></p>
        <p><a href="./task6.1/counter.php">Missing</a></p>

        <br/>


        <h2 style="color: red">7. (#40) Разработайте PHP-скрипт bubble_sort.php, реализующий алгоритм «Пузырьковой сортировки». Входные данные задаются в виде GET-параметра numbers. Как следует из его названия, он должен содержать числа, разделенные запятыми (для получения массива из строки, используем функцию explode). В случае, если параметр не был передан, или он содержит хотя бы одно не числовое значение, возвращается код ответа 400.</h2>
        <h2>Формат вывода ответа – строка чисел, разделенных запятыми (используйте функцию implode для получения строки из массива).</h2>

        <h4>Пример:</h4>
        <p>/bubble_sort.php?numbers=10,1,23,18,56,6,3,4,2,1,1</p>
        
        <p>1,1,1,2,3,4,6,10,18,23,56</p>

        <p><a href="./task7/bubble_sort.php?numbers=10,1,23,18,56,6,3,4,2,1,1">Correct</a></p>
        <p><a href="./task7/bubble_sort.php?numbers=10,a,23,18,56,6,3,4,2,1,1">Inorrect</a></p>
        <p><a href="./task7/bubble_sort.php?numbers=">Incorrect</a></p>
        <p><a href="./task7/bubble_sort.php">Missing</a></p>

        <br/>
        

    </body>
</html>
