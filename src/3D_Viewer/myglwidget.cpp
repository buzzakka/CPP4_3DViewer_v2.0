#include "myglwidget.h"
#include <QVector>
#include <vector>
#include "../model/parser.h"
#include "../model/scene.h"

MyGlWidget::MyGlWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}
//std::vector<double> v_arr = {
//    -0.5, -0.5, 0.5,      -0.5, 0.5, 0.5,       0.5, 0.5, 0.5,    0.5, -0.5, 0.5
//        -0.5, -0.5, -0.5,     -0.5, 0.5, -0.5,      0.5, 0.5, -0.5,   0.5, -0.5, -0.5
//};
//std::vector<int> f_arr = {
//    0, 1, 1, 2, 2, 3, 3, 0
//};
void MyGlWidget::initializeGL() {glEnable(GL_DEPTH_TEST);}
void MyGlWidget::resizeGL(int w, int h) {glViewport(0, 0, w, h);}
void MyGlWidget::paintGL() {
    glClearColor(.0f, .0f, .0f, .0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fov = 60.0 * M_PI / 180;
    float heapHeight = 1 / (2 * tan(fov / 2));
    glFrustum(-1, 1, -1, 1, heapHeight, 100);
    glTranslated(0, 0, -heapHeight * 3);

//    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    DrawFigure();
}
void MyGlWidget::DrawFigure() {
    s21::FileReader f_reader;
    s21::Scene scene = f_reader.ReadScene("/Users/marsel/Desktop/git/temp/CPP4_3DViewer_v2.0/src/model/obj_files/test1.obj");
    s21::Figure figure = scene.get_figure();
    std::vector<int> f_arr = figure.get_facets();
    std::vector<double> v_arr = figure.get_vertices();

    glVertexPointer(3, GL_DOUBLE, 0, &v_arr[0]); //определяет массив данных вершин
    glEnableClientState(GL_VERTEX_ARRAY); // разрешаем массив вершин
    glDrawElements(GL_LINES, f_arr.size(), GL_UNSIGNED_INT, &f_arr[0]);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void MyGlWidget::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}
void MyGlWidget::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI *(mo->pos().y() - mPos.y());
    yRot = 1 / M_PI *(mo->pos().x() - mPos.x());
    update();
}
