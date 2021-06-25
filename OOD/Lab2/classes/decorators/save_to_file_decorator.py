from configs import app_config as cnf
from classes.decorators.a_decorator import ADecorator



class SaveToFileDecorator(ADecorator):

    # private methods =========================================================

    def __init__(self, shape, output_file_path):
        super().__init__(shape)
        self.__file_path = output_file_path


    # public methods ==========================================================

    def get_parameters(self):
        figure_type, perimeter, area = super().get_parameters()

        try:
            with open(cnf.ROOT_PATH + self.__file_path, "a") as out_file:
                out_file.write("{0}: P={1}; S={2}\n".format(figure_type, perimeter, area))
        except:
            print("Cant open output file.")
            raise

        return figure_type, perimeter, area
