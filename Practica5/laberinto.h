#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <string>
#include <vector>

using namespace std;

class laberinto
{
public:
    laberinto();
    void loadFromFile(const std::string& filename);
    QGraphicsScene* getScene();
    void addMagicPill(int x, int y, int size); // Declaración de addMagicPill
    void addSmallPoint(int x, int y, int size); // Declaración de addSmallPoint
private:
    QGraphicsScene* scene;
    vector<QGraphicsRectItem*> walls;
    void addWall(int x, int y, int width, int height);
    vector<QGraphicsEllipseItem*> magicPills; // Vector para píldoras mágicas
    vector<QGraphicsEllipseItem*> smallPoints; // Vector para puntos pequeños
};

#endif // LABERINTO_H
