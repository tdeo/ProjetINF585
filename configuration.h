#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include<QString>
#include<QList>
#include<QVector>
#include<QDebug>

class configuration
{
public:
    static QVector<QString> algorithmList;
    static QVector<QString> variableSelectionMethodList;
    configuration();
    configuration(QString, int, int, QString);
    configuration(int,int,int,int);
    QString algorithm();
    int rootNumber();
    int nodeNumber();
    QString variableSelectionMethod();
    void setAlgorithm(QString);
    void setAlgorithm(int);
    void setRootNumber(int);
    void setNodeNumber(int);
    void setVariableSelectionMode(QString);
    void setVariableSelectionMode(int);
private:
    QString m_algorithm;
    int m_rootNumber;
    int m_nodeNumber;
    QString m_variableSelectionMethod;
};

#endif // CONFIGURATION_H
