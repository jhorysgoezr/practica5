#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 705, 495);

    // Crear laberinto desde archivo de texto
    miLaberinto = new laberinto();
    miLaberinto->cargarLaberintoDesdeTxt("C:\\Users\\lenovo\\Documents\\AppGUI\\build\\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\\mapa.txt");
    miLaberinto->crearLaberintoDesdeMatriz(scene);

    miPersonaje = new personaje(47, 17, 5, 5);
    ui->graphicsView->setScene(scene);
    scene->addItem(miPersonaje);
}


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::verificarColisionesPersonaje(QPointF direccion)
{
    return miPersonaje->verificarColision(direccion);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QPointF direccion;

    // Determinar dirección según la tecla presionada
    if (event->key() == Qt::Key_Z) direccion = QPointF(0, miPersonaje->getVelocidad());
    else if (event->key() == Qt::Key_S) direccion = QPointF(0, -miPersonaje->getVelocidad());
    else if (event->key() == Qt::Key_D) direccion = QPointF(miPersonaje->getVelocidad(), 0);
    else if (event->key() == Qt::Key_A) direccion = QPointF(-miPersonaje->getVelocidad(), 0);

    // Verificar si el personaje puede moverse en la dirección deseada
    if (!verificarColisionesPersonaje(direccion)) {
        // Actualizar posición del personaje
        miPersonaje->actualizarPosicion(miPersonaje->calcularNuevaPosicion(direccion));

        // Verificar colisiones con píldoras
        miLaberinto->verificarColisionesConPildoras(miPersonaje, scene);
    }
}






