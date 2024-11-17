#include "laberinto.h"
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <iostream>

laberinto::laberinto() {
    scene = new QGraphicsScene();
}

void laberinto::addMagicPill(int x, int y, int size) {
    auto magicPill = new QGraphicsEllipseItem(x, y, size, size);
    magicPill->setBrush(QBrush(Qt::red));
    magicPill->setPen(Qt::NoPen);
    scene->addItem(magicPill);
    magicPills.push_back(magicPill); // Opcional: almacenar para futura referencia
}

void laberinto::addSmallPoint(int x, int y, int size) {
    auto smallPoint = new QGraphicsEllipseItem(x, y, size, size);
    smallPoint->setBrush(QBrush(Qt::yellow));
    smallPoint->setPen(Qt::NoPen);

    // Opcional: Añadir un efecto de brillo
    QRadialGradient gradient(x + size/2, y + size/2, size/2);
    gradient.setColorAt(0, Qt::yellow);
    gradient.setColorAt(1, QColor(255, 255, 0, 150));
    smallPoint->setBrush(gradient);

    scene->addItem(smallPoint);
    smallPoints.push_back(smallPoint);
}

void laberinto::addWall(int x, int y, int width, int height) {
    auto wall = new QGraphicsRectItem(x, y, width, height);
    wall->setBrush(QBrush(Qt::blue));
    wall->setPen(Qt::NoPen);
    scene->addItem(wall);
    walls.push_back(wall); // Almacenar la pared para referencia futura
}

QGraphicsScene* laberinto::getScene() {
    return scene;
}

void laberinto::loadFromFile(const std::string& filename) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return;
    }

    QTextStream in(&file);
    int y = 0;
    const int tileSize = 20; // Tamaño de cada celda
    const int smallDotSize = tileSize / 4; // Tamaño del punto pequeño

    while (!in.atEnd()) {
        QString line = in.readLine();
        for (int x = 0; x < line.length(); ++x) {
            QChar cell = line[x];
            int posX = x * tileSize;
            int posY = y * tileSize;

            switch (cell.toLatin1()) {  // Convertimos QChar a char para la comparación
            case 'a': // Esquina superior izquierda
            case 'b': // Esquina superior derecha
            case 'c': // Esquina inferior izquierda
            case 'd': // Esquina inferior derecha
            case 'h': // Pared horizontal
            case 'v': // Pared vertical
            case 'm': // Medio hacia arriba
            case 'n': // Medio hacia abajo
            case 'o': // Medio hacia la izquierda
            case 'p': // Medio hacia la derecha
                addWall(posX, posY, tileSize, tileSize);
                break;

            case '@': // Píldora mágica
                addMagicPill(posX + tileSize / 4, posY + tileSize / 4, tileSize / 2);
                break;

            case '-': // Punto pequeño
                int dotX = posX + (tileSize - smallDotSize) / 2;
                int dotY = posY + (tileSize - smallDotSize) / 2;
                addSmallPoint(dotX, dotY, smallDotSize);
                break;
            }
        }
        ++y;
    }
    file.close();
}


