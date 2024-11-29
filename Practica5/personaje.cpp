#include "personaje.h"

personaje::personaje()
{

}

personaje::personaje(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    setPos(x,y);
    velocidad=5;
}

int personaje::getVelocidad() const {
    return velocidad; // Devuelve el valor de la velocidad
}

QRectF personaje::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());

    //QPixmap pxmap(":/pacman/pacman.png");
    //painter->drawPixmap(boundingRect(), pxmap,pxmap.rect());

}

QPointF personaje::obtenerPosicionActual() const
{
    return QPointF(x, y);
}

QPointF personaje::calcularNuevaPosicion(QPointF direccionMovimiento) const
{
    return QPointF(x + direccionMovimiento.x(), y + direccionMovimiento.y());
}

void personaje::actualizarPosicion(QPointF nuevaPosicion)
{
    x = nuevaPosicion.x();
    y = nuevaPosicion.y();
    setPos(x, y);
}

// Modificar los métodos de movimiento en personaje.cpp
void personaje::MoverArriba()
{
    QPointF direccion(0, -velocidad);
    if (!verificarColision(direccion)) {
        y = y - velocidad;
        setPos(x, y);
    }
}

void personaje::MoverAbajo()
{
    QPointF direccion(0, velocidad);
    if (!verificarColision(direccion)) {
        y = y + velocidad;
        setPos(x, y);
    }
}

void personaje::MoverIzq()
{
    QPointF direccion(-velocidad, 0);
    if (!verificarColision(direccion)) {
        x = x - velocidad;
        setPos(x, y);
    }
}

void personaje::MoverDer()
{
    QPointF direccion(velocidad, 0);
    if (!verificarColision(direccion)) {
        x = x + velocidad;
        setPos(x, y);
    }
}

// personaje.cpp - Implementar los nuevos métodos
bool personaje::verificarColision(QPointF direccionMovimiento)
{
    // Guardamos la posición actual
    QPointF posicionOriginal = pos();

    // Movemos temporalmente el personaje para verificar la colisión
    setPos(pos() + direccionMovimiento);

    QList<QGraphicsItem*> colisiones = collidingItems();
    bool hayColision = false;

    for (QGraphicsItem* item : colisiones) {
        muro* paredColision = dynamic_cast<muro*>(item);
        if (paredColision != nullptr) {
            hayColision = true;
            break;
        }
    }

    // Restauramos la posición original
    setPos(posicionOriginal);
    return hayColision;
}

