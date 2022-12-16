from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPainterPath

from classes.primitives.a_shape import AShape



class RectangleShape(AShape):

    # private methods =========================================================

    def __init__(self, top_left_point, bottom_right_point):
        """
        Args:
            top_left_point: QPoint
            bottom_right_point: QPoint
        """
        super().__init__()

        self.__figure_type = "RECTANGLE"
        self.__top_left_point = top_left_point
        self.__bottom_right_point = bottom_right_point

        self.__path = QPainterPath()
        self.__path.moveTo(top_left_point)
        self.__path.lineTo(QPoint(bottom_right_point.x(), top_left_point.y()))
        self.__path.lineTo(bottom_right_point)
        self.__path.lineTo(QPoint(top_left_point.x(), bottom_right_point.y()))
        self.__path.lineTo(top_left_point)


    # public methods ==========================================================

    def draw(self, canvas):
        """
        Draw rectangle shape on canvas.

        Args:
            canvas: QWidget
        """
        super().draw(canvas, self.__path)


    def get_parameters(self):
        """
        Return:
            perimeter: int
            area: int
        """
        width = abs(self.__bottom_right_point.x() - self.__top_left_point.x())
        height = abs(self.__top_left_point.y() - self.__bottom_right_point.y())

        perimeter = (width + height) * 2
        area = width * height

        return self.__figure_type, int(perimeter), int(area)
