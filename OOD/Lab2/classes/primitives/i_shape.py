class IShape:
    """
    It just declare childs interface, no more.
    """

    # virtual methods =========================================================

    def draw_to(self, canvas):
        raise NotImplementedError()


    def move_to(self, point):
        raise NotImplementedError()


    def is_contain(self, point):
        raise NotImplementedError()


    def get_bounding_rect(self):
        raise NotImplementedError()


    def get_parameters(self):
        raise NotImplementedError()


    def set_color(self, color):
        raise NotImplementedError()


    def set_border_color(self, color):
        raise NotImplementedError()


    def set_border_style(self, style):
        raise NotImplementedError()


    def set_border_width(self, width):
        raise NotImplementedError()
