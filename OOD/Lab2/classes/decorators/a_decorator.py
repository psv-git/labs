from classes.primitives.i_shape import IShape



class ADecorator(IShape):

    # private methods =========================================================

    def __init__(self, shape):
        self.__shape = shape


    # public methods ==========================================================

    def draw_to(self, canvas):
        self.__shape.draw_to(canvas)


    def move_to(self, point):
        self.__shape.move_to(point)


    def is_contain(self, point):
        return self.__shape.is_contain(point)


    def get_bounding_rect(self):
        return self.__shape.get_bounding_rect()


    def get_parameters(self):
        return self.__shape.get_parameters()


    def set_color(self, color):
        self.__shape.set_color(color)


    def set_border_color(self, color):
        self.__shape.set_border_color(color)


    def set_border_style(self, style):
        self.__shape.set_border_style(style)


    def set_border_width(self, width):
        self.__shape.set_border_width(width)
