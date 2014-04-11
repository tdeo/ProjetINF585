#ifndef DISPLAYRESULT_H
#define DISPLAYRESULT_H
#include <QPointF>
#include <QList>

#include <QDir>
#include <QStringList>
#include <QString>

#include <QFile>       // Pour utiliser le fichier
#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QTextStream> // Flux sortant du fichier
#include <QList>       // To work with dynamic arrays
#include <QtDebug>

#include </usr/local/qwt-6.1.0-rc3/include/qwt_plot.h>
#include </usr/local/qwt-6.1.0-rc3/include/qwt_plot_curve.h>
#include </usr/local/qwt-6.1.0-rc3/include/qwt_plot_grid.h>
#include </usr/local/qwt-6.1.0-rc3/include/qwt_symbol.h>
#include </usr/local/qwt-6.1.0-rc3/include/qwt_legend.h>


class Displayresult
{
public:

    Displayresult();
    bool getData(QString directory);
    QPolygonF* solToPolygon();
    void grapher(QwtPlot &plot, const QPolygonF &pts,Qt::GlobalColor color,QString legend);
    QString info;
    QList< QPointF > solution;
};



#endif // DISPLAYRESULT_H
