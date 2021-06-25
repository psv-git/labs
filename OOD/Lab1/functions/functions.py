

def get_segment_length(first_point, second_point):
        return pow(pow(second_point.x() - first_point.x(), 2) + pow(second_point.y() - first_point.y(), 2), 0.5)
