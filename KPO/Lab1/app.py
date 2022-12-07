import sys


# print(sys.float_info)
INF = float("inf")
F_MIN = sys.float_info.min
F_MAX = sys.float_info.max


def get_sides(args):
    if len(args) != 3:
        raise Exception(f"Bad args count: {len(args)}")
    a = float(args[0])
    b = float(args[1])
    c = float(args[2])
    # print(a, b, c)
    if a >= 0 and b >= 0 and c >= 0:
        if a >= F_MIN and b >= F_MIN and c >= F_MIN:
            if a <= F_MAX and b <= F_MAX and c <= F_MAX:
                return a, b, c
            else: raise Exception("Some args value bigger than max.")
        else: raise Exception("Some args value lesser than min.")
    else: raise Exception("Some args is negative")


def is_triangle(a, b, c):
    s1 = a + b
    s2 = a + c
    s3 = b + c
    if s1 != INF and s2 != INF and s3 != INF:
        if s1 <= F_MAX and s2 <= F_MAX and s3 <= F_MAX:
            if s1 > c and s2 > b and s3 > a:
                return True
            else:
                return False
        else: raise Exception("Sum max overflow")
    else:
        raise Exception("Sum max overflow (inf)")


def main(args):
    result = "неизвестная ошибка"
    try:
        a, b, c = get_sides(args)
        if is_triangle(a, b, c):
            if a == b and a == c:
                result = "равносторонний"
            else:
                if a == b or b == c or c == a:
                    result = "равнобедренный"
                else:
                    result = "обычный"
        else:
            result = "не треугольник"
    except Exception as e:
        # print(e)
        pass
    return result




if __name__ == "__main__":
    print(main(sys.argv[1::]))
