#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "compte.h"
#include "emissions.h"
#include "invites.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include<QtWidgets>
#include <QModelIndex>
#include <QSqlTableModel>
#include"exel.h"
#include"camera.h"
#include "statistique_materiel.h"
#include "historiques.h"
#include"materiel.h"
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
class Dialog;
}
class QMediaPlayer;
class QVideoWidget;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setcompte(compte c);
    ~Dialog();

private slots:


    void on_emission_button_clicked();

    void on_pushButton_invite_clicked();

    void on_next_crud_clicked();

    void on_next_crud_2_clicked();

    void on_pushButton_next_crude_guest_clicked();

    void on_pushButton_previous_crud_guest_clicked();



    void on_pushButton_add_emission_clicked();

    void on_delete_emission_clicked();



    void on_refresh_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_add_guest_clicked();

    void on_pushButton_delete_a_guest_clicked();

    void on_pushButton_update_2_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_Pdf_emission_clicked();

    void on_pushButton_search_2_clicked();

    void on_pushButton_pdf_invites_clicked();

    void on_refresh_2_clicked();

    void on_pushButton_medio_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_volume_valueChanged(int value);

    void on_pushButton_mute_clicked();

    void on_pushButton_add_guest_2_clicked();

    void on_qrcode_clicked();

    int on_suivant_2_clicked();

    void on_Ajouter_3_clicked();
    void browse2();





    void on_brows2_clicked();

    void on_Ajouter_4_clicked();

    void on_afficher_5_clicked();

    void on_tableView_invite_activated(const QModelIndex &index);

    void on_Excelexport_clicked();
    void on_calendarWidget1_selectionChanged();
     void on_camera_clicked();
     void on_borws_picture_clicked();

     void on_page_materiel_customContextMenuRequested(const QPoint &pos);

     void on_pushButton_materiel_clicked();

     void on_tab_materiel_currentChanged(int index);

     void on_pushButton_clicked();

     void on_triermaterielBtn_clicked();

     void on_statmateriel_clicked();

     void on_pdfmateriel_clicked();

     void on_historiquemateriel_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pb_ajouter_clicked();

     void on_pb_triNOM_clicked();

     void on_pb_triTYPE_clicked();

     void on_pb_supprimer_clicked();

     void on_lineEdit_rechnom_textChanged(const QString &arg1);

     void on_lineEdit_3_textChanged(const QString &arg1);

     void on_pb_Excell_clicked();

     void on_pb_pdf_clicked();

     void on_pb_modifier_clicked();

     void on_pushButton_browse_email_clicked();

     void on_pushButton_send_email_clicked();
      void mailSent(QString);

     void on_pb_QR_clicked();

private:
    Ui::Dialog *ui;
    EMISSIONS E3;
    invites E;
    QMediaPlayer *mMediaPlayer;
    QStringList files;
    QByteArray data;
    QString filePath;
    camera *ca;
    materiel c;
    materiel c1;
      CLIENT C;

};

#endif // DIALOG_H
