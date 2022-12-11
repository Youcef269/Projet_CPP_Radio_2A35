#include "dialog.h"
#include"qrcode.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include"mainwindow.h"
#include "emission.h"
#include<QFileDialog>
#include<QMovie>
#include "invites.h"
#include <QIntValidator>
#include <QPdfWriter>
#include "QDate"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <string>
#include <vector>
#include<QDirModel>
#include<QMediaPlayer>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include<QTimer>
#include<QDebug>
#include<QSvgRenderer>
#include <cstring>
#include <string>
#include "statistique_materiel.h"
#include "historiques.h"
#include "materiel.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "smtp.h"
#include <QMainWindow>
#include<QMessageBox>
#include<QDesktopServices>
#include<QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include<QDateTime>
#include <QTime>
#include<QPdfWriter>
#include<QPainter>
#include<QPrinter>
#include<QBarCategoryAxis>
#include<QFileDialog>
#include<QFile>
#include "notification.h"
#include "employe.h"
#include<QPrintDialog>


using qrcodegen::QrCode;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    ui->add_emission_id->setValidator(new QIntValidator(100,999999,this));
    ui->lineEdit_8->setValidator(new QIntValidator(100,999999,this));
    ui->update_id->setValidator(new QIntValidator(100,999999,this));
    ui->lineEdit_guest_id_2->setValidator( new QIntValidator(100, 999999, this));
    ui->lineEdit_ID_invite->setValidator( new QIntValidator(100, 999999, this));
    ui->lineEdit_guest_id_3->setValidator( new QIntValidator(100, 999999, this));
    connect(ui->browseBtn_6, SIGNAL(clicked()), this, SLOT(browse2()));
    mMediaPlayer = new QMediaPlayer(this);



    connect(mMediaPlayer, &QMediaPlayer::positionChanged,[&](qint64 pos){ui->progressBar->setValue(pos);});
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](quint64 dur){ui->progressBar->setMaximum(dur);});
//    QRegExpValidator rv = new QRegExpValidator(QRegExp("^.$"));
//    ui->update_emission_name->setValidator(rv);


//    QMovie *movie = new QMovie(":/img/profile.gif");
//   // QLabel *processLabel = new QLabel(this);
//   // ui->label_2->setGeometry(100,100,100,100);
//    ui->emission_button->setMovie(movie);
//    movie->start();

    QMovie *movie1 = new QMovie(":/img/giphy (2) (1).gif");
   // QLabel *processLabel = new QLabel(this);
   // ui->label_2->setGeometry(100,100,100,100);
    ui->label_8->setMovie(movie1);
    movie1->start();
    ui->tableView_emission->setModel(E3.afficher());
    ui->tableView_invite->setModel(E.afficher());
    ui->tableView_invite_2->setModel(E.afficher());





//        QPixmap pix2(path);
//        int w1 = ui->label_18->width();
//        int h1 = ui->label_18->height();
//        ui->label_3->setPixmap(pix2.scaled(w1,h1,Qt::KeepAspectRatio));


    QMovie *movie = new QMovie(":/img/cameras.gif");
   // QLabel *processLabel = new QLabel(this);
   // ui->label_2->setGeometry(100,100,100,100);
    ui->camera_gif->setMovie(movie);
    movie->start();

    //view pictures in camera
     QPixmap pix1("C:/Users/Youcef/Pictures/Capture1");
     ui->label_pic->setPixmap(pix1);

     ui->table_CLIENT->setModel(C.afficher());



     ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");



     QtCharts::QBarSet *set0  = new  QtCharts::QBarSet ("client 1");
      QtCharts::QBarSet *set1  = new   QtCharts::QBarSet("client 2");
       QtCharts::QBarSet *set2  = new   QtCharts::QBarSet("client 3");
        QtCharts::QBarSet *set3  = new   QtCharts::QBarSet("client 4");
        *set0 << 30 << 40 << 10 << 20 << 10 << 60;
        *set1 << 10 << 30 << 42 << 15 << 81 << 75;
        *set2 << 80 << 100 << 70 << 13 << 60 << 20;
        *set3 << 30 << 10 << 80 << 70 << 60 << 45;

        QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);


        QtCharts::QChart *chart = new QtCharts::QChart();

        chart->addSeries(series);
        chart->setTitle("Statistiques des Client Durant l'année");
        chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);


        QStringList categories;
        categories << "jan" << "feb" << "march" << "april" << "mai" << "juin" ;
        QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);


        QtCharts::QChartView *chartview = new QtCharts::QChartView(chart);
        chartview->setParent(ui->horizentalframe);



}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_emission_button_clicked()
{
    ui->menu_stacked_widget->setCurrentIndex(1);
    QBarSet *set0=new QBarSet("Emissions Number");
        QBarSet *set1=new QBarSet("Sport");
        QBarSet *set2=new QBarSet("Fun");
        QBarSet *set3=new QBarSet("Info");


                      *set0 <<283<<341<<313<<338<<346<<335<<345<<200<<300<<350<<320<<340;
                      *set1 <<100<<141<<113<<100<<100<<100<<154<<50<<100<<100<<100<<140;
                      *set2 <<83<<100<<100<<138<<146<<120<<100<<50<<100<<150<<120<<100;
                      *set2 <<100<<100<<100<<100<<100<<115<<100<<100<<100<<100<<100<<100;

                      QBarSeries *Series=new QBarSeries();
                           Series->append(set0);
                           Series->append(set1);
                           Series->append(set2);
                           Series->append(set3);

                           QChart *chart=new QChart();
                           chart->addSeries(Series);
                           chart->setTitle("Monthly Emissions");
                           chart->setAnimationOptions(QChart::SeriesAnimations);
                             QStringList categories;
                              categories<<"January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"<<"October"<<"November"<<"December";
                              QBarCategoryAxis *axis=new  QBarCategoryAxis();
                                   axis->append(categories);
                                   chart->createDefaultAxes();
                                   chart->setAxisX(axis,Series);
                                   chart->legend()->setVisible(true);
                                   chart->legend()->setAlignment(Qt::AlignBottom);

                                   QChartView *chartview=new QChartView(chart) ;
         chartview->setRenderHint(QPainter::Antialiasing);

         QVBoxLayout *layout2 = new QVBoxLayout(ui->frame_youcef);
         layout2->addWidget(chartview);

         }

