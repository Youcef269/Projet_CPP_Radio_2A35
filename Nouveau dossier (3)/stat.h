#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

namespace Ui {
class stat;
}

class stat : public QDialog
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
    ~stat();
    QList<qreal> stat_liv();
    QList <QString> stat_liv_nom();

private:
    Ui::stat *ui;
};





#endif // STAT_H
