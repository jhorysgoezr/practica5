// muro.h
#ifndef MURO_H
#define MURO_H

#include <QGraphicsItem>
#include <QPainter>

class muro : public QGraphicsItem
{
private:
    int x,y,w,h;

public:
    muro();
    muro(int x, int y, int w, int h);
    virtual ~muro() {}  // Agregar esta línea
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MURO_H
