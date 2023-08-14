#include "model.h"
#include <vector>

int main() {
    s21::FileReader test;
    std::string path = "./obj_files/test.obj";
    s21::Scene scene = test.ReadScene(path);
    s21::Figure figure = scene.get_figure();
    figure.print();
    return 0;
}