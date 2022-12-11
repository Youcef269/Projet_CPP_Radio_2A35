#ifndef STATISTIQUE_materiel_H
#define STATISTIQUE_materiel_H

#include <QDialog>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class Statistique_materiel;
}

class Statistique_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique_materiel(QWidget *parent = nullptr);
    ~Statistique_materiel();

private slots:
    void on_statmateriel_clicked();

    void on_horizontalFrame_customContextMenuRequested(const QPoint &pos);

    void on_Statistique_materiel_accepted();

private:
    Ui::Statistique_materiel *ui;
};

#endif // STATISTIQUE_materiel_H
