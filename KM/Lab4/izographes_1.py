# Имеется орграф с n вершинами, который можно закодировать перестановкой (1,2,3,...,n), т.е. все вершины данного графа имеют полустепени захода и выхода, равными 1. Он задан матрицей смежности.

# Для матрицы смежности, которая описывает другой подобный граф, необходимо проверить являются ли изоморфными данные графы. Вам надо написать: 
# 1) функцию graph_permutation(GM), которая на вход берет матрицу смежности GM - таблицу (numpy array), проверяет корректность задания орграфа (является ли он перестановочным) и строит перестановку, описывающую граф. На выходе функция должна возвращать перестановку - GP - вектор numpy.array(k1, k2, ,,,, kn) , где ki - номер вершины, в которую входит дуга из вершины i или False, если граф не описывается перестановкой.
# 2) функцию graph_cycl_formula(GP), которая на вход берет перестановку - вектор numpy.array(k1, k2, ,,,, kn) и возвращает его циклическую формулу  CF, в виде списка списков: [[N1, ,,, Nm], [Nm+1, ... Nm+l], ...], где [N1, ,,, Nm] - цикл длины m.

# Пример:
# GM_1 = np.array([[0,1,0], [1,0,0], [0,0,1]])
# GP1 = graph_permutation(GM_1)
# print(GP1)
# [2 1 3]
# CF_1 = mygraph_cycl_formula(GP1)
# print(CF_1)
# [[1, 2], [3]]

import numpy as np

def graph_permutation(GM):
    GP = np.array(range(1, GM.shape[0] + 1))
    for ln in range(GM.shape[0]):
        transCount = 0 #количество перестановок
        for col in range(GM.shape[1]):
            if (GM[ln][col] == 1):
                GP[ln] = col + 1
                transCount += 1
        if (transCount != 1): #если перестановок <>1
            GP = False
            break
    res = GP
    return(res)


def graph_cycl_formula(GP):
    CF = []
    tmp = [] #массив для формирования вывода
    skip = [] #массив для пропускаемых индексов
    for ind in range(GP.shape[0]):
        if (skip.count(ind+1) > 0):
            continue
        nxt = GP[ind]
        if (ind+1 == nxt):
            CF.append([nxt])
        else:
            tmp.append(ind+1)
            while (ind+1 != nxt):
                skip.append(nxt)
                tmp.append(nxt)
                nxt = GP[nxt-1]
            CF.append(tmp.copy())
            tmp.clear()
    return(CF)
