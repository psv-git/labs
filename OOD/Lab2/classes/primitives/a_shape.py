from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPen, QPainter, QColor, QPainterPath

from configs import app_config as cnf



class AShape:
    """
    Abstract base class for shape.
    Args:
        parent: parent node
        path: QPainterPath
    """

    # private methods ==========================================================

    def __init__(self, parent, path):
        self.is_empty = False
        self.is_active = False
        self.is_blocked = False

        self._parent = parent
        self._path = path
        self._last_pos = path.currentPosition()

        self._color = QColor(255, 255, 255, 255) # shape background
        self._border_color = QColor(0, 255, 0, 255) # shape borders
        self._bb_color = QColor(0, 0, 0, 0) # bounding box background
        self._bbl_color = QColor(0, 0, 255, 255) # bounding box borders

        self.__pen = QPen()
        self.__pen.setWidth(2) # border width

        self._update_bounding_box()


    def _update_bounding_box(self):
        self._bounding_box_path = QPainterPath()
        self._bounding_box_path.moveTo(self.bounding_rect().topLeft())
        self._bounding_box_path.lineTo(self.bounding_rect().topRight())
        self._bounding_box_path.lineTo(self.bounding_rect().bottomRight())
        self._bounding_box_path.lineTo(self.bounding_rect().bottomLeft())
        self._bounding_box_path.lineTo(self.bounding_rect().topLeft())

        self._bounding_box_path.addEllipse(self.bounding_rect().topLeft(), 3, 3)
        self._bounding_box_path.addEllipse(self.bounding_rect().topRight(), 3, 3)
        self._bounding_box_path.addEllipse(self.bounding_rect().bottomRight(), 3, 3)
        self._bounding_box_path.addEllipse(self.bounding_rect().bottomLeft(), 3, 3)


    def _draw_to(self, canvas):
        """
        Draw path on canvas.
        Args:
            canvas: QWidget
        """
        painter = QPainter(canvas)
        self.__pen.setColor(self._border_color)
        painter.setPen(self.__pen)
        painter.setBrush(self._color)
        painter.drawPath(self._path)
        if self.is_active:
            self.__pen.setColor(self._bbl_color)
            painter.setPen(self.__pen)
            painter.setBrush(self._bb_color)
            painter.drawPath(self._bounding_box_path)


    def _move_to(self, cursor_pos):
        dp = cursor_pos - self._last_pos
        print(dp)
        self._path.translate(dp)
        self._last_pos = cursor_pos
        self._update_bounding_box()

    # event methods ============================================================

    def on_click(self, cursor_pos, keyboard_modifier):
        """
        On click method.
        Args:
            point: QPoint
        """
        # self._last_pos = cursor_pos

        if self.is_blocked:
            return
        
        on_focus = self.is_contain(cursor_pos)
        if on_focus:
            self.is_active = True
            self._last_pos = cursor_pos
        else:
            if keyboard_modifier != cnf.SHIFT_MODIFIER:
                self.is_active = False


    def on_drag(self, cursor_pos):
        """
        On drag method.
        Args:
            point: QPoint
        """
        if self.is_blocked:
            return

        if self.is_active:
            self.move_to(cursor_pos)

    # public methods ===========================================================

    def get_id(self):
        return id(self)


    def bounding_rect(self):
        """
        Return:
            boundecg_rect: QRectF
        """
        return self._path.controlPointRect()


    def add_shape(self, shape):
        return None


    def remove_shape(self, shape):
        return None


    def get_nested_shapes(self):
        return None


    def draw_to(self, canvas):
        self._draw_to(canvas)


    def move_to(self, cursor_pos):
        self._move_to(cursor_pos)


    def is_contain(self, point):
        """
        Is point inside in shape.
        Args:
            point: QPoint
        """
        return self._path.contains(point)


    def set_blocked(self, blocked):
        self.is_active = False
        self.is_blocked = blocked

    # style ====================================================================

    # def set_border_style(self, style):
    #     """
    #     Set shape border line style.
    #     Available styles:
    #         Qt.SolidLine, Qt.DashLine, Qt.DotLine,
    #         Qt.DashDotLine, Qt.DashDotDotLine, Qt.CustomDashLine
    #     """
    #     self.__pen.setStyle(style)

    # ==========================================================================

    def get_parameters(self):
        raise NotImplementedError()
