from PyQt5.QtGui import QPainterPath

from classes.primitives.a_shape import AShape
from functions.functions import get_segment_length



class TriangleShape(AShape):

    # private methods =========================================================

    def __init__(self, parent, first_point, second_point, third_point):
        """
        Args:
            first_point: QPoint
            second_point: QPoint
            third_point: QPoint
        """
        self.__figure_type = "TRIANGLE"
        self.__first_point = first_point
        self.__second_point = second_point
        self.__third_point = third_point

        path = QPainterPath()
        path.moveTo(first_point)
        path.lineTo(second_point)
        path.lineTo(third_point)
        path.lineTo(first_point)
        super().__init__(parent, path)


    # public methods ==========================================================

    def get_parameters(self):
        """
        Return:
            figure_type: str
            perimeter: int
            area: int
        """
        first_seg_len = get_segment_length(self.__first_point, self.__second_point)
        second_seg_len = get_segment_length(self.__second_point, self.__third_point)
        third_seg_len = get_segment_length(self.__third_point, self.__first_point)

        perimeter = first_seg_len + second_seg_len + third_seg_len
        half_perimeter = perimeter / 2
        area = pow(half_perimeter * (half_perimeter - first_seg_len) * (half_perimeter - second_seg_len) * (half_perimeter - third_seg_len), 0.5)

        return self.__figure_type, int(perimeter), int(area)
