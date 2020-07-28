#include "tarea.h"
#include "ui_tarea.h"
#include <QDebug>
#include <QFileDialog>

Tarea::Tarea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea)
{
    ui->setupUi(this);
    connect(ui->btnAgregar, SIGNAL(clicked()), this, SLOT(guardarTareas()));
}

Tarea::~Tarea()
{
    delete ui;
}

void Tarea::guardarTareas()
{
    QString fileName = "tareas.csv";
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly |   QFile::Text)) {
        return;
    }
        QTextStream out(&file);
        QString nombre = ui->inNombre->text();
        QString fecha = ui->inFecha->text();
        out << nombre << ";";
        //Obteniendo la opcion que eligio el usuario de la interfaz
        if(ui->inAlta->isChecked()){
            out << "Alta" << ";";
        }else if(ui->inMedia->isChecked()){
            out << "Media" << ";";
        }else{
            out << "Baja" << ";";
        }
        //Obteniendo la opcion que eligio el usuario de la interfaz
        if(ui->inUniversidad->isChecked()){
            out << "Universidad" << ";";
        }else if(ui->inPersonal->isChecked()){
            out << "Personales" << ";";
        }else{
            out << "Familiares" << ";";
        }
        out << fecha;
        out <<"\n";
        ui->inNombre->clear();

}
