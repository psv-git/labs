def get_sides(args):
    if len(args) == 3:
        try:
            a = int(args[0])
            b = int(args[1])
            c = int(args[2])
            if a >= 0 and b >= 0 and c >= 0:
                return a, b, c
        except ValueError:
            pass
    return None, None, None


def is_triangle_exist(a, b, c):
    if a > 0 and b > 0 and c > 0:
        if a + b > c and a + c > b and b + c > a:
            return True
    else:
        return False


def main(args):
    result = "неизвестная ошибка"
    a, b, c = get_sides(args)
    if a is not None:
        if is_triangle_exist(a, b, c):
            if a == b and a == c:
                result = "равносторонний"
            else:
                if a == b or b == c or c == a:
                    result = "равнобедренный"
                else:
                    result = "обычный"
        else:
            result = "не треугольник"
    return result


if __name__ == "__main__":
    import sys
    print(main(sys.argv[1::]))