void Dialog::on_pushButton_invite_clicked()
{
    ui->menu_stacked_widget->setCurrentIndex(2);
    QBarSet *set0=new QBarSet("nombre d'invites");
        QBarSet *set1=new QBarSet("homme");
                 QBarSet *set2=new QBarSet("femme");


                 *set0 <<283<<341<<313<<338<<346<<335<<345<<200<<300<<350<<320<<340;
                 *set1 <<100<<140<<230<<200<<200<<130<<248<<150<<100<<200<<200<<140;
                 *set2 <<183<<200<<100<<138<<146<<105<<315<<50<<200<<150<<120<<200;

                 QBarSeries *Series=new QBarSeries();
                      Series->append(set0);
                      Series->append(set1);
                      Series->append(set2);

                      QChart *chart=new QChart();
                      chart->addSeries(Series);
                      chart->setTitle("Monthly guest");
                      chart->setAnimationOptions(QChart::SeriesAnimations);
                        QStringList categories;
                         categories<<"January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"<<"October"<<"November"<<"December";
                         QBarCategoryAxis *axis=new  QBarCategoryAxis();
                              axis->append(categories);
                              chart->createDefaultAxes();
                              chart->setAxisX(axis,Series);
                              chart->legend()->setVisible(true);
                              chart->legend()->setAlignment(Qt::AlignBottom);

                              QChartView *chartview=new QChartView(chart) ;
    chartview->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout2 = new QVBoxLayout(ui->aziz);
    layout2->addWidget(chartview);


}

void Dialog::setcompte(compte c)
{
    ui->lineEdit_compte->setText(c.getcompte());
}

void Dialog::on_next_crud_clicked()
{
    ui->stackedWidget_crud->setCurrentIndex(1);
}

void Dialog::on_next_crud_2_clicked()
{
    ui->stackedWidget_crud->setCurrentIndex(0);
}

void Dialog::on_pushButton_next_crude_guest_clicked()
{
     ui->stackedWidget_guest->setCurrentIndex(1);
}

void Dialog::on_pushButton_previous_crud_guest_clicked()
{
     ui->stackedWidget_guest->setCurrentIndex(0);
}


