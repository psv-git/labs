# https://e-maxx.ru/algo/oriented_area


class Point:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "({0}, {1})".format(self.x, self.y)

    def __eq__(self, point):
        return self.x == point.x and self.y == point.y



class Segment:

    def __init__(self, op, cl):
        self.op = op
        self.cl = cl

    def __str__(self):
        return "({0}, {1})".format(self.op, self.cl)

    def get_min_max_x(self):
        return min(self.op.x, self.cl.x), max(self.op.x, self.cl.x)

    def get_min_max_y(self):
        return min(self.op.y, self.cl.y), max(self.op.y, self.cl.y)



def read_file(file):
    S_1_1 = file.readline().split()
    S_1_2 = file.readline().split()
    S_2_1 = file.readline().split()
    S_2_2 = file.readline().split()
    return Segment(Point(int(S_1_1[0]), int(S_1_1[1])), Point(int(S_1_2[0]), int(S_1_2[1]))), Segment(Point(int(S_2_1[0]), int(S_2_1[1])), Point(int(S_2_2[0]), int(S_2_2[1])))



def is_bound(seg_1, seg_2):
    min_x_1, max_x_1 = seg_1.get_min_max_x()
    min_y_1, max_y_1 = seg_1.get_min_max_y()
    min_x_2, max_x_2 = seg_2.get_min_max_x()
    min_y_2, max_y_2 = seg_2.get_min_max_y()

    if min_x_2 < min_x_1 and min_x_1 < max_x_2:
        if min_y_2 < min_y_1 and min_y_1 < max_y_2:
            return True
        if min_y_2 < max_y_1 and max_y_1 < max_y_2:
            return True
    if min_x_2 < max_x_1 and max_x_1 < max_x_2:
        if min_y_2 < min_y_1 and min_y_1 < max_y_2:
            return True
        if min_y_2 < max_y_1 and max_y_1 < max_y_2:
            return True

    return False



def signed_double_triangle_area(seg, p):
    return (seg.cl.x-seg.op.x)*(p.y-seg.op.y)-(seg.cl.y-seg.op.y)*(p.x-seg.op.x)
