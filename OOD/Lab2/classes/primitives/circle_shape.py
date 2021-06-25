import math
from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPainterPath

from classes.primitives.a_shape import AShape



class CircleShape(AShape):
    """
    Circle shape class.

    Args:
        center_point: QPoint
        radius: int
    """

    # private methods =========================================================

    def __init__(self, center_point, radius):
        self.__figure_type = "CIRCLE"
        self.__center_point = center_point
        self.__radius = radius

        path = QPainterPath()
        path.addEllipse(center_point, radius, radius)

        super().__init__(path)


    # public methods ==========================================================

    def get_parameters(self):
        """
        Return:
            perimeter: int
            area: int
        """
        perimeter = math.pi * 2 * self.__radius
        area = pow(math.pi * self.__radius, 2) / 2

        return self.__figure_type, int(perimeter), int(area)