void Dialog::on_pushButton_add_emission_clicked()
{
    int ID_EMISSION=ui->add_emission_id->text().toInt();
    QString NOM_EMISSION=ui->add_emission_name->text();
//    QString TYPE_EMISSION=ui->type->text();
//    QString DUREE_EMISSION=ui->duree->text();
//    QString DATE_EMISSION=ui->date->text();

    QString TYPE_EMISSION;
    QString DUREE_EMISSION;


    if(ui->add_emission_type_fun->isChecked())
    {
     TYPE_EMISSION="fun";
    }
    else if(ui->add_emission_type_info->isChecked())
    {
     TYPE_EMISSION="info";
    }
    else if(ui->add_emission_type_sport->isChecked())
    {
    TYPE_EMISSION="sport";
    }


    if(ui->add_emission_duration_5->isChecked())
    {
     DUREE_EMISSION="5mn";
    }
    else if(ui->add_emission_duration_10->isChecked())
    {
     DUREE_EMISSION="10mn";
    }
    else if(ui->add_emission_duration_15->isChecked())
    {
     DUREE_EMISSION="15mn";
    }

    QDate date = ui->dateTimeEdit->date();
    QString DATE_EMISSION = date.toString();


  EMISSIONS E(ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION);


  bool test=E.ajouter();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("ajout effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->add_emission_id->setText("");
           ui->add_emission_name->setText("");
          // ui->tableView_emission->setModel(E3.afficher());

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("ajout non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



        ui->add_emission_id->setText("");
        ui->add_emission_name->setText("");
  }



void Dialog::on_delete_emission_clicked()
{
    EMISSIONS E1;

        E1.setid (ui->lineEdit_8->text().toInt());

        bool test=E1.supprimer(E1.getid());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            //ui->tableView_emission->setModel(E3.afficher());

    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
        ui->lineEdit_8->setText("");

    }


void Dialog::on_refresh_clicked()
{
    //ui->tableView_emission->setModel(E3.afficher());
    QString order;
    if(ui->comboBox_emission_2->currentText()=="ID_EMISSION")
    {
     order="ID_EMISSION";
    }
    if(ui->comboBox_emission_2->currentText()=="NOM_EMISSION")
    {
     order="NOM_EMISSION";
    }
    if(ui->comboBox_emission_2->currentText()=="TYPE_EMISSION")
    {
     order="TYPE_EMISSION";
    }

    EMISSIONS E;
    QSqlQueryModel *model =E.afficher_emission(order);
    ui->tableView_emission->setModel(model);
}



void Dialog::on_pushButton_update_clicked()
{

    int ID_EMISSION=ui->update_id->text().toInt();
    QString NOM_EMISSION=ui->update_emission_name->text();
//    QString TYPE_EMISSION=ui->type->text();
//    QString DUREE_EMISSION=ui->duree->text();
//    QString DATE_EMISSION=ui->date->text();

    QString TYPE_EMISSION;
    QString DUREE_EMISSION;


    if(ui->update_fun->isChecked())
    {
     TYPE_EMISSION="fun";
    }
    else if(ui->update_info->isChecked())
    {
     TYPE_EMISSION="info";
    }
    else if(ui->update_sport->isChecked())
    {
    TYPE_EMISSION="sport";
    }


    if(ui->update_duration_5->isChecked())
    {
     DUREE_EMISSION="5mn";
    }
    else if(ui->update_duration_10->isChecked())
    {
     DUREE_EMISSION="10mn";
    }
    else if(ui->update_duration_15->isChecked())
    {
     DUREE_EMISSION="15mn";
    }

    QDate date = ui->dateTimeEdit_2->date();
    QString DATE_EMISSION = date.toString();


  EMISSIONS E1(ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION);

  bool test=E1.update();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("update effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           //ui->tableView_emission->setModel(E3.afficher());
   }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("update non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }

       ui->update_id->setText("");
       ui->update_emission_name->setText("");

//       ui->update_id->setText("");
//       ui->update_emission_name->setText("");
//       ui->update_fun->setAutoExclusive(false);
//       ui->update_info->setAutoExclusive(false);
//       ui->update_sport->setAutoExclusive(false);
//     ui->tableView_emission->setModel(E3.afficher());
  }


void Dialog::on_pushButton_add_guest_clicked()
{
    int ID_INVITE=ui->lineEdit_guest_id_2->text().toInt();
        QString NOM_INVITE=ui->lineEdit_guest_name_2->text();
          QString PRENOM_INVITE=ui->lineEdit_guest_last_name_2->text();
          QString FONCTION=ui->lineEdit_guest_function->text();
QString TYPE;
          QDate date= ui->dateTimeEdit_4->date();
             QString DATE_INVITE= date.toString();
             if(ui->fun1->isChecked())
             {
              TYPE="fun";
             }
             else if(ui->info1->isChecked())
             {
              TYPE="info";
             }
             else if(ui->sport1->isChecked())
             {
             TYPE="sport";
             }
         invites inv(ID_INVITE,NOM_INVITE,PRENOM_INVITE,FONCTION,DATE_INVITE,TYPE);
         bool test=inv.ajouter();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("ajout effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_invite->setModel(E.afficher());

     }
         else
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("ajout non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_delete_a_guest_clicked()
{
    invites I;
        I.setid (ui->lineEdit_guest_id_3->text().toInt());

        bool test=I.supprimer(I.getid());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_invite->setModel(E.afficher());

    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        ui->lineEdit_guest_id_3->setText("");

}

void Dialog::on_pushButton_update_2_clicked()
{
    int ID_INVITE=ui->lineEdit_ID_invite->text().toInt();
       QString NOM_INVITE=ui->lineEdit_geusr_name->text();
         QString PRENOM_INVITE=ui->lineEdit_laste->text();
         QString FONCTION=ui->lineEdit_geusr_function_2->text();


         QDate date =ui->dateTimeEdit_3->date();
            QString DATE_INVITE= date.toString();
            QString TYPE;

                         if(ui->fun2->isChecked())
                         {
                          TYPE="fun";
                         }
                         else if(ui->info2->isChecked())
                         {
                          TYPE="info";
                         }
                         else if(ui->sport2->isChecked())
                         {
                         TYPE="sport";
                         }
        invites inv(ID_INVITE,NOM_INVITE,PRENOM_INVITE,FONCTION,DATE_INVITE,TYPE);
        bool test= inv.update();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("modification effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tableView_invite->setModel(E.afficher());
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("modification non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pushButton_search_clicked()
{
    QString variable;
            if(ui->comboBox_emission->currentText()=="ID_EMISSION")
            {
             variable="ID_EMISSION";
            }
            if(ui->comboBox_emission->currentText()=="NOM_EMISSION")
            {
             variable="NOM_EMISSION";
            }
            if(ui->comboBox_emission->currentText()=="TYPE_EMISSION")
            {
             variable="TYPE_EMISSION";
            }
            if(ui->comboBox_emission->currentText()=="DUREE_EMISSION")
            {
             variable="DUREE_EMISSION";
            }
            if(ui->comboBox_emission->currentText()=="DATE_EMISSION")
            {
             variable="DATE_EMISSION";
            }

            EMISSIONS e;
            QSqlQueryModel *model =e.search_emission(ui->lineEdit_search->text(),variable);
            ui->tableView_emission->setModel(model);
}

void Dialog::on_pushButton_Pdf_emission_clicked()
{
        QString id_emission;
        QString NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION;
        QString type,duree;
        id_emission=ui->add_emission_id->text();
        NOM_EMISSION=ui->add_emission_name->text();

        if(ui->add_emission_type_fun->isChecked())
            type="Fun";
        if(ui->add_emission_type_sport->isChecked())
            type="Sport";
        if(ui->add_emission_type_info->isChecked())
            type="Info";
        if(ui->add_emission_duration_5->isChecked())
            duree="5mn";
        if(ui->add_emission_duration_10->isChecked())
            duree="10mn";
        if(ui->add_emission_duration_15->isChecked())
            duree="15mn";

        QDate date = ui->dateTimeEdit_2->date();
        DATE_EMISSION = date.toString();


        QPdfWriter pdf("C:/Users/Aziz/Pictures/Projet2A/pdf/emission.pdf");
        QPainter painter(&pdf);

        painter.setPen(Qt::red);
        painter.drawText(4000,400,"Employee N°:  "+id_emission+"" );
        painter.setPen(Qt::black);
        painter.drawText(3500,1700,"Emission Name :  "+NOM_EMISSION+"" );
        painter.drawText(3500,2100,"Emission Type : "+type+"" );
        painter.drawText(3500,2500,"Emission Duration : "+duree+"" );
        painter.drawText(3500,2900,"Emission Date : "+DATE_EMISSION+"" );


        painter.end();
}

void Dialog::on_pushButton_search_2_clicked()
{
    QString variable;
           if(ui->comboBox_invites->currentText()=="guest id")
           {
            variable="ID_INVITE";
           }
           if(ui->comboBox_invites->currentText()=="guest name")
           {
            variable="NOM_INVITE";
           }
           if(ui->comboBox_invites->currentText()=="guest last name")
           {
            variable="PRENOM_INVITE";
           }
           if(ui->comboBox_invites->currentText()=="guest function")
           {
            variable="FONCTION";
           }
           if(ui->comboBox_emission->currentText()=="type")
           {
            variable="TYPE";
           }

           invites c;
           QSqlQueryModel *model =c.search_invites(ui->lineEdit_search_invite_2->text(),variable);
           ui->tableView_invite->setModel(model);
}

void Dialog::on_pushButton_pdf_invites_clicked()
{
    QString ID_INVITE;
            QString NOM_INVITE,PRENOM_INVITE,FONCTION,TYPE;
            ID_INVITE=ui->lineEdit_guest_id_2->text();
            NOM_INVITE=ui->lineEdit_guest_name_2->text();
             PRENOM_INVITE=ui->lineEdit_guest_last_name_2->text();
            FONCTION=ui->lineEdit_guest_function->text();
            if(ui->fun1->isChecked())
                TYPE="Fun";
            if(ui->sport1->isChecked())
                TYPE="Sport";
            if(ui->info1->isChecked())
                TYPE="Info";

            QPdfWriter pdf("C:/Users/Aziz/Pictures/Projet2A/pdf/invites.pdf");
            QPainter painter(&pdf);

            painter.setPen(Qt::red);
            painter.drawText(4000,400,"invite N°:  "+ID_INVITE+"" );
            painter.setPen(Qt::black);
            painter.drawText(3500,2100,"The first name : "+NOM_INVITE+"" );
            painter.drawText(3500,2500,"The name : "+PRENOM_INVITE+"" );
            painter.drawText(3500,2900,"fonction : "+FONCTION+"" );
            painter.drawText(3500,2900,"type : "+TYPE+"" );


            painter.end();
}

void Dialog::on_refresh_2_clicked()
{
    QString order;
    if(ui->comboBox_invites_2->currentText()=="guest id")
    {
     order="guest id";
    }
    if(ui->comboBox_invites_2->currentText()=="guest name")
    {
     order="guest name";
    }
    if(ui->comboBox_invites_2->currentText()=="guest function")
    {
     order="guest function";
    }
    if(ui->comboBox_invites_2->currentText()=="type")
    {
     order="type";
    }


    invites i;
    QSqlQueryModel *model =i.afficher_guest(order);
    ui->tableView_invite->setModel(model);
    ui->tableView_invite_2->setModel(model);
}

void Dialog::on_afficher_5_clicked()
{


   QString path = ui->lineEdit_2->text();

   if (!path.isEmpty())
      {
          QImage image(path);
          ui->label_18->setPixmap(QPixmap::fromImage(image));
      }

}
void Dialog::on_pushButton_medio_clicked()
{
 QString filename = QFileDialog::getOpenFileName(this,"medio");
 if (filename.isEmpty()){
     return;
 }
 mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
  mMediaPlayer->setVolume(ui->volume->value());
}

void Dialog::on_pushButton_play_clicked()
{
mMediaPlayer->play();
 QMovie *movie3 = new QMovie(":/img/YdBO.gif");
 ui->label_13->setMovie(movie3);
 movie3->start();
}

void Dialog::on_pushButton_pause_clicked()
{
mMediaPlayer->pause();

}

void Dialog::on_pushButton_stop_clicked()
{
mMediaPlayer->stop();

}

void Dialog::on_volume_valueChanged(int value)
{
mMediaPlayer->setVolume(value);
}

void Dialog::on_pushButton_mute_clicked()
{
    if(ui->pushButton_mute->text()=="Mute")
    {
    mMediaPlayer->setMuted(true);
    ui->pushButton_mute->setText("Unmute");
    }
    else {
        mMediaPlayer->setMuted(false);
        ui->pushButton_mute->setText("Mute");
    }
}

void Dialog::on_pushButton_add_guest_2_clicked()
{

}

void Dialog::on_qrcode_clicked()
{

    if(ui->tableView_invite_2->currentIndex().row()==-1)

                  QMessageBox::information(nullptr, QObject::tr("QrCode"),

                                           QObject::tr("Veuillez Choisir un(e) invite(e) du Tableau.\n"

                                                       "Click Ok to exit."), QMessageBox::Ok);

              else

              {

        int ID_INVITE=ui->tableView_invite_2->model()->data(ui->tableView_invite_2->model()->index(ui->tableView_invite_2->currentIndex().row(),0)).toInt();

                           const QrCode qr = QrCode::encodeText(std::to_string(ID_INVITE).c_str(), QrCode::Ecc::LOW);

                           std::ofstream myfile;

                           myfile.open ("qrcode.svg") ;

                           myfile << qr.toSvgString(1);

                           myfile.close();

                           QSvgRenderer svgRenderer(QString("qrcode.svg"));

                           QPixmap pix( QSize(300, 300) );

                           QPainter pixPainter( &pix );

                           svgRenderer.render( &pixPainter );

                           ui->label_14->setPixmap(pix);

           }

    }



int Dialog::on_suivant_2_clicked()
{
    int ID_INVITES =ui->id_invimage->text().toInt();
   // invites inv(ID_INVITES);
    QSqlQuery query;

    return ID_INVITES;
}

void Dialog::on_Ajouter_3_clicked()
{
    int ID_INVITES=on_suivant_2_clicked();

    QString IMAGE_INV=ui->file_6->text();
    invites k(ID_INVITES,IMAGE_INV);
    bool test=k.ajouterimage(ID_INVITES,IMAGE_INV);

    QString PATH=ui->lineEdit_2->text();
    invites k1(ID_INVITES,PATH);
    bool test1=k.ajouterpath(ID_INVITES,PATH);

    if(test){
            //refresh
            ui->tableView_invite->setModel(k.afficher());

            QMessageBox :: information (nullptr, QObject::tr("ok"),
                        QObject::tr("Ajout effectué\n"), QMessageBox::Cancel);



        }else {QMessageBox::critical(nullptr, QObject::tr("non ok"),
                        QObject::tr("Ajout non effectué\n"), QMessageBox::Cancel);
        }
    if(test1){
            //refresh
            ui->tableView_invite->setModel(k.afficher());

            QMessageBox :: information (nullptr, QObject::tr("ok"),
                        QObject::tr("Ajout effectué\n"), QMessageBox::Cancel);



        }else {QMessageBox::critical(nullptr, QObject::tr("non ok"),
                        QObject::tr("Ajout non effectué\n"), QMessageBox::Cancel);
        }
}

void Dialog::on_Ajouter_4_clicked()
{
    int ID_INVITES=on_suivant_2_clicked();

    QString PATH=ui->lineEdit_2->text();
    invites k(ID_INVITES,PATH);
    bool test=k.ajouterpath(ID_INVITES,PATH);


    if(test){
            //refresh
            ui->tableView_invite->setModel(k.afficher());

            QMessageBox :: information (nullptr, QObject::tr("ok"),
                        QObject::tr("Ajout effectué\n"), QMessageBox::Cancel);



        }else {QMessageBox::critical(nullptr, QObject::tr("non ok"),
                        QObject::tr("Ajout non effectué\n"), QMessageBox::Cancel);
        }
}

void Dialog::browse2()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

          ui->file_6->setText( fileListString );

          dialog.setNameFilter(tr("Images(*.png *.xpm *.jpg)"));
          dialog.setViewMode(QFileDialog::Detail);
          QString filename = QFileDialog::getOpenFileName(this,
                                                          tr("Open.Images"),"C:/Users/Aziz/Pictures/",tr("Image Files(*.png *jpg *bmp)"));
         ui->lineEdit_2->setText(filename);
}




void Dialog::on_brows2_clicked()
{
    //filePath=QFileDialog::getExistingDirectory(this, "C:/Users/Youcef/Desktop/Projet2A/LoginApp/img");

//    QDir d = QFileInfo(filePath).absoluteDir();
//    QString absolute=d.absolutePath();


    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images(*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Open.Images"),"C:/Users/Aziz/Pictures/",tr("Image Files(*.png *jpg *bmp)"));

             ui->lineEdit_2->setText(filename);

        if (!filename.isEmpty())
           {
               QImage image(filename);
               ui->label_18->setPixmap(QPixmap::fromImage(image));
           }


}





void Dialog::on_tableView_invite_activated(const QModelIndex &index)
{
    QString val = ui->tableView_invite->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from invites where ID_INVITE='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
        ui->ID_A->setText(qry.value(0).toString());
        ui->N_A->setText(qry.value(1).toString());
        ui->LN_A->setText(qry.value(2).toString());
        ui->F_A->setText(qry.value(3).toString());
        ui->T_A->setText(qry.value(5).toString());
        ui->D_A->setText(qry.value(4).toString());
        ui->lineEdit_2->setText(qry.value(7).toString());

    }
    }
    QString path = ui->lineEdit_2->text();

    if (!path.isEmpty())
       {
           QImage image(path);
           ui->label_18->setPixmap(QPixmap::fromImage(image));
       }

//    else
//    {
//        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
//    }
}

void Dialog::on_Excelexport_clicked()
{
    QString NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION;
        int ID_EMISSION=ui->add_emission_id->text().toInt();

        //int fac[12] = {nvprix, nvprix, nvprix, nvprix, nvprix, nvprix, nvprix, nvprix, nvprix, nvprix, nvprix};
        EMISSIONS E  (ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION);
        bool test = E.ajouter();
        if (test) {
            ui->tableView_emission->setModel(E.afficher());
        }
        QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tableView_emission);
    //janvier, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre;
            //colums to export
            obj.addField(0, "ID_EMISSION", "char(20)");
            obj.addField(1, "NOM_EMISSION", "char(20)");
            obj.addField(2, "TYPE_EMISSION", "char(20)");
            obj.addField(3, "DUREE_EMISSION", "char(20)");
            obj.addField(4, "DATE_EMISSION", "char(20)");






            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString(tr("Exportation paiement par facilité avec succée")).arg(retVal)
                                         );
                bool test2 = E.supprimer(E.getid());;
                if (test2) {

                }
            }
}
void Dialog::on_calendarWidget1_selectionChanged()
{
    QString x=ui->calendarWidget1->selectedDate().toString();
    //QDate x1=ui->calendarWidget1->selectedDate();
    ui->lineEdit_calendar->setText(x);
    ui->tableView_c->setModel(E3.afficher_calendar(x));
}

void Dialog::on_camera_clicked()
{
    ca= new camera();
     ca->show();
     QWidget::close();
}

void Dialog::on_borws_picture_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images(*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open.Images"),"C:/Users/Youcef/Pictures/Capture1",tr("Image Files(*.png *jpg *bmp)"));

    if (!filename.isEmpty())
    {
        QImage image(filename);
        ui->label_pic->setPixmap(QPixmap::fromImage(image));
    }
}

void Dialog::on_page_materiel_customContextMenuRequested(const QPoint &pos)
{

}

void Dialog::on_pushButton_materiel_clicked()
{
 ui->menu_stacked_widget->setCurrentIndex(3);
}

void Dialog::on_tab_materiel_currentChanged(int index)
{

}

void Dialog::on_pushButton_clicked()
{
    QString type=ui->lineEdit_type->text();
    QString marque=ui->lineEdit_marque->text();
    QString id=ui->lineEdit_id->text();
    QString etat=ui->lineEdit_etat->text();
    materiel C(type,marque,id,etat);
    bool test=C.ajouter();
    if (test)
    {
         ui->tableView->setModel(c.afficher());
         Historiques h(type, marque, id, etat, "");
         h.savemateriel();

        QMessageBox::information(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        ui->tableView->setModel(c.afficher());
        QMessageBox::critical(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void Dialog::on_triermaterielBtn_clicked()
{
    QString id="";
    QString type="";
    QString marque="";
    QString etat="";

    materiel c(type,marque,id,etat);
    QString trieOption=ui->materielComboBox->currentText();
     ui->tableView->setModel(c.triermateriel(trieOption));


}

void Dialog::on_statmateriel_clicked()
{
    Statistique_materiel *statistique = new Statistique_materiel();

     statistique->show();
}

void Dialog::on_pdfmateriel_clicked()
{
    QPdfWriter pdf("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/PDF/List_materiel.pdf");

       QPainter painter(&pdf);
       int i = 4100;
      const QImage image(":/img/logo.png");
                   const QPoint imageCoordinates(155,0);
                   int width1 = 1600;
                   int height1 = 1600;
                   QImage img=image.scaled(width1,height1);
                   painter.drawImage(imageCoordinates, img );


              QColor dateColor(255,0,0);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des materiels");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              //painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"id");
              painter.drawText(2000,3600,"type");
              painter.drawText(3300,3600,"marque");
              painter.drawText(4500,3600,"etat");
              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from materiel");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3300,i,query.value(3).toString());
                  painter.drawText(4500,i,query.value(2).toString());

                 i = i + 500;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_historiquemateriel_clicked()
{
    QDesktopServices::openUrl(QUrl(tr("file:///C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/historique.txt")));

}


void Dialog::on_pushButton_2_clicked()
{
    QString id=ui->lineEdit_suppid->text();
     bool test=c.supprime(id);
     if (test)
     {
         materiel c("","","","");
         QSqlQuery materielInfo = c.afficher(id);
         materielInfo.next();
         Historiques h(materielInfo.value(1).toString(), materielInfo.value(2).toString(), materielInfo.value(0).toString(), materielInfo.value(3).toString(), "");
         h.saveDeletemateriel();

         ui->tableView->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                     QObject::tr("delete successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("delete"),
                     QObject::tr("delete failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
}

void Dialog::on_pushButton_3_clicked()
{
    QString id=ui->lineEdit_id_2->text();
QString marque=ui->lineEdit_marque_2->text();
        QString type=ui->lineEdit_type_2->text();
          QString etat=ui->lineEdit_etat_2->text();


          materiel c("","","","");
          QSqlQuery materielInfo = c.afficher(id);
          materielInfo.next();
          Historiques h(materielInfo.value(1).toString(), materielInfo.value(3).toString(), materielInfo.value(0).toString(), materielInfo.value(2).toString(), "");


        materiel C(type,marque,id,etat);
        bool test=C.modifier(id);
        ui->tableView->setModel(c1.afficher());
     if(test){

         h.saveUpdatemateriel(type, marque, id, etat, "");

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }else{
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


     }

}

void Dialog::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->text();
    QString periode=ui->le_periode->text();
    CLIENT C(id,nom,type,periode);

bool test=C.ajouter();
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajouter avec succee.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
ui->table_CLIENT->setModel(C.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("no"),
                QObject::tr("pas ajouter.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pb_triNOM_clicked()
{
      ui->table_CLIENT->setModel(C.triNom());
}

void Dialog::on_pb_triTYPE_clicked()
{
     ui->table_CLIENT->setModel(C.triType());
}

void Dialog::on_pb_supprimer_clicked()
{
    CLIENT C1; C1.setid(ui->le_id_suppr->text().toInt());
    bool test=C1.supprimer(C1.getid());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supprimer avec succee.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->table_CLIENT->setModel(C1.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("no"),
                    QObject::tr("pas supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_lineEdit_rechnom_textChanged(const QString &arg1)
{
    CLIENT C;
                        QString inputValue,filterChecked;
                        inputValue=ui->lineEdit_rechnom->text();
                        ui->table_CLIENT->setModel(C.rechercherdynamique(inputValue,"nom"));
}

void Dialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    CLIENT C;
                        QString inputValue,filterChecked;
                        inputValue=ui->lineEdit_2->text();
                        ui->table_CLIENT->setModel(C.rechercherdynamique(inputValue,"type"));
}

void Dialog::on_pb_Excell_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->table_CLIENT);

    //colums to export
    obj.addField(0, "id", "char(20)");
    obj.addField(1, "name", "char(20)");
    obj.addField(2, "type", "char(20)");
    obj.addField(3, "periode", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void Dialog::on_pb_pdf_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->table_CLIENT->model()->rowCount();
                const int columnCount =ui->table_CLIENT->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("Client")
                        <<  "</head>\n"
                        "<body bgcolor=#159A9C link=#159A9C>\n"
                            "<h1>Liste des clients</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->table_CLIENT->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->table_CLIENT->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->table_CLIENT->isColumnHidden(column)) {
                                   QString data = ui->table_CLIENT->model()->data(ui->table_CLIENT->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/Fourat/Desktop/atelier/Atelier_Connexion/Atelier_Connexion/pdf/mypdffile.pdf");
        document->print(&printer);
}

void Dialog::on_pb_modifier_clicked()
{
    int id=ui->le_id_2->text().toInt();
            QString nom=ui->le_nom_2->text();
            QString type=ui->le_type_2->text();
            QString periode=ui->le_periode_2->text();


            CLIENT C(id,nom,type,periode);
            bool test=C.modifier(id);
         if(test){

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
            ui->table_CLIENT->setModel(C.afficher());
        }else{
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}
}

void Dialog::on_pushButton_browse_email_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->lineEdit_atchmnt_email->setText( fileListString );
}

void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email->clear();
    ui->lineEdit_subject_email->clear();
    ui->lineEdit_atchmnt_email->clear();
    ui->textEdit_email->clear();
    ui->lineEdit_psswrd_email->clear();
}
void Dialog::on_pushButton_send_email_clicked()
{
    //    QSslConfiguration sslCfg = QSslConfiguration::defaultConfiguration();
       //    QList<QSslCertificate> ca_list = sslCfg.caCertificates();
       //    QList<QSslCertificate> ca_new = QSslCertificate::fromData("CaCertificates");
       //    ca_list += ca_new;

       //    sslCfg.setCaCertificates(ca_list);

       //    sslCfg.setProtocol( QSsl::TlsV1SslV3 );

       //    QSslConfiguration::setDefaultConfiguration(sslCfg);

           qDebug() <<  "Loaded SSL Library version: " << QSslSocket::sslLibraryVersionString();

           // ui->lineEdit_to_email->setText("email_ili_bch_tab3athlou@gmail.com");
           // ui->lineEdit_from_email->setText("email_ili_bch_tab3ith_minou@gmail.com");
           // ui->lineEdit_psswrd_email->setText("mdp mta3 l email ili bch tab3th minou");

           // ui->lineEdit_subject_email->setText("test subject");
           // ui->textEdit_email->setText("test text");

           QString from = ui->lineEdit_from_email->text();
           QString to = ui->lineEdit_to_email->text();
           QString subject = ui->lineEdit_subject_email->text();
           QString password = ui->lineEdit_psswrd_email->text();
           QString email_text = ui->textEdit_email->toPlainText();

           Smtp* smtp = new Smtp(from, password);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           if( !files.isEmpty() )
               smtp->sendMail(from, to, subject, email_text, files);
           else
               smtp->sendMail(from, to, subject, email_text);
}

void Dialog::on_pb_QR_clicked()
{
    QDesktopServices::openUrl(QUrl("https://qrcode.tec-it.com/fr"));
     QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
     if (QString::compare(filename,QString()) !=0)
     {
         QImage image;
         bool valid = image.load(filename);
         if(valid)
         {
             image=image.scaledToWidth(ui->label_QR->width(), Qt::SmoothTransformation);
                     ui->label_QR->setPixmap(QPixmap::fromImage(image));
         }
         else
         {
             //ERROR HANDLING
         }
     }
}
