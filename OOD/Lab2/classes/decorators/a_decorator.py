class ADecorator:

    def __init__(self, shape):
        self.__shape = shape


    def __str__(self):
        return str(self.__shape)


    def on_click(self, cursor_pos, keyboard_modifier):
        return self.__shape.on_click(cursor_pos, keyboard_modifier)


    def on_drag(self, cursor_pos):
        return self.__shape.on_drag(cursor_pos)


    def fill_color(self, color=None):
        return self.__shape.fill_color(color)


    def border_color(self, color=None):
        return self.__shape.border_color(color)


    def bb_fill_color(self, color=None):
        return self.__shape.bb_fill_color(color)


    def bb_border_color(self, color=None):
        return self.__shape.bb_border_color(color)


    def path(self, path=None):
        return self.__shape.path(path)


    def parent(self, parent=None):
        return self.__shape.parent(parent)


    def last_pos(self, pos=None):
        return self.__shape.last_pos(pos)


    def is_active(self, val=None):
        return self.__shape.is_active(val)


    def is_blocked(self, val=None):
        return self.__shape.is_blocked(val)


    def is_empty(self):
        return self.__shape.is_empty()


    def get_id(self):
        return self.__shape.get_id()


    def bounding_rect(self):
        return self.__shape.bounding_rect()


    def add_shape(self, shape):
        return self.__shape.add_shape(shape)


    def remove_shape(self, shape):
        return self.__shape.remove_shape(shape)


    def get_nested_shapes(self):
        return self.__shape.get_nested_shapes()


    def draw_to(self, canvas):
        return self.__shape.draw_to(canvas)


    def move_to(self, cursor_pos):
        return self.__shape.move_to(cursor_pos)


    def get_parameters(self):
        return self.__shape.get_parameters()
