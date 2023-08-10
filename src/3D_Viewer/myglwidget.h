#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QWidget>
#include <QOpenGLWidget>
#include <QtOpenGL>

class MyGlWidget : public QOpenGLWidget
{
    Q_OBJECT
private:
    float xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
public:
    explicit MyGlWidget(QWidget *parent = nullptr);
    void DrawFigure();

signals:

};

#endif // MYGLWIDGET_H
