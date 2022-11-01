#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
   Employe e(ui->le_id->text().toInt(),ui->le_nom->text(),ui->le_prenom->text(),ui->numTel->text().toInt());
   bool test= e.ajouter();
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

}



void MainWindow::on_supp_clicked()
{

   Employe e;
       int id=ui->le_id_2->text().toInt();
           bool test1=e.supprimer(id);
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



}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView->setModel(em.afficheract());
}
void MainWindow::on_modif_clicked()
{
    Employe e(ui->le_id_2->text().toInt(),ui->le_nom_2->text(),ui->le_prenom_2->text(),ui->numTel_2->text().toInt());
    bool test= e.modifier(ui->le_id_2->text().toInt(),ui->le_nom_2->text(),ui->le_prenom_2->text(),ui->numTel_2->text().toInt());
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
