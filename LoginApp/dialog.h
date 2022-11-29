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

private:
    Ui::Dialog *ui;
    EMISSIONS E3;
    invites E;
    QMediaPlayer *mMediaPlayer;
    QStringList files;
    QString filePath;
    camera *c;
};

#endif // DIALOG_H
