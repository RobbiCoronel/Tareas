#ifndef TAREA_H
#define TAREA_H

#include <QDialog>

namespace Ui {
class Tarea;
}

class Tarea : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea(QWidget *parent = nullptr);
    ~Tarea();

public slots:
    void guardarTareas();

private:
    Ui::Tarea *ui;
};

#endif // TAREA_H
