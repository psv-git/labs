#include "game/Application.hpp"

int main() {
    Application app;
    app.run();

    std::cout << "Main was closed." << std::endl;
    return 0;
}
