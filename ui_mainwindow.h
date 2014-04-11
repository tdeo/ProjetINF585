/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *fileLayout;
    QLabel *fileLabel;
    QLineEdit *fileField;
    QPushButton *fileButton;
    QFormLayout *generalOptionsLayout;
    QLabel *timeLimitLabel;
    QSpinBox *timeLimitField;
    QLabel *configurationNumberLabel;
    QSpinBox *configurationNumberField;
    QLabel *configurationChooserLabel;
    QHBoxLayout *configurationChoosetLayout;
    QRadioButton *config1Button;
    QRadioButton *config2Button;
    QRadioButton *config3Button;
    QRadioButton *config4Button;
    QFormLayout *formLayout;
    QLabel *algorithmLabel;
    QComboBox *algorithmField;
    QLabel *rootNumberLabel;
    QSpinBox *rootNumberField;
    QLabel *nodeNumberLabel;
    QSpinBox *nodeNumberField;
    QLabel *variableSelectionLabel;
    QComboBox *variableSelectionField;
    QPushButton *solveButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(473, 388);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 451, 353));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QStringLiteral("fileLayout"));
        fileLabel = new QLabel(verticalLayoutWidget);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));

        fileLayout->addWidget(fileLabel);

        fileField = new QLineEdit(verticalLayoutWidget);
        fileField->setObjectName(QStringLiteral("fileField"));

        fileLayout->addWidget(fileField);

        fileButton = new QPushButton(verticalLayoutWidget);
        fileButton->setObjectName(QStringLiteral("fileButton"));

        fileLayout->addWidget(fileButton);


        verticalLayout->addLayout(fileLayout);

        generalOptionsLayout = new QFormLayout();
        generalOptionsLayout->setSpacing(6);
        generalOptionsLayout->setObjectName(QStringLiteral("generalOptionsLayout"));
        generalOptionsLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        timeLimitLabel = new QLabel(verticalLayoutWidget);
        timeLimitLabel->setObjectName(QStringLiteral("timeLimitLabel"));

        generalOptionsLayout->setWidget(0, QFormLayout::LabelRole, timeLimitLabel);

        timeLimitField = new QSpinBox(verticalLayoutWidget);
        timeLimitField->setObjectName(QStringLiteral("timeLimitField"));
        timeLimitField->setMaximum(1800);

        generalOptionsLayout->setWidget(0, QFormLayout::FieldRole, timeLimitField);

        configurationNumberLabel = new QLabel(verticalLayoutWidget);
        configurationNumberLabel->setObjectName(QStringLiteral("configurationNumberLabel"));
        configurationNumberLabel->setEnabled(true);

        generalOptionsLayout->setWidget(1, QFormLayout::LabelRole, configurationNumberLabel);

        configurationNumberField = new QSpinBox(verticalLayoutWidget);
        configurationNumberField->setObjectName(QStringLiteral("configurationNumberField"));
        configurationNumberField->setMinimum(1);
        configurationNumberField->setMaximum(4);

        generalOptionsLayout->setWidget(1, QFormLayout::FieldRole, configurationNumberField);


        verticalLayout->addLayout(generalOptionsLayout);

        configurationChooserLabel = new QLabel(verticalLayoutWidget);
        configurationChooserLabel->setObjectName(QStringLiteral("configurationChooserLabel"));

        verticalLayout->addWidget(configurationChooserLabel);

        configurationChoosetLayout = new QHBoxLayout();
        configurationChoosetLayout->setSpacing(6);
        configurationChoosetLayout->setObjectName(QStringLiteral("configurationChoosetLayout"));
        config1Button = new QRadioButton(verticalLayoutWidget);
        config1Button->setObjectName(QStringLiteral("config1Button"));
        config1Button->setChecked(true);

        configurationChoosetLayout->addWidget(config1Button);

        config2Button = new QRadioButton(verticalLayoutWidget);
        config2Button->setObjectName(QStringLiteral("config2Button"));
        config2Button->setEnabled(false);
        config2Button->setCheckable(true);

        configurationChoosetLayout->addWidget(config2Button);

        config3Button = new QRadioButton(verticalLayoutWidget);
        config3Button->setObjectName(QStringLiteral("config3Button"));
        config3Button->setEnabled(false);

        configurationChoosetLayout->addWidget(config3Button);

        config4Button = new QRadioButton(verticalLayoutWidget);
        config4Button->setObjectName(QStringLiteral("config4Button"));
        config4Button->setEnabled(false);

        configurationChoosetLayout->addWidget(config4Button);


        verticalLayout->addLayout(configurationChoosetLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        algorithmLabel = new QLabel(verticalLayoutWidget);
        algorithmLabel->setObjectName(QStringLiteral("algorithmLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, algorithmLabel);

        algorithmField = new QComboBox(verticalLayoutWidget);
        algorithmField->setObjectName(QStringLiteral("algorithmField"));

        formLayout->setWidget(1, QFormLayout::FieldRole, algorithmField);

        rootNumberLabel = new QLabel(verticalLayoutWidget);
        rootNumberLabel->setObjectName(QStringLiteral("rootNumberLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rootNumberLabel);

        rootNumberField = new QSpinBox(verticalLayoutWidget);
        rootNumberField->setObjectName(QStringLiteral("rootNumberField"));
        rootNumberField->setMaximum(999999999);

        formLayout->setWidget(2, QFormLayout::FieldRole, rootNumberField);

        nodeNumberLabel = new QLabel(verticalLayoutWidget);
        nodeNumberLabel->setObjectName(QStringLiteral("nodeNumberLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, nodeNumberLabel);

        nodeNumberField = new QSpinBox(verticalLayoutWidget);
        nodeNumberField->setObjectName(QStringLiteral("nodeNumberField"));
        nodeNumberField->setMaximum(999999999);

        formLayout->setWidget(3, QFormLayout::FieldRole, nodeNumberField);

        variableSelectionLabel = new QLabel(verticalLayoutWidget);
        variableSelectionLabel->setObjectName(QStringLiteral("variableSelectionLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, variableSelectionLabel);

        variableSelectionField = new QComboBox(verticalLayoutWidget);
        variableSelectionField->setObjectName(QStringLiteral("variableSelectionField"));

        formLayout->setWidget(4, QFormLayout::FieldRole, variableSelectionField);


        verticalLayout->addLayout(formLayout);

        solveButton = new QPushButton(verticalLayoutWidget);
        solveButton->setObjectName(QStringLiteral("solveButton"));

        verticalLayout->addWidget(solveButton);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nonlinear Knapsack problem solver", 0));
        fileLabel->setText(QApplication::translate("MainWindow", "File :", 0));
        fileButton->setText(QApplication::translate("MainWindow", "...", 0));
        timeLimitLabel->setText(QApplication::translate("MainWindow", "Time limit (in seconds)", 0));
        configurationNumberLabel->setText(QApplication::translate("MainWindow", "Number of Configurations", 0));
        configurationChooserLabel->setText(QApplication::translate("MainWindow", "Configuration number shown below:", 0));
        config1Button->setText(QApplication::translate("MainWindow", "1", 0));
        config2Button->setText(QApplication::translate("MainWindow", "2", 0));
        config3Button->setText(QApplication::translate("MainWindow", "3", 0));
        config4Button->setText(QApplication::translate("MainWindow", "4", 0));
        algorithmLabel->setText(QApplication::translate("MainWindow", "Algorithm", 0));
        algorithmField->clear();
        algorithmField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "B-BB: Simple Branch and Bound", 0)
         << QApplication::translate("MainWindow", "B-OA: OA Decomposition", 0)
         << QApplication::translate("MainWindow", "B-QG: Quesada and Grossmann", 0)
         << QApplication::translate("MainWindow", "B-Hyb: Hybrid", 0)
        );
        rootNumberLabel->setText(QApplication::translate("MainWindow", "Number resolve at root", 0));
        nodeNumberLabel->setText(QApplication::translate("MainWindow", "Number resolve at node", 0));
        variableSelectionLabel->setText(QApplication::translate("MainWindow", "Variable selection mode", 0));
        variableSelectionField->clear();
        variableSelectionField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Most Fractional", 0)
         << QApplication::translate("MainWindow", "Strong Branching", 0)
         << QApplication::translate("MainWindow", "Reliability Branching", 0)
         << QApplication::translate("MainWindow", "QP Strong Branching", 0)
         << QApplication::translate("MainWindow", "LP Strong Branching", 0)
         << QApplication::translate("MainWindow", "NLP Strong Branching", 0)
         << QApplication::translate("MainWindow", "Osi simple", 0)
         << QApplication::translate("MainWindow", "Osi strong", 0)
         << QApplication::translate("MainWindow", "Random", 0)
        );
        solveButton->setText(QApplication::translate("MainWindow", "Solve problem", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
