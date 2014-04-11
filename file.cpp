#include "file.h"
#include <iostream>
#include <QMessageBox>
#include <QDomDocument>
using namespace std;

file::~file()
{
}
file::file(QString file_adress) : QWidget()
{

    if (file_adress.at(file_adress.size()-7)=='i') varType = 1 ;
    else if (file_adress.at(file_adress.size()-7)=='c') varType = 0;
    else cerr << "invalid varType"<< endl;

    QDomDocument dom("mon_xml");
    QFile xml_doc(file_adress);
    dom.setContent(&xml_doc);
    QDomElement element = dom.documentElement();
    QDomNode current_root = element.firstChild();
    //QString type = current_root.firstChild().firstChild().toText().nodeValue();



    std::ofstream fichier(QDir::currentPath().toLocal8Bit()+"/../projet/data.txt", ios::out | ios::trunc);

    if( file_adress.at(file_adress.size()-12)== 'n')
    {
        //cout << "probleme non lineaire"<< endl;
        linType = 0;
        fichier<<linType<< endl;
        current_root = current_root.nextSibling().firstChild();
        //QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est " + current_root.nodeName());
        QDomNode tr = current_root.firstChild().nextSibling().nextSibling();
        varNum = tr.firstChild().firstChild().nodeValue().toInt();
        fichier<<varNum<<endl;
        W = tr.firstChild().nextSibling().firstChild().nodeValue().toDouble();
        fichier<<varType<<endl;
        fichier<<W<<endl;
        current_root = current_root.nextSibling().firstChild().nextSibling().nextSibling();
        QDomNodeList tab = current_root.childNodes();
        for (int i=0 ;i<varNum ;++i)
        {
            a.push_back(tab.item(1).firstChild().nodeValue().toDouble());
            b.push_back(tab.item(2).firstChild().nodeValue().toDouble());
            c.push_back(tab.item(3).firstChild().nodeValue().toDouble());
            d.push_back(tab.item(4).firstChild().nodeValue().toDouble());
            p.push_back(tab.item(5).firstChild().nodeValue().toDouble());
            q.push_back(tab.item(6).firstChild().nodeValue().toDouble());
            U.push_back(tab.item(7).firstChild().nodeValue().toDouble());
            current_root = current_root.nextSibling();
            tab = current_root.childNodes();
            fichier << a[i]<< endl<< b[i] <<endl << c[i]<<endl << d[i]<<endl << p[i]<<endl << q[i]<<endl<< U[i] << endl;
        }



    }else if(file_adress.at(file_adress.size()-12)== 'l')
    {
        //fichier << "probleme lineaire"<< endl;
        linType = 1;
        fichier<<linType<< endl;
        current_root = current_root.nextSibling().firstChild();
        //QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est " + current_root.nodeName());
        QDomNode tr = current_root.firstChild().nextSibling().nextSibling();
        varNum = tr.firstChild().firstChild().nodeValue().toInt();
        fichier<<varNum<<endl;
        W = tr.firstChild().nextSibling().firstChild().nodeValue().toDouble();
        fichier << varType <<endl;
        fichier<< W<<endl;
        current_root = current_root.nextSibling().firstChild().nextSibling().nextSibling();
        QDomNodeList tab = current_root.childNodes();
        for (int i=0 ;i<varNum ;++i)
        {
            a.push_back(tab.item(1).firstChild().nodeValue().toDouble());
            b.push_back(tab.item(2).firstChild().nodeValue().toDouble());
            c.push_back(tab.item(3).firstChild().nodeValue().toDouble());
            d.push_back(tab.item(4).firstChild().nodeValue().toDouble());
            w.push_back(tab.item(5).firstChild().nodeValue().toDouble());
            U.push_back(tab.item(6).firstChild().nodeValue().toDouble());
            current_root = current_root.nextSibling();
            tab = current_root.childNodes();
            fichier << a[i]<< endl<< b[i] <<endl << c[i]<<endl << d[i]<<endl<< w[i]<<endl<< U[i] << endl;

        }

    } else
        cout << "ERREUR : fichier mal presente"<< endl;
    fichier.close();


}
