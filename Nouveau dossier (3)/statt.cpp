#include "statt.h"
#include "ui_statt.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>

statt::statt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statt)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_emp();
     QList<QString> list2=stat_emp_age();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
       QChart *chart =new QChart;
       chart->addSeries(series);
        chart->setTitle("STATS des liv");
        QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}

statt::~statt()
{
    delete ui;
}
QList<qreal> statt::stat_emp()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select age,count(age) from table1 group by age");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> statt::stat_emp_age()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select age,count(age) from table1 group by age");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
