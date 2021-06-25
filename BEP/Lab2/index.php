<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>Лабораторная работа №2.</h1>

        <br/>


        <h1>Основные задания:</h1>

        <br/>


        <h2 style="color: red">1. (#5) Напишите PHP-скрипт print_hello.php, которое выводит сообщение "Hello World!" в формате text/plain.</h2>

        <p><a href="./task1/task1.php">print_hello</a></p>

        <br/>

        <h2 style="color: red">2. (#5) Определите заголовки запроса браузера и ответа сервера при запросе приложения PrintHello.</h2>

        <br/>


        <h2 style="color: red">3. (#5) Разработайте PHP приложение print_hello_html.php.</h2> 
        <h2>Сделайте, чтобы сообщение "Hello HTML World!" выводилось в формате text/html.</h2> 
        <h2>Сообщение должно располагаться внутри HTML тэга H1.</h2>
        <h2>Определите отличие заголовков ответа сервера для программы PrintHelloHTML от PrintHello.</h2>

        <p><a href="./task3/task3.php">print_hello_html</a></p>

        <br/>


        <h2 style="color: red">4. (#5) Напишите PHP приложение print_query_string.php, которое выводит данные переданные в запросе.</h2> 

        <h4>Пример:</h4>

        <p>HTTP 1.1 GET /print_query_string.php?my_name=Sarah&my_surname=Rever&message=British+are+coming+by+sea.</p> 

        <p>Content-Type: text/plain</p>
        <p>Query string = 'my_name=Sarah&my_surname=Rever&message=British+are+coming+by+sea.'</p>

        <p><a href="./task4/task4.php?my_name=Sarah&my_surname=Rever&message=British+are+coming+by+sea">print_query_string</a></p>

        <br/>


        <h2 style="color: red">5. (#10) Напишите PHP приложение print_name.php, которое выводит сообщение "Hello, Dear <Name>!". <Name> заменяется на значение параметра name, переданного в GET запросе.</h2>

        <h4>Пример:</h4>

        <p>HTTP 1.1 GET /print_name.php?name=Sarah</p>

        <p>Content-Type: text/plain</p>
        <p>Hello, Dear Sarah!</p>

        <p><a href="./task5/task5.php?name=Sarah">print_name</a></p>

        <br/>


        <h2 style="color: red">6. (#10) Напишите PHP приложение calc_sum.php, которое вычисляет сумму чисел, переданных в запросе GET. Параметры запроса arg1 и arg2.</h2>
            
        <h4>Например:</h4>
        <p>/calc_sum.php?arg1=10&arg2=15</p>
        <p>25</p>

        <p><a href="./task6/task6.php?arg1=10&arg2=25">calc_sum</a></p>

        <br/>


        <h1>Дополнительные задания:</h1>

        <br/>


        <h2 style="color: red">7. (#5) Внесите следующие доработки в задание 6.: возможность задания математической операции с помощью GET-параметра запроса. Возможные значения: add, sub, mul, div.</h2> 

        <h4>Пример:</h4>
        <p>/calc.php?arg1=10&arg2=15&operation=add</p>

        <h3>a) #5 операция сложение (add):</h3> <p><a href="./task7/task7.php?arg1=10&arg2=25&operation=add">add;</a></p>
        <h3>b) #5 операция вычитание (sub):</h3> <p><a href="./task7/task7.php?arg1=10&arg2=25&operation=sub">sub;</a></p>
        <h3>c) #5 операция умножение (mul):</h3> <p><a href="./task7/task7.php?arg1=10&arg2=25&operation=mul">mul;</a></p>
        <h3>d) #5 операция деление (div):</h3> <p><a href="./task7/task7.php?arg1=10&arg2=25&operation=div">div;</a></p>

        <br/>


        <h2 style="color: red">8. (#20) Доработайте программу из задания 7, добавьте проверку данных, которые пользователь передает через GET-параметры. Информацию о найденной ошибке необходимо отобразить пользователю на странице в формате HTML.</h2> 
        <h2>Должны учитываться следующие случаи:</h2>

        <h3>1. Переданы не все параметры arg1, arg2 и operation:</h3> <p><a href="./task8/task8.php?arg1=10&arg=5">arg1=10&arg=5</a></p>
        <h3>2. Один или несколько параметров имеют некорректные имена (например, arg1, arg2 и op):</h3> <p><a href="./task8/task8.php?arg1=10&a=5&operation=add">arg1=10&a=5&operation=add</a></p>
        <h3>3. Переданы лишние параметры (например, arg1, arg2, operation, name):</h3> <p><a href="./task8/task8.php?arg1=10&arg2=5&operation=add&bad=78">arg1=10&arg2=5&operation=add&bad=78</a></p>
        <h3>4. Параметры arg1 и arg2 содержат данные, отличные от числовых:</h3> <p><a href="./task8/task8.php?arg1=ololo&arg2=5&operation=add">arg1=ololo&arg2=5&operation=add</a></p>
        <h3>5. Параметр operation содержит некорректную операцию:</h3> <p><a href="./task8/task8.php?arg1=10&arg2=5&operation=unknown">arg1=10&arg2=5&operation=unknown</a></p>
        <h3>6. Происходит деление на ноль:</h3> <p><a href="./task8/task8.php?arg1=10&arg2=0&operation=div">arg1=10&arg2=0&operation=div</a></p>

        <br/>


        <p><a href="./task8/task8.php?arg1=10&arg2=5&operation=add">arg1=10&arg2=5&operation=add</a></p>
        <p><a href="./task8/task8.php?arg1=10&arg2=5&operation=sub">arg1=10&arg2=5&operation=sub</a></p>
        <p><a href="./task8/task8.php?arg1=6&arg2=2.5&operation=mul">arg1=6&arg2=2.5&operation=mul</a></p>
        <p><a href="./task8/task8.php?arg1=6.5&arg2=2&operation=div">arg1=6.5&arg2=2&operation=div</a></p>

        <br/>


    </body>
</html>
