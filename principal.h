#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
public:
    void leerArchivo();


private slots:
    void on_mnuAgregar_triggered();

    void on_mnuFinalizar_triggered();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
