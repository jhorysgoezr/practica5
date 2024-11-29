#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include "muro.h"
#include "pildora.h"

class personaje : public QGraphicsItem {
public:
    personaje();
    personaje(int x, int y, int w, int h);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool verificarColision(QPointF direccionMovimiento);
    void actualizarPosicion(QPointF nuevaPosicion);
    QPointF obtenerPosicionActual() const;
    QPointF calcularNuevaPosicion(QPointF direccionMovimiento) const;
    void MoverConColision(int dx, int dy);
    void comerPildoras();  // Nuevo método para comer píldoras

    // Métodos de movimiento
    void MoverArriba();
    void MoverAbajo();
    void MoverIzq();
    void MoverDer();

    // Nuevo método con colisiones
    void MoverConColision(int dx, int dy, const QVector<class muro*>& muros);

    int getVelocidad() const;

private:
    int x, y, w, h, velocidad;
};

#endif // PERSONAJE_H
