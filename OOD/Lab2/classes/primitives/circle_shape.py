from PyQt5.QtGui import QPainterPath

import math
from classes.primitives.a_shape import AShape



class CircleShape(AShape):

    # private methods ==========================================================

    def __init__(self, parent, center_point, radius):
        """
        Class for circle shape.

        Args:
            center_point: QPoint
            radius: int
        """
        self.__figure_type = "CIRCLE"
        self.__radius = radius

        path = QPainterPath()
        path.addEllipse(center_point, radius, radius)
        super().__init__(parent, path)


    # public methods ===========================================================

    def get_parameters(self):
        """
        Return:
            perimeter: int
            area: int
        """
        perimeter = math.pi * 2 * self.__radius
        area = pow(math.pi * self.__radius, 2) / 2

        return self.__figure_type, int(perimeter), int(area)
