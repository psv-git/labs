def is_even(number):
    if number % 2 == 0: 
        return True
    return False


def read_file(file):
    line = file.read()
    pair = [int(s) for s in line.split() if s.isdigit()]
    return pair[0], pair[1]
