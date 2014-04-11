#ifndef PARAMETERS_H
#define PARAMETERS_H

#include<QVector>
#include<configuration.h>

class parameters
{
public:
    parameters();
    int configurationNumber();
    int timeLimit();
    configuration config(int);
    void setConfigurationNumber(int);
    void setTimeLimit(int);
    void setConfig(int,configuration);

private:
    int m_configurationNumber;
    int m_timelimit;
    QVector<configuration> m_configs;
};

#endif // PARAMETERS_H
