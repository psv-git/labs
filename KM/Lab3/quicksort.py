# ----------------------- begin of user function --------------------------

# listA: список чисел, |listA| >2
# функция должна переставить элементы местами так, чтобы вернуть список элементов
# такой, что все элементы левее х - меньше х, а все элементы больше х - правее х 
# и при этом затратить минимальное кол-во операций перестановки элементов
# в качестве х выбирается элемент посередине списка (если нечетное кол-во элементов)
# или чуть ближе к началу (если четное).
# Функция возвращает КОЛ-ВО ПЕРЕСТАНОВОК ЭЛЕМЕНТОВ !!!

# --- Эту функцию программирует обучающийся!!! ----

import math
def quick1(listA):
    swapN = 0
    lenList = len(listA)
    if (lenList == 2):
        if (listA[0] < listA[1]):
            swapN += 1
    elif (lenList > 2):
        midInd = int(math.ceil(lenList / 2)) - 1
        min = 0
        max = 0
        for i in range(0, midInd):
            if (listA[i] > listA[midInd]):
                max += 1
        for i in range(midInd + 1, lenList):
            if (listA[i] < listA[midInd]):
                min += 1
        if (min <= max):
            swapN = max
        else:
            swapN = min
    return(swapN)

# ---------------------- end of user fun ---------------------------
