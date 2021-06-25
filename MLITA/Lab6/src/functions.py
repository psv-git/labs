# http://comp-science.narod.ru/DL-AR/okulov.htm


def read_file(file):
    lines = file.read().splitlines()
    return lines[0], lines[1]


def string_to_long(str_num, base_power=3):
    lng_num = []
    dig_count = 0
    curr_num = ""
    for i in range(len(str_num)-1, -1, -1):
        dig_count += 1
        curr_num += str_num[i]
        if dig_count == base_power:
            lng_num.append(int(curr_num[::-1]))
            dig_count = 0
            curr_num = ""
    if len(curr_num):
        lng_num.append(int(curr_num[::-1]))
    return lng_num


def long_to_string(lng_num, sign=1, base_power=3):
    if sign < 0: str_num = "-"
    else: str_num = ""
    lng_num_len = len(lng_num)-1
    for i in range(lng_num_len, -1, -1):
        num = str(lng_num[i])
        num_len = len(num)
        if num_len < base_power and i < lng_num_len:
            num = "0" * (base_power - num_len) + num
        str_num += num
    return str_num


def __compare(lng_x, lng_y):
    """
        0: x = y
        1: x > y
        2: x < y
    """
    len_lng_x = len(lng_x)
    len_lng_y = len(lng_y)
    if len_lng_x > len_lng_y: return 1
    if len_lng_x < len_lng_y: return 2
    for i in range(len_lng_x-1, -1, -1):
        if lng_x[i] > lng_y[i]: return 1
        if lng_x[i] < lng_y[i]: return 2
    return 0


def __sub(lng_x, lng_y, base_power):
    for i in range(len(lng_y)):
        lng_x[i] -= lng_y[i]
        for j in range(i+1, len(lng_x)):
            if lng_x[j-1] >= 0: break
            lng_x[j-1] += pow(10, base_power)
            lng_x[j] -= 1
    for i in range(len(lng_x)-1, -1, -1):
        if lng_x[i] == 0: lng_x.pop(i)
        else: break
    return lng_x


def subtract(lng_x, lng_y, base_power=3):
    """
        0,     1: x = y
        answ,  1: x > y
        answ, -1: x < y
    """
    answ = 0
    sign = 1
    c = __compare(lng_x, lng_y)
    if c != 0:
        if c == 1:
            answ = __sub(lng_x, lng_y, base_power)
        if c == 2:
            sign = -1
            answ = __sub(lng_y, lng_x, base_power)
    return sign, answ
