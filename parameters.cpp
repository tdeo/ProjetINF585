#include "parameters.h"

parameters::parameters()
{
    m_configurationNumber=1;
    m_timelimit=0;
    m_configs=QVector<configuration>(4);
}

int parameters::configurationNumber()
{
    return m_configurationNumber;
}

int parameters::timeLimit()
{
    return m_timelimit;
}

configuration parameters::config(int i)
{
    configuration *data=m_configs.data();
    return data[i];
}

void parameters::setConfigurationNumber(int n)
{
    if(n>=1 && n<=4)
    {
        m_configurationNumber=n;
    }
}

void parameters::setTimeLimit(int n)
{
    m_timelimit=n;
}

void parameters::setConfig(int i,configuration config)
{
    configuration *data=m_configs.data();
    data[i]=config;
}
