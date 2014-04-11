#include <QFile>       // Pour utiliser le fichier
#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <QList>       // To work with dynamic arrays
#include <QtDebug>
#include <QDir>
#include "displayresult.h"

int main(int argc, char **argv)
{
    Displayresult display;
    QApplication a(argc, argv);

    QwtPlot plot; // Création du plot qui va contenir les courbes
    plot.setTitle( "Graphique des resultats du solver BONMIN" );
    plot.setCanvasBackground( Qt::white );
    plot.insertLegend( new QwtLegend(), QwtPlot::TopLegend ); // Legende en haut
    plot.setAxisTitle(2,"Temps d'execution de BONMIN");
    plot.setAxisTitle(0,"Valeur de la fonction");

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( &plot ); // Grille de fond

    QPolygonF* points=new QPolygonF;

    //On teste la présence de chaque fichier selon la nomenclature définie. On ajoute légende, couleur adaptée à chaque méthode
    if (display.getData("/home/thierry/Projet_INF585/projet/output0.log")){
        points=display.solToPolygon();
        display.grapher(plot,*points,Qt::red,"Methode 1\n"+display.info);
    }
    if (display.getData("/home/thierry/Projet_INF585/projet/output1.log")){
        points=display.solToPolygon();
        display.grapher(plot,*points,Qt::blue,"Methode 2\n"+display.info);
    }
    if (display.getData("/home/thierry/Projet_INF585/projet/output2.log")){
        points=display.solToPolygon();
        display.grapher(plot,*points,Qt::green,"Methode 3\n"+display.info);
    }
    if (display.getData("/home/thierry/Projet_INF585/projet/output3.log")){
        points=display.solToPolygon();
        display.grapher(plot,*points,Qt::black,"Methode 4\n"+display.info);
    }
    // Affichage de la fenêtre agrandie au maximum.
    plot.showMaximized();



    return a.exec();
}
