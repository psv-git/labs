from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPainterPath

import math
from classes.primitives.a_shape import AShape



class CircleShape(AShape):

    # private methods =========================================================

    def __init__(self, center_point, radius):
        """
        Class for circle shape.

        Args:
            center_point: QPoint
            radius: int
        """
        super().__init__()

        self.__figure_type = "CIRCLE"
        self.__radius = radius

        self.__path = QPainterPath()
        self.__path.addEllipse(center_point, radius, radius)


    # public methods ==========================================================

    def draw(self, canvas):
        """
        Draw circle shape on canvas.

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
        perimeter = math.pi * 2 * self.__radius
        area = pow(math.pi * self.__radius, 2) / 2

        return self.__figure_type, int(perimeter), int(area)
