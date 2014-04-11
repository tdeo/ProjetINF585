#ifndef FILE_H
#define FILE_H
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <iostream>
#include <string>
#include <fstream>

class file : public QWidget
{
public:
    file();
    int linType; //contraintes lineaires ou pas
    int varNum; //taille des vecteurs
    int varType; //variable continue ou entiere
    double W; //0<g<W
    QVector <double> U,a,b,c,d,p,q,w;
    file(QString file_adress);
    ~file();


};
#endif // FILE_H
