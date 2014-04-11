#include "displayresult.h"
#include <QDir>
#include <QStringList>
#include <QString>

#include <QFile>       // Pour utiliser le fichier
#include <QApplication>
#include <QTextEdit>   // Nous allons tout de mÃªme afficher le contenu du fichier ^^
#include <QTextStream> // Flux sortant du fichier
#include <QList>       // To work with dynamic arrays
#include <QtDebug>
#include <QPointF>

Displayresult::Displayresult()
{

}

bool Displayresult::getData(const QString directory){

    //LIST OF VARIABLES
    QString texte;  // variable to stock the content of the .log file
    QString temp;   // variable to stock (temporary) the relevant substrings (solutions and times of execution)
    float temp_solution, temp_time; //temporary variables to store the solution and the time and add them to the QPointF array
    int debut=0, fin=0; // integers to stock the indices of the beginning and the end of the relevant substrings in the .log file

    // we open the .log file
    QFile fichier(directory);

    //if the file was opened succesfully
    if(fichier.open(QIODevice::ReadOnly)) {

        // Save the content of the file into the texte variable
        texte = fichier.readAll();
        fichier.close();

        // Search the content of texte variable and save the found solutions and execution times into the corresponding dynamic arrays
        int j=0;

        //if solution was found
        if((texte.indexOf("solution of"))!=-1){
          // Get the solutions and the corresponding times of execution and save them into Qlist array Solution
          while((j=texte.indexOf("solution of",j))!=-1) {

            debut=texte.indexOf("solution of ",fin)+13; //get the index of the first character of the (next) solution
            fin=texte.indexOf(" ",debut+1)-1;   //get the index of the last character of the solution
            temp=texte.mid(debut,fin-debut+1);  //extract the part of the string containing the solution
            temp_solution=temp.toFloat();    //save the solution in a variable of type float

            // Extract the time of execution, corresponding to the above solution (same procedure)
            debut=texte.indexOf("(",fin)+1;
            fin=texte.indexOf(" ",debut);
            temp=texte.mid(debut,fin-debut+1);
            temp_time=temp.toFloat();

            // Add the solution and the corresponding time to the QPointF variable solution
            QPointF pointTemp(temp_time,temp_solution);
            solution.append(pointTemp);

            ++j;
           }
         //get the optimal solution

         int k=0;
         k=texte.indexOf("x[0]");
         info=texte.mid(k);
         info=" seconds): "+info;
         info=temp+info;
         info= "Best solution (found in "+info;



        return true;


    }

    else if((texte.indexOf("x[0]"))!=-1) {
                 int k=0;
                 k=texte.indexOf("x[0]");
                 info=texte.mid(k);
                 info= "Best solution (found immediatly): "+info;
                 solution=QList<QPointF> ();
        return true;
    }

    //if only the partial solution exists
    else if((texte.indexOf("Not finished"))!=-1){

        // get the lowerbound
        debut=texte.lastIndexOf("best possible")+15;
        fin=texte.indexOf(")",debut);
        info="No solution found. The last lower bound found: "+texte.mid(debut,fin-debut);

        //get the corresponding time of execution
        debut=texte.indexOf("(",fin)+1;
        fin=texte.indexOf(" second",debut);
        info=info+". Algorithm stopped after "+texte.mid(debut,fin-debut+1)+" seconds.";
        solution=QList<QPointF> ();
        return true;
    }
}
    return false;
}

// Conversion de la solution QList<QPointF> to QPolygonF pour graphique
QPolygonF* Displayresult::solToPolygon() {
    QList<QPointF> sols=solution;
    QPolygonF *points=new QPolygonF;
        while(!sols.isEmpty()) {
            *points << sols.first();
            sols.removeFirst();
}
        return points;
}

// Fonction qui ajoute une courbe sur le graphique plot à partir des points, a couleur fixe
// et légende donnée
void Displayresult::grapher(QwtPlot &plot, const QPolygonF &pts,Qt::GlobalColor color, QString legend){

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle(legend); // Ajout légende
    curve->setPen( color, 4 ); // Pinceau qui trace le graphe
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( color ), QPen( color, 2 ), QSize( 8, 8 ) ); // Ajout des points du graphe
    curve->setSymbol( symbol );
    curve->setSamples( pts );
    curve->attach( &plot );
}


