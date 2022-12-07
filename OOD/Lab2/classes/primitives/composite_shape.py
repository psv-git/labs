from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPainterPath, QColor

from classes.primitives.a_shape import AShape



class CompositeShape(AShape):

    # private methods ==========================================================

    def __init__(self, parent, shape, *shapes):
        self.__nested_shapes = {}
        self.add_shape(shape)
        for sh in shapes:
            self.add_shape(sh)

        path = self.__update_path(shape)
        super().__init__(parent, path)

        self._color = QColor(0, 0, 0, 0) # shape background
        self._border_color = QColor(0, 0, 0, 0) # shape borders
        self._bb_color = QColor(0, 0, 0, 0) # bounding box background
        self._bbl_color = QColor(0, 0, 255, 255) # bounding box borders


    def __update_path(self, shape=None):
        min_x, max_x, min_y, max_y = None, None, None, None

        if shape is not None:
            min_x = shape.bounding_rect().topLeft().x()
            max_x = shape.bounding_rect().topRight().x()
            min_y = shape.bounding_rect().topLeft().y()
            max_y = shape.bounding_rect().bottomLeft().y()
        else:
            min_x = self.bounding_rect().topLeft().x()
            max_x = self.bounding_rect().topRight().x()
            min_y = self.bounding_rect().topLeft().y()
            max_y = self.bounding_rect().bottomLeft().y()

        for sh in self.__nested_shapes.values():
            minx = sh.bounding_rect().topLeft().x()
            maxx = sh.bounding_rect().topRight().x()
            miny = sh.bounding_rect().topLeft().y()
            maxy = sh.bounding_rect().bottomLeft().y()

            if minx < min_x: min_x = minx
            if maxx > max_x: max_x = maxx
            if miny < min_y: min_y = miny
            if maxy > max_y: max_y = maxy

        path = QPainterPath()
        path.moveTo(min_x, min_y)
        path.lineTo(max_x, min_y)
        path.lineTo(max_x, max_y)
        path.lineTo(min_x, max_y)
        path.lineTo(min_x, min_y)
        return path


    # public methods ===========================================================

    def add_shape(self, shape):
        shape._parent = self
        shape.set_blocked(True)
        self.__nested_shapes[shape.get_id()] = shape
        self._path = self.__update_path(shape)
        self._update_bounding_box()
        return shape


    def remove_shape(self, shape):
        if not self.is_empty:
            shape._parent = self._parent
            shape.set_blocked(False)
            self.__nested_shapes.pop(shape.get_id(), None)
            if len(self.__nested_shapes):
                self._path = self.__update_path()
                self._update_bounding_box()
            else:
                self.is_empty = True
        return shape


    def get_nested_shapes(self):
        return list(self.__nested_shapes.values())


    def draw_to(self, canvas):
        if not self.is_empty:
            self._draw_to(canvas)
            for sh in self.__nested_shapes.values():
                sh.draw_to(canvas)


    def move_to(self, cursor_pos):
        last_pos = self._last_pos
        self._move_to(cursor_pos)
        for sh in self.__nested_shapes.values():
            sh._last_pos = last_pos
            sh.move_to(cursor_pos)
