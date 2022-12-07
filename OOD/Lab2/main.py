import sys
import logging
from logging.config import fileConfig
from PyQt5.QtWidgets import QApplication

from configs import app_config as cnf
from classes.app_handler.app_handler import AppHandler



if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Please enter relative paths to input/output files as commandline arguments.")
    else:
        fileConfig(cnf.LOGGER_CONFIG_PATH, disable_existing_loggers=False)

        app = QApplication(sys.argv)
        
        app_handler = AppHandler(sys.argv[1], sys.argv[2])
        app_handler.destroyed.connect(app.exit)
        
        sys.exit(app.exec_())
