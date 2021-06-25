#! /usr/bin/python3.5

# Данный файл создают обучающиеся.
# Программа в данном файле должна выполнять задание практикума
# и должна начинаться со ввода переменной nn

# Для заданного (преподавателем) значения переменной nn необходимо:
# - вывести все целые числа от 0 до n-1, если n<10
# - вывести текст "used numbers= 0, 1, 2, 3, ..., n-1", если 10≤n<20
# - вывести текст "very big number", если n>=20

nn = int(input())
if (nn < 10):
  for i in range(0, nn):
    print(i)
elif (nn < 20):
  print ("used numbers=", end = ' ')
  for i in range(0, nn):
    if (i != nn-1):
      print(i, end=', ')
    else:
      print(i)
else:
  print("very big number")
