#ifndef PILDORA_H
#define PILDORA_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class Pildora : public QGraphicsEllipseItem {
public:
    Pildora(int x, int y, int tamano, bool esMagica);
    bool esMagica() const;

private:
    bool magica; // Define si es una píldora mágica
};

#endif // PILDORA_H
