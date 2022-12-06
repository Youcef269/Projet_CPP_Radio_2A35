#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<client.h>
#include<connection.h>
#include <QMainWindow>
#include<QMessageBox>
#include<QDebug>
#include<QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include<QDateTime>
#include <QTime>
#include<QPdfWriter>
#include<QPainter>
#include<QPrinter>
#include <QTabWidget>
#include<QPixmap>
#include<QPieSeries>
#include<QChart>
#include<QPieSlice>
#include<QChartView>
#include<QVBoxLayout>
#include<QBarSet>
#include<QBarSeries>

#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDataStream>
#include <QDataStream>

#include"client.h"
#include"excell.h"
#include "smtp.h"
#include <QDialog>
#include <QFileDialog>
#include <QAbstractSocket>
#include<QSslSocket>
#include<QtNetwork>
#include<arduino.h>
#include"employe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    QSqlQueryModel* rechercherdynamique(int ,int );



    void on_lineEdit_rechnom_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pb_triNOM_clicked();

    void on_pb_triTYPE_clicked();











    void on_pb_QR_clicked();

    void on_pb_Excell_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_send_email_clicked();

    void on_pushButton_browse_email_clicked();
     void mailSent(QString);

     void on_pb_arduino_clicked();

     void on_pb_valider_clicked();

     void on_pb_rechercher_clicked();

     void on_pb_tri_clicked();

     void on_pb_on_clicked();

     void on_pb_supprimer_yass_clicked();

     void on_pb_modif_yas_clicked();

     void on_tableView_2_clicked(const QModelIndex &index);

     void on_tabWidget_2_currentChanged(int index);

     void on_tabWidget_2_tabBarClicked(int index);

     void on_pb_imprimer_yas_clicked();

     void on_pb_pdf_yas_clicked();

     void on_le_id_7_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;
    CLIENT C;

    Employe em;


    QStringList files;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
