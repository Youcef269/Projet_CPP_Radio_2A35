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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
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

          int ret=A.connect_arduino(); // lancer la connexion à arduino
          switch(ret){
          case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
             break;
          case(-1):qDebug() << "arduino is not available";
          }
           //le slot update_label suite à la reception du signal readyRead (reception des données).

}

 MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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

void MainWindow::on_pb_modifier_clicked()
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



void MainWindow::on_lineEdit_rechnom_textChanged(const QString &arg1)
{
    CLIENT C;
                        QString inputValue,filterChecked;
                        inputValue=ui->lineEdit_rechnom->text();
                        ui->table_CLIENT->setModel(C.rechercherdynamique(inputValue,"nom"));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    CLIENT C;
                        QString inputValue,filterChecked;
                        inputValue=ui->lineEdit_2->text();
                        ui->table_CLIENT->setModel(C.rechercherdynamique(inputValue,"type"));
}

void MainWindow::on_pb_triNOM_clicked()
{
     ui->table_CLIENT->setModel(C.triNom());
}

void MainWindow::on_pb_triTYPE_clicked()
{
   ui->table_CLIENT->setModel(C.triType());
}












void MainWindow::on_pb_QR_clicked()
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

void MainWindow::on_pb_Excell_clicked()
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

void MainWindow::on_pb_pdf_clicked()
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


void MainWindow::on_pushButton_send_email_clicked()
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

void MainWindow::on_pushButton_browse_email_clicked()
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

void MainWindow::on_pb_arduino_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_pb_valider_clicked()
{
    Notification n;
   Employe e(ui->le_id_6->text().toInt(),ui->le_nom_5->text(),ui->le_prenom_5->text(),ui->numTel_5->text().toInt(),ui->ageEdit_2->text().toInt());
   bool test= e.ajouter();
   n.notification_ajout();

   if(test)
   {
       ui->tableView_2->setModel(e.afficheract());
       QMessageBox::information(nullptr,QObject::tr(" OK"),
                                QObject::tr("Ajout effectuée\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_rechercher_clicked()
{

}

void MainWindow::on_pb_tri_clicked()
{
    QString colone=ui->colone_tri_2->currentText();
        QString ordre=ui->ordre_tri_2->currentText();
     //   Employe L;
        ui->tableView_2->setModel(em.tri(colone,ordre));
}

void MainWindow::on_pb_on_clicked()
{

}


void MainWindow::on_pb_supprimer_yass_clicked()
{
    Notification n;
   Employe e;
       int id=ui->le_id_8->text().toInt();
           bool test1=e.supprimer(id);
           n.notification_supprimer();
       if(test1)
       {
           ui->tableView_2->setModel(e.afficheract());
           QMessageBox::information(nullptr,QObject::tr(" OK"),
                                    QObject::tr("Suppression effectuée\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);


       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Suppression non effectué\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       ui->le_id_8->clear();
        ui->le_nom_6->clear();
          ui->le_prenom_4->clear();
            ui->numTel_4->clear();

}

void MainWindow::on_pb_modif_yas_clicked()
{
    Notification n;

        Employe e(ui->le_id_8->text().toInt(),ui->le_nom_6->text(),ui->le_prenom_4->text(),ui->numTel_4->text().toInt(),ui->ageEdit2_2->text().toInt());
        bool test= e.modifier(ui->le_id_8->text().toInt(),ui->le_nom_6->text(),ui->le_prenom_4->text(),ui->numTel_4->text().toInt(),ui->ageEdit2_2->text().toInt());
        n.notification_modifier();
        if(test)
        {
            ui->tableView_2->setModel(e.afficheract());
            QMessageBox::information(nullptr,QObject::tr(" OK"),
                                     QObject::tr("Modification effectuée\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->le_id_8->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),0)).toString());
        ui->le_nom_6->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),1)).toString());
          ui->le_prenom_4->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),2)).toString());
          ui->numTel_4->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),3)).toString());
          ui->ageEdit2_2->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),4)).toString());

}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
        ui->tableView_2->setModel(em.afficheract());
}


void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
        ui->tableView_2->setModel(em.afficheract());
}

void MainWindow::on_pb_imprimer_yas_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void MainWindow::on_pb_pdf_yas_clicked()
{
        em.genererPDF();
}

void MainWindow::on_le_id_7_textChanged(const QString &arg1)
{
      ui->tableView_2->setModel(em.recherche(arg1));
}




