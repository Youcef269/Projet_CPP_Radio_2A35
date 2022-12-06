#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "statt.h"
#include "arduino.h"
#include "materiel.h"
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

    void on_tabWidget_tabBarClicked(int index);

//    void on_Trier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_le_id_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_on_6_clicked();




    void on_pb_ajouter_5_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_5_clicked();

    void on_statmateriel_clicked();

    void on_pdfmateriel_clicked();

    void on_historiquemateriel_clicked();

    void on_materielachet_clicked();

    void on_triermaterielBtn_clicked();

    void on_materielComboBox_currentIndexChanged(int index);

    void on_recherchermateriel_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Employe em;
    statt *stat_emp;
    Arduino A;
    materiel c;
    materiel c1;
};

#endif // MAINWINDOW_H
