from PyQt5.QtGui import QPainterPath, QColor

from classes.primitives.a_shape import AShape



class CompositeShape(AShape):

    # private methods ==========================================================

    def __init__(self, parent, *shapes):
        self.__shape = None
        self.__nested_shapes = {}

        if not len(shapes):
            raise AttributeError()
        elif len(shapes) == 1:
            self.__shape = shapes[0]
            self.__add_shape(self.__shape)
        else:
            for sh in shapes:
                self.add_shape(sh)

        super().__init__(parent, self.__update_path())

        self.fill_color(QColor(0, 0, 0, 0))
        self.border_color(QColor(0, 0, 0, 0))
        self.bb_fill_color(QColor(0, 0, 0, 0))
        self.bb_border_color(QColor(0, 0, 255, 255))


    def __str__(self):
        return f"<CompositeShape: shape={str(self.__shape)}, nested={'(' + '| '.join(str(ns) for ns in self.__nested_shapes.values()) + ')'}>"


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
            shape.parent(self)
            shape.is_active(False)
            shape.is_blocked(True)
            self.path(self.__update_path())
            self._update_bounding_box()

    # public methods ===========================================================

    def is_empty(self):
        return (self.__shape is None) and (len(self.__nested_shapes) == 0)


    def on_click(self, cursor_pos, keyboard_modifier):
        if self.__shape is not None:
            shape_path = self.__shape.path()
        else:
            shape_path = self.path()
        self._on_click(cursor_pos, keyboard_modifier, shape_path)


    def add_shape(self, shape):
        self.__nested_shapes[shape.get_id()] = shape
        self.__add_shape(shape)
        return shape


    def remove_shape(self, shape):
        shape = self.__nested_shapes.pop(shape.get_id(), None)
        if shape is not None:
            shape.parent(self.parent())
            shape.is_active(False)
            shape.is_blocked(False)
            if not self.is_empty():
                self.path(self.__update_path())
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
        last_pos = self.last_pos()
        if self.__shape is not None:
            self.__shape.last_pos(last_pos)
            self.__shape.move_to(cursor_pos)
        self._move_to(cursor_pos)
        for sh in self.__nested_shapes.values():
            sh.last_pos(last_pos)
            sh.move_to(cursor_pos)
