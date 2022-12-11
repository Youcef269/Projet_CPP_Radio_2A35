#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "sign_in.h"
#include <QPropertyAnimation>
#include"arduino.h"
#include "materiel.h"
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
QWidget *centralWidget;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_login_clicked();
    void on_sign_in_push_button_clicked();

void update_lable();



void on_hel_clicked();

void on_saker_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    sign_in *sign;
    QPropertyAnimation *animation;
    QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H
