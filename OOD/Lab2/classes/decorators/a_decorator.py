class ADecorator:

    # private methods =========================================================

    def __init__(self, shape):
        self.__shape = shape


    # public methods ==========================================================

    def get_id(self):
        return self._shape.get_id()


    def draw(self, canvas):
        self.__shape.draw(canvas)


    def get_parameters(self):
        return self.__shape.get_parameters()


    def on_click(self, cursor_pos, keyboard_modifier):
        """
        On click method.
        Args:
            point: QPoint
        """
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
