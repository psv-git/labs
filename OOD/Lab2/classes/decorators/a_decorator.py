class ADecorator:

    # private methods =========================================================

    def __init__(self, shape):
        self.__shape = shape


    # public methods ==========================================================

    def get_parameters(self):
        return self.__shape.get_parameters()
