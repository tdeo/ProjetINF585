#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QApplication>
#include <QCoreApplication>
#include <QProcess>

#include <parameters.h>
#include <file.h>
#include <iostream>
#include <string>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QProcess process;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setFile(file *);
    file* getFile();
    parameters getParameters();
    
private:
    file* m_file;
    parameters m_parameters;
    Ui::MainWindow *ui;

private slots:
    void openFile();
    void updateConfigurationNumber();
    void saveTimeLimit();
    void saveConfiguration();
    void loadConfiguration();
    void solve();
};

#endif // MAINWINDOW_H
