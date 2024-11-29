#ifndef LABERINTO_H
#define LABERINTO_H

#include <QVector>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include "muro.h"
#include "pildora.h"
#include "personaje.h"


class laberinto {
private:
    QVector<muro*> muros;
    QVector<QString> mapaLaberinto;
    const int TAMANO_BLOQUE = 18;  // Tamaño de cada bloque del laberinto
    QVector<Pildora*> pildoras; // Lista de píldoras


public:
    laberinto();
    void cargarLaberintoDesdeTxt(const QString& nombreArchivo);
    void crearLaberintoDesdeMatriz(QGraphicsScene *scene);
    void verificarColisionesConPildoras(personaje* pacman, QGraphicsScene* scene);
    QVector<muro*> getMuros() const;
    QVector<Pildora*> getPildoras() const;


private:
    void interpretarSimbolo(char simbolo, int x, int y, QGraphicsScene *scene);
};

#endif // LABERINTO_H
