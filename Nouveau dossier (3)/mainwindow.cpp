#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QMessageBox"
#include<QPrinter>
#include<QPrintDialog>
#include "notification.h"
#include "arduino.h"
#include "historiques.h"
#include "statistique_materiel.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     ui->tableView->setModel(em.afficheract());

     //le slot update_label suite à la reception du signal readyRead (reception des données).
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    Notification n;
   Employe e(ui->le_id->text().toInt(),ui->le_nom->text(),ui->le_prenom->text(),ui->numTel->text().toInt(),ui->ageEdit->text().toInt());
   bool test= e.ajouter();
   n.notification_ajout();

   if(test)
   {
       ui->tableView->setModel(e.afficheract());
       QMessageBox::information(nullptr,QObject::tr(" OK"),
                                QObject::tr("Ajout effectuée\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);


   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                QObject::tr("Ajout non effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);


   ui->le_id->clear();
    ui->le_nom->clear();
      ui->le_prenom->clear();
        ui->numTel->clear();
        ui->ageEdit->clear();

}



void MainWindow::on_supp_clicked()
{
    Notification n;
   Employe e;
       int id=ui->le_id_2->text().toInt();
           bool test1=e.supprimer(id);
           n.notification_supprimer();
       if(test1)
       {
           ui->tableView->setModel(e.afficheract());
           QMessageBox::information(nullptr,QObject::tr(" OK"),
                                    QObject::tr("Suppression effectuée\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);


       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Suppression non effectué\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       ui->le_id_2->clear();
        ui->le_nom_2->clear();
          ui->le_prenom_2->clear();
            ui->numTel_2->clear();






}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->le_id_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
        ui->le_nom_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
          ui->le_prenom_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
          ui->numTel_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
          ui->ageEdit2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());




}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView->setModel(em.afficheract());
}
void MainWindow::on_modif_clicked()
{   Notification n;

    Employe e(ui->le_id_2->text().toInt(),ui->le_nom_2->text(),ui->le_prenom_2->text(),ui->numTel_2->text().toInt(),ui->ageEdit2->text().toInt());
    bool test= e.modifier(ui->le_id_2->text().toInt(),ui->le_nom_2->text(),ui->le_prenom_2->text(),ui->numTel_2->text().toInt(),ui->ageEdit2->text().toInt());
    n.notification_modifier();
    if(test)
    {
        ui->tableView->setModel(e.afficheract());
        QMessageBox::information(nullptr,QObject::tr(" OK"),
                                 QObject::tr("Modification effectuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Modification non effectué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);


    ui->le_id_2->clear();
     ui->le_nom_2->clear();
       ui->le_prenom_2->clear();
         ui->numTel_2->clear();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->tableView->setModel(em.afficheract());
}

/*void MainWindow::on_Trier_clicked()
{
   /* Employe e;
    ui->tableView->setModel(e.trier());


}
*/


void MainWindow::on_pushButton_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void MainWindow::on_pushButton_2_clicked()
{
    em.genererPDF();
}

void MainWindow::on_le_id_3_textChanged(const QString &arg1)
{
    ui->tableView->setModel(em.recherche(arg1));
}

void MainWindow::on_pushButton_3_clicked()
{
    stat_emp=new statt(this);
    stat_emp->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
     //   Employe L;
        ui->tableView->setModel(em.tri(colone,ordre));
}

void MainWindow::on_on_6_clicked()
{
    A.write_to_arduino("0");
        A.write_to_arduino("0");
            A.write_to_arduino("0");
                A.write_to_arduino("0");
                    A.write_to_arduino("0");
                        A.write_to_arduino("0");
     A.write_to_arduino("1");
}




void MainWindow::on_tabWidget_2_currentChanged(int index)
{
     ui->tableView->setModel(em.afficheract());
}

void MainWindow::on_pushButton_5_clicked()
{
    QString type=ui->lineEdit_type->text();
    QString marque=ui->lineEdit_marque->text();
    QString id=ui->lineEdit_id->text();
    QString etat=ui->lineEdit_etat->text();
    materiel C(type,marque,id,etat);
    bool test=C.ajouter();
    if (test)
    {
         ui->tableView_2->setModel(c.afficher());
         Historiques h(type, marque, id, etat, "");
         h.savemateriel();

        QMessageBox::information(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        ui->tableView_2->setModel(c.afficher());
        QMessageBox::critical(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_statmateriel_clicked()
{
    statistique_materiel *statistique = new statistique_materiel();

     statistique->show();

}

void MainWindow::on_pdfmateriel_clicked()
{
    QPdfWriter pdf("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/PDF/List_materiel.pdf");

       QPainter painter(&pdf);
       int i = 4100;
      const QImage image("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/IMG/logo.png");
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

void MainWindow::on_historiquemateriel_clicked()
{
     QDesktopServices::openUrl(QUrl(tr("file:///C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/historique.txt")));
}

void MainWindow::on_materielachet_clicked()
{
    QString id="";
    QString type="";
    QString marque="";
    QString etat="";

    materiel c(type,marque,id,etat);

    int maxtype= c.materielachet();
    QString max = QString::number(maxtype);

     //QString idmaterielachet = c.materielachetDetails();
     //qDebug() << "idmaxtype" << idmaterielachet ;

    QSqlQuery materielInfo = c.materielachetDetails();
    materielInfo.next();



    qDebug() << "maxtype" << max ;


    ui->nbachetLabel->setText(max);


}

void MainWindow::on_triermaterielBtn_clicked()
{
    QString id="";
    QString type="";
    QString marque="";
    QString etat="";

    materiel c(type,marque,id,etat);
    QString trieOption=ui->materielComboBox->currentText();
     ui->tableView_2->setModel(c.triermateriel(trieOption));
}

void MainWindow::on_recherchermateriel_textChanged(const QString &arg1)
{
    QString chaine_c=ui->recherchermateriel->text();

    QString id="";
    QString type="";
    QString marque="";
    QString etat="";

    materiel c(type,marque,id,etat);

    if(chaine_c !="")
    {
    ui->tableView_2->setModel(c.recherchermateriel(chaine_c));
    }
    else
    {
        QString trieOption=ui->materielComboBox->currentText();
        ui->tableView_2->setModel(c.triermateriel(trieOption));
    }
}

void MainWindow::on_pushButton_7_clicked()
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
        ui->tableView_2->setModel(c1.afficher());
     if(test){

         h.saveUpdatemateriel(type, marque, id, etat, "");

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }else{
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


     }

}

void MainWindow::on_pushButton_6_clicked()
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

         ui->tableView_2->setModel(c.afficher());
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
