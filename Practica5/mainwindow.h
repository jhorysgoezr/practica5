#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <personaje.h>
#include <QKeyEvent>
#include <muro.h>
#include <laberinto.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    personaje *miPersonaje;
    QGraphicsScene *scene;
    laberinto *miLaberinto; // Añadimos el laberinto
    bool verificarColisionesPersonaje(QPointF direccion);
};

#endif // MAINWINDOW_H
