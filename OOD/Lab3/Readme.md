# Лабораторная работа №3.

### Задание:  
Разработать программный проект, выполняющий визуализацию и простейшие операции (расчет площади и периметра) для геометрических фигур - треугольника, прямоугольника, окружности. Иерархия разрабатываемых классов должна реализовывать шаблон проектирования декоратор  над классами CircleShape, RectangleShape и ConvexShape.  

Выполнить рефакторинг лабораторной работы №1, используя паттерны «Фабричный метод» и Синглтон (Для каждого типа фигур создать свой класс- Creator, каждый из которых является Синглтоном).  

### Входные и выходные данные: текстовые файлы.  

#### Пример входных данных: input.txt  
TRIANGLE: P1=100,100; P2=200,200; P3:150,150  
RECTANGLE: P1=200,200; P2=300,300  
CIRCLE: C=100,100; R=50  

#### Пример результата: output.txt  
TRIANGLE: P=400; S=600  
RECTANGLE: P=200; S=800  
CIRCLE: P=300; S=500  

### Приложение:  
Консольное, должно включать классы, выполняющие расчет, и исполняемый модуль.  

### Примечание:  
Целью лабораторной работы не является задача синтаксического разбора текстового файла.  
Считается, что файл «правильный», т.е. не содержит опечаток в словах TRIANGLE, RECTANGLE, CIRCLE, лишних пробелов и символов.  
Стороны прямоугольника параллельны осям абсцисс и ординат, прямоугольник задается точками, стоящими по диагонали.  
Координаты являются целыми числами.  
Однако количество фигур в файле может быть любым, строки, задающие фигуры, могут стоять в любом порядке.  

## python ./main.py /data/input1 /data/output