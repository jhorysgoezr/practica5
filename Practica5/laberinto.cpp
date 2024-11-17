#include "laberinto.h"
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <iostream>

laberinto::laberinto() {
    scene = new QGraphicsScene();
}

void laberinto::loadFromFile(const std::string& filename) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return;
    }

    QTextStream in(&file);
    int y = 0;
    const int tileSize = 20; // Tamaño de cada celda en píxeles

    while (!in.atEnd()) {
        QString line = in.readLine();
        for (int x = 0; x < line.length(); ++x) {
            char cell = line[x].toLatin1();
            switch (cell) {
            case 'a': case 'b': case 'h': case 'v': case 'n':
                addWall(x * tileSize, y * tileSize, tileSize, tileSize);
                break;
            case '@':
                // Agregar punto grande
                break;
            case '·':
                // Agregar punto pequeño
                break;
            default:
                // Espacio vacío u otro elemento
                break;
            }
        }
        ++y;
    }
}

void laberinto::addWall(int x, int y, int width, int height) {
    auto wall = new QGraphicsRectItem(x, y, width, height);
    wall->setBrush(QBrush(Qt::blue));
    wall->setPen(Qt::NoPen);
    scene->addItem(wall);
    walls.push_back(wall);
}

QGraphicsScene* laberinto::getScene() {
    return scene;
}
