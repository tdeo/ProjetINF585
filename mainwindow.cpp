#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

using namespace std;

extern string projectPath;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_parameters=parameters();
    ui->setupUi(this);
    connect(ui->fileButton,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->timeLimitField,SIGNAL(valueChanged(int)),this,SLOT(saveTimeLimit()));
    connect(ui->configurationNumberField,SIGNAL(valueChanged(int)),this,SLOT(updateConfigurationNumber()));
    connect(ui->algorithmField,SIGNAL(currentIndexChanged(int)),this,SLOT(saveConfiguration()));
    connect(ui->nodeNumberField,SIGNAL(valueChanged(int)),this,SLOT(saveConfiguration()));
    connect(ui->rootNumberField,SIGNAL(valueChanged(int)),this,SLOT(saveConfiguration()));
    connect(ui->variableSelectionField,SIGNAL(currentIndexChanged(int)),this,SLOT(saveConfiguration()));
    connect(ui->config1Button,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(ui->config2Button,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(ui->config3Button,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(ui->config4Button,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(ui->solveButton,SIGNAL(clicked()),this,SLOT(solve()));
}

file* MainWindow::getFile()
{
    return m_file;
}

parameters MainWindow::getParameters()
{
    return m_parameters;
}

void MainWindow::setFile(file* fichier)
{
    m_file=fichier;
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Pick a file", QString(), "");
    ui->fileField->setText(path);
}

void MainWindow::saveTimeLimit()
{
    m_parameters.setTimeLimit(ui->timeLimitField->value());
}

void MainWindow::updateConfigurationNumber()
{
    if (ui->configurationNumberField->value()==1){
        m_parameters.setConfigurationNumber(1);
        ui->config1Button->setEnabled(true);
        ui->config2Button->setEnabled(false);
        ui->config3Button->setEnabled(false);
        ui->config4Button->setEnabled(false);
    } else if (ui->configurationNumberField->value()==2){
        m_parameters.setConfigurationNumber(2);
        ui->config1Button->setEnabled(true);
        ui->config2Button->setEnabled(true);
        ui->config3Button->setEnabled(false);
        ui->config4Button->setEnabled(false);
    } else if (ui->configurationNumberField->value()==3){
        m_parameters.setConfigurationNumber(3);
        ui->config1Button->setEnabled(true);
        ui->config2Button->setEnabled(true);
        ui->config3Button->setEnabled(true);
        ui->config4Button->setEnabled(false);
    } else if (ui->configurationNumberField->value()==4){
        m_parameters.setConfigurationNumber(4);
        ui->config1Button->setEnabled(true);
        ui->config2Button->setEnabled(true);
        ui->config3Button->setEnabled(true);
        ui->config4Button->setEnabled(true);
    }
}

void MainWindow::saveConfiguration()
{
    int i=-1;
    if(ui->config1Button->isChecked()){
        i=0;
    } else if(ui->config2Button->isChecked()){
        i=1;
    } else if(ui->config3Button->isChecked()){
        i=2;
    } else if(ui->config4Button->isChecked()){
        i=3;
    }
    if(i!=-1){
        m_parameters.setConfig(i,configuration(ui->algorithmField->currentIndex(),ui->rootNumberField->value(),ui->nodeNumberField->value(),ui->variableSelectionField->currentIndex()));
    }
    ofstream fichier(QDir::currentPath().toLocal8Bit()+"/../projet/config.txt", ios::out | ios::trunc);
    fichier << m_parameters.timeLimit() << endl << m_parameters.configurationNumber()<<endl;
    for(int j=0;j<m_parameters.configurationNumber();j++){
        fichier << m_parameters.config(j).algorithm().toStdString() << endl << m_parameters.config(j).rootNumber() << endl <<  m_parameters.config(j).nodeNumber() << endl <<  m_parameters.config(j).variableSelectionMethod().toStdString()<<endl;
    }
}

void MainWindow::loadConfiguration()
{
    int i=-1;
    if(ui->config1Button->isChecked()){
        i=0;
    } else if(ui->config2Button->isChecked()){
        i=1;
    }else if(ui->config3Button->isChecked()){
        i=2;
    }else if(ui->config4Button->isChecked()){
        i=3;
    }
    if(i!=-1){
        int algo=configuration::algorithmList.indexOf(m_parameters.config(i).algorithm());
        int node=m_parameters.config(i).nodeNumber();
        int root=m_parameters.config(i).rootNumber();
        int variable=configuration::variableSelectionMethodList.indexOf(m_parameters.config(i).variableSelectionMethod());
        ui->algorithmField->setCurrentIndex(algo);
        ui->nodeNumberField->setValue(node);
        ui->rootNumberField->setValue(root);
        ui->variableSelectionField->setCurrentIndex(variable);
    }
}

void MainWindow::solve()
{
    saveConfiguration();
    QRegExp zou (".xml");
    if(ui->fileField->text().contains(zou)){
        //on lit le .xml
        file* zou=new file(ui->fileField->text());
        setFile(zou);
        qDebug()<<ui->fileField->text();

        process.start(QDir::currentPath().toLocal8Bit()+"/../projet/Solver/SolverBonmin");
        //qDebug() << process.readAllStandardOutput();
        process.waitForFinished();

        //et finalement, on affiche tout !
        process.start(QDir::currentPath().toLocal8Bit()+"/../projet/Grapher/Grapher");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
