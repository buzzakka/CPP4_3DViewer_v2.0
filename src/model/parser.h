#ifndef S21_3D_VIEWER_MODEL_PARSER
#define S21_3D_VIEWER_MODEL_PARSER

#include "scene.h"
#include <string>
#include <fstream>
#include <iostream>
#include <thread>

namespace s21 {

class FileReader {
    public:
        s21::Scene ReadScene(std::string path) {
            s21::Figure new_figure;
            std::ifstream file(path);
            if (file) {
                std::string line;
                while (std::getline(file, line)) {
                    if (line.front() == 'v') {
                        float x = 0, y = 0, z = 0;
                        sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
                        new_figure.AddVertex(x, y, z);
                    } else if (line.front() == 'f') {
                        new_figure.AddFacet(FacetParser(line));
                    }
                }
                file.close();
            }
            s21::Scene new_scene;
            new_scene.set_figure(new_figure);
            return new_scene;
        }

        std::vector<int> FacetParser(std::string line) {
            std::string delimiter = " ";
            size_t last = 0;
            size_t next = 0;
            std::vector<int> result_facet {};
            while((next = line.find(delimiter, last)) != std::string::npos) {
                std::string token = line.substr(last, next-last);
                if (token != "f") {
                    int result = atoi(token.c_str()) - 1;
                    result_facet.push_back(result);
                }
                last = next + 1;
            }
            result_facet.push_back(atoi(line.substr(last).c_str()) - 1);
            result_facet = NormalizeFacet(result_facet);
            return result_facet;
        }

        std::vector<int> NormalizeFacet(std::vector<int> facet_vactor) {
            std::vector<int> result_facet {};
            for (auto it = facet_vactor.begin(); it != facet_vactor.end(); ++it) {
                if (it != facet_vactor.begin()) result_facet.push_back(*it);
                result_facet.push_back(*it); 
            }
            result_facet.push_back(facet_vactor.front());
            return result_facet;
        }
};
} // namespace s21

#endif // S21_3D_VIEWER_MODEL_PARSER
