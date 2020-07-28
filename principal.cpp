#include "principal.h"
#include "ui_principal.h"
#include "tarea.h"
#include <QDebug>
#include <QFile>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->mnuSalir, SIGNAL(triggered(bool)), this, SLOT(close()));
    QStringList cabecera = {"Numero", "Nombre", "Tipo","Fecha"};
    ui->outTareas->setColumnCount(4);
    ui->outTareas->setHorizontalHeaderLabels(cabecera);
    leerArchivo();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::leerArchivo()
{
    int numero = 1;
    QFile archivo("Tareas.csv");
    // leer el archivo de tareas
    if(archivo.open(QFile::ReadOnly)){
        QTextStream in(&archivo);
        while (!in.atEnd()){
            QString linea = in.readLine();
            //separar datos por ;
            QStringList datos = linea.split(';');
            QString nombre = datos[0];
            QString prioridad = datos[1];
            QString tipo = datos[2];
            QString fecha = datos[3];
            int posicion = ui->outTareas->rowCount();
            ui->outTareas->insertRow(posicion);
            ui->outTareas->setItem(posicion,0,new QTableWidgetItem(QString::number(numero++)));
            ui->outTareas->setItem(posicion,1,new QTableWidgetItem(nombre));
            ui->outTareas->setItem(posicion,2,new QTableWidgetItem(tipo));
            ui->outTareas->setItem(posicion,3,new QTableWidgetItem(fecha));
            if(prioridad == "Alta"){
                ui->outTareas->setStyleSheet("color: red");
            }else if(prioridad == "Media"){
                ui->outTareas->setStyleSheet("color: orange");
            }else if(prioridad == "Baja"){
                ui->outTareas->setStyleSheet("color: green");
            }
        }
    }else{
        qDebug() << "Error al abrir el archivo";
    }

    archivo.close();
}


void Principal::on_mnuAgregar_triggered()
{
    Tarea *dlgTarea = new Tarea();
    dlgTarea->show();
}

void Principal::on_mnuFinalizar_triggered()
{
    int p = ui->outTareas->currentRow();
    ui->outTareas->removeRow(p);
}
