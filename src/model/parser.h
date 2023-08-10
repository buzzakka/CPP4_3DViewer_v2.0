#ifndef S21_3D_VIEWER_MODEL_PARSER
#define S21_3D_VIEWER_MODEL_PARSER

// #include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace s21 {

class FileReader {
    public:
        s21::Scene ReadScene(std::string path) {
            s21::Figure new_figure;
            std::ifstream file(path);
            if (file) {
                std::string line;
                while (std::getline(file, line)) {
                    if (line[0] == 'v') {
                        float x = 0, y = 0, z = 0;
                        sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
                        new_figure.AddVertex(x, y, z);
                    }
                }
                file.close();
            }
            s21::Scene new_scene;
            new_scene.set_figure(new_figure);
            return new_scene;
        }

};
} // namespace s21

#endif // S21_3D_VIEWER_MODEL_PARSER