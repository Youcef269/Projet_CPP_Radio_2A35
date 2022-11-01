#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();


    void on_supp_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_modif_clicked();

private:
    Ui::MainWindow *ui;
    Employe em;
};

#endif // MAINWINDOW_H
