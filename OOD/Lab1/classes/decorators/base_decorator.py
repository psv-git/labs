from classes.primitives.i_shape import IShape



class BaseDecorator(IShape):

    # private methods =========================================================

    def __init__(self, shape):
        self.__shape = shape


    # public methods ==========================================================

    def draw(self, canvas):
        self.__shape.draw(canvas)


    def set_color(self, color):
        self.__shape.set_color(color)


    def set_border_color(self, color):
        self.__shape.set_border_color(color)


    def set_border_style(self, style):
        self.__shape.set_border_style(style)


    def set_border_width(self, width):
        self.__shape.set_border_width(width)


    def get_parameters(self):
        return self.__shape.get_parameters()
