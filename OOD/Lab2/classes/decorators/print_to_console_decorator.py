from classes.decorators.a_decorator import ADecorator



class PrintToConsoleDecorator(ADecorator):

    # private methods =========================================================

    def __init__(self, shape):
        super().__init__(shape)


    # public methods ==========================================================

    def get_parameters(self):
        figure_type, perimeter, area = super().get_parameters()

        print("Figure type: {0}, perimeter: {1}, area: {2}".format(figure_type, perimeter, area))

        return figure_type, perimeter, area
