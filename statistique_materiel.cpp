#include "statistique_materiel.h"
#include "ui_statistique_materiel.h"
#include "materiel.h"

Statistique_materiel::Statistique_materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique_materiel)
{
    ui->setupUi(this);

    on_statmateriel_clicked();
}

Statistique_materiel::~Statistique_materiel()
{
    delete ui;
}


void Statistique_materiel::on_statmateriel_clicked()
{
    QBarSet *set1 = new QBarSet("nombre de materiels par etat");

    QString id="";
    QString type="";
    QString marque="";
    QString etat="";

     materiel c(type,marque,id,etat);

        *set1 <<  c.statistiquemateriel("0")
              <<  c.statistiquemateriel("1");

            //qDebug()<< c.statistiquemateriel(2);

            QBarSeries *series = new QBarSeries();

            series->append(set1);

            QColor color(255,0,0);
            set1->setColor(color);


            QChart *chart = new QChart();

                chart->addSeries(series);
                chart->setTitle("");
               chart->setBackgroundVisible(false);

                   QStringList categories;
                categories << "0" << "1";
                QBarCategoryAxis *axis = new QBarCategoryAxis();


                axis->append(categories);

                chart->createDefaultAxes();
                chart->setAxisX(axis, series);


                chart->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);


                QChartView *chartView = new QChartView(chart);

                chartView->setRenderHint(QPainter::Antialiasing);
                QPalette pal = qApp->palette();

                chartView->setMaximumWidth(650);
                chartView->setMaximumHeight(290);

                chartView->setParent(ui->horizontalFrame);
                chartView->show();


}

void Statistique_materiel::on_horizontalFrame_customContextMenuRequested(const QPoint &pos)
{

}

void Statistique_materiel::on_Statistique_materiel_accepted()
{

}
