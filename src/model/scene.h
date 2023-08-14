#ifndef S21_3D_VIEWER_MODEL_FIGURE
#define S21_3D_VIEWER_MODEL_FIGURE

#include <vector>

namespace s21 {

class Figure {
    public:
        Figure() {};
        std::vector<double> get_vertices() {return vertices_;}
        std::vector<int> get_facets() {return facets_;}
        void AddVertex(double x, double y, double z) {vertices_.insert(vertices_.end(), {x, y, z});}
        void AddFacet(std::vector<int> new_facet) {for(auto elem : new_facet) facets_.push_back(elem);}
    private:
        std::vector<double> vertices_;
        std::vector<int> facets_;
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