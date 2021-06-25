class IShape:

    # virtual methods =========================================================

    def get_parameters(self):
        raise NotImplementedError()


    def draw(self, canvas, path):
        raise NotImplementedError()


    def set_color(self, color):
        raise NotImplementedError()


    def set_border_color(self, color):
        raise NotImplementedError()


    def set_border_style(self, style):
        raise NotImplementedError()


    def set_border_width(self, width):
        raise NotImplementedError()
