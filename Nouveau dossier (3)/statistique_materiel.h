#ifndef STATISTIQUE_MATERIEL_H
#define STATISTIQUE_MATERIEL_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
namespace Ui {
class statistique_materiel;
}

class statistique_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_materiel(QWidget *parent = nullptr);
    ~statistique_materiel();
private slots:
    void on_statmateriel_clicked();

private:
    Ui::statistique_materiel *ui;
};

#endif // STATISTIQUE_MATERIEL_H
