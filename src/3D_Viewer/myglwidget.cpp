#include "myglwidget.h"
#include <QVector>

MyGlWidget::MyGlWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void MyGlWidget::initializeGL() {   // Вызывается один раз при открытии проги
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}
float arr[] = {
    -0.5, -0.5, 0.5,      0.5, -0.5, 0.5,       0.5, 0.5, 0.5,        -0.5, 0.5, 0.5,
    0.5, -0.5, -0.5,      -0.5, -0.5, -0.5,       -0.5, 0.5, -0.5,        0.5, 0.5, -0.5,
    -0.5, -0.5, -0.5,      -0.5, -0.5, 0.5,       -0.5, 0.5, 0.5,        -0.5, 0.5, -0.5,
    0.5, -0.5, 0.5,      0.5, -0.5, -0.5,       0.5, 0.5, -0.5,        0.5, 0.5, 0.5,
    -0.5, -0.5, 0.5,      0.5, -0.5, 0.5,       0.5, -0.5, -0.5,        -0.5, -0.5, -0.5,
    -0.5, 0.5, 0.5,      0.5, 0.5, 0.5,       0.5, 0.5, -0.5,        -0.5, 0.5, -0.5,
};
float arr2[] = {
    -0.5, -0.5, 0.5,      0.5, -0.5, 0.5,       0, 0.5, 0,      // front
    0.5, -0.5, -0.5,      -0.5, -0.5, -0.5,       0, 0.5, 0,    // back
    -0.5, -0.5, -0.5,      -0.5, -0.5, 0.5,       0, 0.5, 0,    // left
    0.5, -0.5, 0.5,      0.5, -0.5, -0.5,       0, 0.5, 0,      // right
    -0.5, -0.5, 0.5,      0.5, -0.5, 0.5,       0.5, -0.5, -0.5,        -0.5, -0.5, -0.5, // bot
};

void MyGlWidget::paintGL() {    // Вызывается каждый раз при отрисовке
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f); // задает четкие значения для буферов цвета
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Очищает буферы (тут буфер цвета)
    glMatrixMode(GL_MODELVIEW); // указывает, какая матрица является текущей матрицей
    glLoadIdentity();   // загружаем единичную матрицу

    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    DrawFigure();
}
void MyGlWidget::resizeGL(int w, int h) {   // Вызывется при перерисовке
    glViewport(0, 0, w, h); // Задает окно просмотра
    glMatrixMode(GL_PROJECTION); // указывает, какая матрица является текущей матрицей.
    glLoadIdentity(); // заменяет текущую матрицу матрицей идентификации
//    glOrtho(-1, 1, -1, 1, 1, 2); // умножает текущую матрицу на орфографическую матрицу
    glFrustum(-1, 1, -1, 1, 1, 3); // задает перспективную матрицу
}

void MyGlWidget::DrawFigure() {
    glVertexPointer(3, GL_FLOAT, 0, &arr2); //определяет массив данных вершин
    glEnableClientState(GL_VERTEX_ARRAY); // разрешаем массив вершин
    glDrawArrays(GL_LINE_LOOP, 0, 16);
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
