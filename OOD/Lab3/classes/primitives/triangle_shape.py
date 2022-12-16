from PyQt5.QtGui import QPainterPath

from classes.primitives.a_shape import AShape



class TriangleShape(AShape):

    # private methods =========================================================

    def __init__(self, first_point, second_point, third_point):
        """
        Args:
            first_point: QPoint
            second_point: QPoint
            third_point: QPoint
        """
        super().__init__()

        self.__figure_type = "TRIANGLE"
        self.__first_point = first_point
        self.__second_point = second_point
        self.__third_point = third_point

        self.__path = QPainterPath()
        self.__path.moveTo(first_point)
        self.__path.lineTo(second_point)
        self.__path.lineTo(third_point)
        self.__path.lineTo(first_point)


    def __get_segment_length(self, first_point, second_point):
            return pow(pow(second_point.x() - first_point.x(), 2) + pow(second_point.y() - first_point.y(), 2), 0.5)


    # public methods ==========================================================

    def draw(self, canvas):
        """
        Draw triangle shape on canvas.

        Args:
            canvas: QWidget
        """
        super().draw(canvas, self.__path)


    def get_parameters(self):
        """
        Return:
            figure_type: str
            perimeter: int
            area: int
        """
        first_seg_len = self.__get_segment_length(self.__first_point, self.__second_point)
        second_seg_len = self.__get_segment_length(self.__second_point, self.__third_point)
        third_seg_len = self.__get_segment_length(self.__third_point, self.__first_point)

        perimeter = first_seg_len + second_seg_len + third_seg_len
        half_perimeter = perimeter / 2
        area = pow(half_perimeter * (half_perimeter - first_seg_len) * (half_perimeter - second_seg_len) * (half_perimeter - third_seg_len), 0.5)

        return self.__figure_type, int(perimeter), int(area)
