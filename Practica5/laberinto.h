#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <string>
#include <vector>


class laberinto
{

public:
    laberinto();
    void loadFromFile(const std::string& filename);
    QGraphicsScene* getScene();
private:
    QGraphicsScene* scene;
    std::vector<QGraphicsRectItem*> walls;
    void addWall(int x, int y, int width, int height);
};

#endif // LABERINTO_H
