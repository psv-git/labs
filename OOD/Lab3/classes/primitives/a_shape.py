from PyQt5.QtGui import QPen, QPainter, QColor



class AShape:

    # private methods =========================================================

    def __init__(self):
        """
        Base class for shape.
        """
        self.__painter = None
        self.__color = QColor(0, 0, 0, 0)

        self.__pen = QPen()
        self.__pen.setColor(QColor(255, 255, 255, 255))


    # public methods ==========================================================

    def draw(self, canvas, path):
        """
        Draw path on canvas.

        Args:
            canvas: QWidget
            path: QPainterPath
        """
        painter = QPainter(canvas)
        painter.setPen(self.__pen)
        painter.setBrush(self.__color)
        painter.drawPath(path)


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
        self.__pen.pen.setWidth(width)


    def get_parameters(self):
        return
