#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void alerte();
private slots:
    void on_ajouterButton_clicked();

    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_pushButton_clicked();

    void on_matriculeInput_3_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    bool verifyCode(QString data);
    void arduinoo();

private:
    Ui::MainWindow *ui;
    arduino A;
};
#endif // MAINWINDOW_H
