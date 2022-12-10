from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QPainterPath, QColor

from classes.primitives.a_shape import AShape



class CompositeShape(AShape):

    # private methods ==========================================================

    def __init__(self, parent, shape, *shapes):
        self.__shape = shape
        self.__nested_shapes = {}

        self.__add_shape(shape)
        for sh in shapes:
            self.add_shape(sh)

        path = self.__update_path()
        super().__init__(parent, path)

        self._color = QColor(0, 0, 0, 0) # shape background
        self._border_color = QColor(0, 0, 0, 0) # shape borders
        self._bb_color = QColor(0, 0, 0, 0) # bounding box background
        self._bbl_color = QColor(0, 0, 255, 255) # bounding box borders


    def __update_path(self):
        min_x, max_x, min_y, max_y = None, None, None, None

        if self.__shape is not None:
            min_x = self.__shape.bounding_rect().topLeft().x()
            max_x = self.__shape.bounding_rect().topRight().x()
            min_y = self.__shape.bounding_rect().topLeft().y()
            max_y = self.__shape.bounding_rect().bottomLeft().y()

        for sh in self.__nested_shapes.values():
            minx = sh.bounding_rect().topLeft().x()
            maxx = sh.bounding_rect().topRight().x()
            miny = sh.bounding_rect().topLeft().y()
            maxy = sh.bounding_rect().bottomLeft().y()

            if min_x is not None:
                if minx < min_x: min_x = minx
                if maxx > max_x: max_x = maxx
                if miny < min_y: min_y = miny
                if maxy > max_y: max_y = maxy
            else:
                min_x = minx
                max_x = maxx
                min_y = miny
                max_y = maxy

        path = QPainterPath()
        path.moveTo(min_x, min_y)
        path.lineTo(max_x, min_y)
        path.lineTo(max_x, max_y)
        path.lineTo(min_x, max_y)
        path.lineTo(min_x, min_y)
        return path


    def __add_shape(self, shape):
        if shape is not None:
            shape._parent = self
            shape.is_active(False)
            shape.is_blocked(True)
            self._path = self.__update_path()
            self._update_bounding_box()

    # public methods ===========================================================

    def is_empty(self):
        return (self.__shape is None) and (len(self.__nested_shapes) == 0)


    def on_click(self, cursor_pos, keyboard_modifier):
        if self.__shape is not None:
            shape_path = self.__shape._path
        else:
            shape_path = self._path
        self._on_click(cursor_pos, keyboard_modifier, shape_path)


    def add_shape(self, shape):
        self.__nested_shapes[shape.get_id()] = shape
        self.__add_shape(shape)
        return shape


    def remove_shape(self, shape):
        shape = self.__nested_shapes.pop(shape.get_id(), None)
        if shape is not None:
            shape._parent = self._parent
            shape.is_active(False)
            shape.is_blocked(False)
            if not self.is_empty():
                self._path = self.__update_path()
                self._update_bounding_box()
        return shape


    def get_nested_shapes(self):
        return list(self.__nested_shapes.values())


    def draw_to(self, canvas):
        if self.__shape is not None:
            self.__shape.draw_to(canvas)
        self._draw_to(canvas)
        for sh in self.__nested_shapes.values():
            sh.draw_to(canvas)


    def move_to(self, cursor_pos):
        last_pos = self._last_pos
        if self.__shape is not None:
            self.__shape._last_pos = last_pos
            self.__shape.move_to(cursor_pos)
        self._move_to(cursor_pos)
        for sh in self.__nested_shapes.values():
            sh._last_pos = last_pos
            sh.move_to(cursor_pos)


    def get_parameters(self):
        return self.__shape.get_parameters()
