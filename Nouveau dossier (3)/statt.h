#ifndef STATT_H
#define STATT_H

#include <QDialog>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

namespace Ui {
class statt;
}

class statt : public QDialog
{
    Q_OBJECT

public:
    explicit statt(QWidget *parent = nullptr);
    ~statt();
    QList<qreal> stat_emp();
    QList <QString> stat_emp_age();


private:
    Ui::statt *ui;
};

#endif // STATT_H
