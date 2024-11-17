#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Constructor
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        qDebug() << "Tecla Arriba presionada";
        break;
    case Qt::Key_Down:
        qDebug() << "Tecla Abajo presionada";
        break;
    case Qt::Key_Left:
        qDebug() << "Tecla Izquierda presionada";
        break;
    case Qt::Key_Right:
        qDebug() << "Tecla Derecha presionada";
        break;
    default:
        QMainWindow::keyPressEvent(event); // Propaga el evento al padre
    }
}
