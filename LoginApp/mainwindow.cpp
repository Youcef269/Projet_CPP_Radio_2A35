#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QMovie>
#include "compte.h"
#include "state.h"
#include "door.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//   animation = new QPropertyAnimation(ui->label_2,"geometry");
//   animation->setDuration(10000);
//   animation->setStartValue(ui->label_2->geometry());
//   animation->setEndValue(QRect(20,20,0,0));
//   animation->start();

//    QPixmap pix(":/img/icons8-user-48.png");
//    int w = 100;
//    int h = 100;
//    ui->label_user->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


//    QPixmap pix2(":/img/frame no ok.png");
//    int w1 = ui->label_3->width();
//    int h1 = ui->label_3->height();
//    ui->label_3->setPixmap(pix2.scaled(w1,h1,Qt::KeepAspectRatio));

                                    /*user gif*/

    QMovie *movie = new QMovie(":/img/ezgif.com-gif-maker.gif");
   // QLabel *processLabel = new QLabel(this);
   // ui->label_2->setGeometry(100,100,100,100);
    ui->label_2->setMovie(movie);
    movie->start();


   int ret=A.connect_arduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
              break;
           case(-1):qDebug() << "arduino is not available";
           }
            QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_lable())); // permet de lancer
            //le slot update_label suite à la reception du signal readyRead (reception des données).


}

MainWindow::~MainWindow()
{
    delete ui;
    Dialog d;
    compte c;

  }


void MainWindow::on_login_clicked()
{
    compte c;

       QString username = ui->username->text();
       QString password = ui->password->text();

       c.setcompte(ui->username->text());
       Dialog d;




       if((username == "Aziz"|| username=="Youcef")  && password == "radio123")
       {
            //QMessageBox::information(this,"Messgage","test provided");


            dialog = new Dialog(this);
    //        dialog->show();
                d.setcompte(c);
                d.exec();


          // ui->statusbar->showMessage("correct username and password",5000);
       }
       else
       {
           //dialog->hide();
            QMessageBox::warning(this,"Message","incorect username and password");
           //ui->statusbar->showMessage("incorect username and password", 5000);
        }
}


void MainWindow::on_sign_in_push_button_clicked()
{
    QCoreApplication::quit();
//    sign = new sign_in(this);
//    sign->show();
}

void MainWindow::update_lable()
{

data =A.read_from_arduino();
       if(data == "1")
       {

          Dialog d;
          compte c;
          d.setcompte(c);
          d.exec();
}




}

void MainWindow::on_hel_clicked()
{
    A.write_to_arduino("2");
    QString etat="opened";
    state e(etat);




        QSqlQuery query;






    bool test=e.update();
         if(test)
         {
             query.prepare("SELECT * FROM state");
             if(query.exec())
             {
             while (query.next())
             {

             ui->lineEdit_door->setText(query.value(0).toString());

             }

             }
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("update effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
     }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("update non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void MainWindow::on_saker_clicked()
{
    A.write_to_arduino("3");
    QString ETAT="closed";
    state e(ETAT);
    QSqlQuery query;





    bool test=e.update();
         if(test)
         {
             query.prepare("SELECT * FROM state");
             if(query.exec())
             {
             while (query.next())
             {
             ui->lineEdit_door->setText(query.value(0).toString());
             }
             }

             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("update effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
     }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("update non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}



