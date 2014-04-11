#include "configuration.h"

QVector<QString> configuration::algorithmList = QVector<QString>()<<"B-BB"<<"B-OA"<<"B-QG"<<"B-Hyb";
QVector<QString> configuration::variableSelectionMethodList = QVector<QString>()<<"most-fractional"<<"strong-branching"<<"reliability-branching"<<"qp-strong-branching"<<"lp-strong-branching"<<"nlp-strong-branching"<<"osi-simple"<<"osi-strong"<<"random";

configuration::configuration()
{
    m_algorithm="B-BB";
    m_rootNumber=0;
    m_nodeNumber=0;
    m_variableSelectionMethod="strong-branching";
}

configuration::configuration(QString algo, int root, int node, QString variable)
{
    m_algorithm=algo;
    m_rootNumber=root;
    m_nodeNumber=node;
    m_variableSelectionMethod=variable;
}

configuration::configuration(int algo, int root, int node, int variable)
{
    m_algorithm=configuration::algorithmList[algo];
    m_rootNumber=root;
    m_nodeNumber=node;
    m_variableSelectionMethod=configuration::variableSelectionMethodList[variable];
}

QString configuration::algorithm(){
    return m_algorithm;
}

int configuration::rootNumber(){
    return m_rootNumber;
}

int configuration::nodeNumber(){
    return m_nodeNumber;
}

QString configuration::variableSelectionMethod()
{
    return m_variableSelectionMethod;
}

void configuration::setAlgorithm(QString algo)
{
    if(configuration::algorithmList.contains(algo)){
        m_algorithm=algo;
    }
}

void configuration::setAlgorithm(int i)
{
    if(i>=0 && i<=3){
        m_algorithm=configuration::algorithmList.value(i);
    }
}

void configuration::setRootNumber(int root)
{
    m_rootNumber=root;
}

void configuration::setNodeNumber(int node)
{
    m_nodeNumber=node;
}

void configuration::setVariableSelectionMode(QString mode)
{
    if(configuration::variableSelectionMethodList.contains(mode)){
        m_variableSelectionMethod=mode;
    }
}

void configuration::setVariableSelectionMode(int i)
{
    if(i>=0 && i<=8){
        m_variableSelectionMethod=configuration::variableSelectionMethodList.value(i);
    }
}


