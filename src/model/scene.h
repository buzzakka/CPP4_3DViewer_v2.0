#ifndef S21_3D_VIEWER_MODEL_FIGURE
#define S21_3D_VIEWER_MODEL_FIGURE

#include <vector>

namespace s21 {

class Point {
    public:
        Point(float x_value = 0, float y_value = 0, float z_value = 0) : x(x_value), y(y_value), z(z_value) {};
        void print() {printf("x=%f\ty=%f\tz=%f\n", x, y, z);}
    private:
        float x;
        float y;
        float z;
};

class Vertex {
    public:
        Vertex(float x_value = 0, float y_value = 0, float z_value = 0) : position_(Point (x_value, y_value, z_value)) {}
        Point get_position() {return position_;}
    private:
        Point position_; 
};

class Figure {
    public:
        Figure() {};
        std::vector<Vertex> get_vertices() {return vertices_;}
        void AddVertex(float x, float y, float z) {vertices_.push_back(Vertex(x, y, z));}
        void print() {
            for (s21::Vertex elem : vertices_) {
                elem.get_position().print();
            }
        }
    private:
        std::vector<Vertex> vertices_;
};

class Scene {
    public:
        Scene() {};
        Figure get_figure() {return figure_;}
        void set_figure(Figure new_figure) {figure_ = new_figure;}
    private:
        Figure figure_;
};

} // namespace s21

#endif // S21_3D_VIEWER_MODEL_FIGURE