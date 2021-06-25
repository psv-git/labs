def read_file(file):
    line = file.read()
    pair = [int(s) for s in line.split() if s.isdigit()]
    return pair[0], pair[1]


def get_digit_count(X):
    dc = 0
    while X > 0:
        dc += 1
        X = X // 10
    return dc


def f(X, N):
    val = 0
    digit_count = get_digit_count(X)    # digits count in this number
    next_number = pow(10, digit_count)  # first number for digit_count+1 range
    if next_number == N:
        range_count = next_number - X   # numbers count in this range
        val += get_digit_count(N)
    elif next_number > N:
        next_number = N
        range_count = next_number - (X-1)
    else:
        range_count = next_number - X
    val += digit_count * range_count

    return next_number, val
