from PyQt5.QtGui import QPen, QPainter, QColor

from classes.primitives.i_shape import IShape



class AShape(IShape):
    """
    Abstract base class for shape.

    Args:
        path: QPainterPath
    """

    # private methods =========================================================

    def __init__(self, path):
        self.__path = path
        self.__painter = None
        self.__color = QColor(255, 255, 255, 255)

        self.__pen = QPen()
        self.set_border_width(2)
        self.set_border_color(QColor(0, 255, 0, 255))


    # public methods ==========================================================

    def draw_to(self, canvas):
        """
        Draw path on canvas.

        Args:
            canvas: QWidget
        """
        painter = QPainter(canvas)
        painter.setPen(self.__pen)
        painter.setBrush(self.__color)
        painter.drawPath(self.__path)


    def move_to(self, point):
        # print(point, self.__path.currentPosition())
        point = point - self.__path.currentPosition()
        self.__path.translate(point)


    def is_contain(self, point):
        """
        Is point inside in shape.

        Args:
            point: QPoint
        """
        return self.__path.contains(point)


    def get_bounding_rect(self):
        """
        Return:
            boundecg_rect: QRectF
        """
        return self.__path.controlPointRect()


    def get_parameters(self):
        """
        Childs must implement this method.
        """
        return None, None, None


    def set_color(self, color):
        """
        Set shape inner color.

        Args:
            color: QColor
        """
        self.__color = color


    def set_border_color(self, color):
        """
        Set shape border color.

        Args:
            color: QColor
        """
        self.__pen.setColor(color)


    def set_border_style(self, style):
        """
        Set shape border line style.

        Available styles:
            Qt.SolidLine, Qt.DashLine, Qt.DotLine,
            Qt.DashDotLine, Qt.DashDotDotLine, Qt.CustomDashLine
        """
        self.__pen.setStyle(style)


    def set_border_width(self, width):
        """
        Set shape border line width.

        Args:
            width: int
        """
        self.__pen.setWidth(width)
