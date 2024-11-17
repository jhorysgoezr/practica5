#include "Laberinto.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    laberinto laberinto;
    laberinto.loadFromFile("mapa.txt");

    QGraphicsView view(laberinto.getScene());
    view.show();

    return app.exec();
}
