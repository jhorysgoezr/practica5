#include "pildora.h"

Pildora::Pildora(int x, int y, int tamano, bool esMagica)
    : QGraphicsEllipseItem(x + tamano / 4, y + tamano / 4, tamano / 2, tamano / 2), magica(esMagica) {
    if (magica) {
        setBrush(QBrush(Qt::yellow)); // Color amarillo para píldoras mágicas
    } else {
        setBrush(QBrush(Qt::red)); // Color blanco para píldoras normales
    }
}

bool Pildora::esMagica() const {
    return magica;  // Devuelve si la píldora es mágica
}
