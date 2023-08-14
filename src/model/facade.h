#ifndef S21_3D_VIEWER_MODEL_FACADE_H
#define S21_3D_VIEWER_MODEL_FACADE_H

#include "parser.h"
#include "scene.h"

namespace s21 {
    class Facade {
        public:
            Facade() {};
            void DrawScene(std::string path) {
                scene_ = file_reader_.ReadScene(path);
            }
        private:
            FileReader file_reader_;
            Scene scene_;
    };
}

#endif // S21_3D_VIEWER_MODEL_FACADE_H