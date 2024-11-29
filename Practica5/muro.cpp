#include "muro.h"

muro::muro() : x(0), y(0), w(0), h(0) {}

muro::muro(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
    setPos(x, y);
}

QRectF muro::boundingRect() const {
    return QRectF(0, 0, w, h);
}

void muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::blue);
    painter->drawRect(0, 0, w, h);
}
