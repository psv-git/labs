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
        self._parent = parent
        self._path = path
        self._last_pos = path.currentPosition()

        self._color = QColor(255, 255, 255, 255) # shape background
        self._border_color = QColor(0, 255, 0, 255) # shape borders
        self._bb_color = QColor(0, 0, 0, 0) # bounding box background
        self._bbl_color = QColor(0, 0, 255, 255) # bounding box borders

        self.__is_active = False
        self.__is_blocked = False

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
        if self.is_active():
            self.__pen.setColor(self._bbl_color)
            painter.setPen(self.__pen)
            painter.setBrush(self._bb_color)
            painter.drawPath(self._bounding_box_path)


    def _move_to(self, cursor_pos):
        dp = cursor_pos - self._last_pos
        self._path.translate(dp)
        self._last_pos = cursor_pos
        self._update_bounding_box()


    def _is_contain(self, point, path):
        """
        Is point inside in shape.
        Args:
            point: QPoint
        """
        return path.contains(point)


    def _on_click(self, cursor_pos, keyboard_modifier, path=None):
        """
        On click method.
        Args:
            point: QPoint
        """
        if self.is_blocked():
            return

        path = path or self._path
        on_focus = self._is_contain(cursor_pos, path)
        if on_focus:
            self.is_active(True)
            self._last_pos = cursor_pos
        else:
            if keyboard_modifier != cnf.SHIFT_MODIFIER:
                self.is_active(False)

    # event methods ============================================================

    def on_click(self, cursor_pos, keyboard_modifier):
        """
        On click method.
        Args:
            point: QPoint
        """
        self._on_click(cursor_pos, keyboard_modifier)


    def on_drag(self, cursor_pos):
        """
        On drag method.
        Args:
            point: QPoint
        """
        if self.is_blocked():
            return

        if self.is_active():
            self.move_to(cursor_pos)

    # public methods ===========================================================

    def is_active(self, val=None):
        if val is not None:
            self.__is_active = val
        return self.__is_active


    def is_blocked(self, val=None):
        if val is not None:
            self.__is_blocked = val
        return self.__is_blocked


    def is_empty(self):
        return False


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


    def get_parameters(self):
        raise NotImplementedError()
