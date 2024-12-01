/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *matriculeInput;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *kilometrageInput;
    QLineEdit *modeleInput;
    QLineEdit *marqueInput;
    QDateEdit *dateArrivageInput;
    QDateEdit *dateSortieInput;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *ajouterButton;
    QPushButton *supprimerButton;
    QPushButton *modifierButton;
    QLineEdit *tt;
    QPushButton *pushButton;
    QLineEdit *matriculeInput_3;
    QPushButton *pushButton_2;
    QTableView *tableView_2;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1004, 783);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-10, -10, 881, 551));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 81, 20));
        matriculeInput = new QLineEdit(groupBox);
        matriculeInput->setObjectName("matriculeInput");
        matriculeInput->setGeometry(QRect(140, 80, 113, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 80, 71, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 150, 101, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 80, 81, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 210, 141, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 150, 131, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(550, 150, 111, 20));
        kilometrageInput = new QLineEdit(groupBox);
        kilometrageInput->setObjectName("kilometrageInput");
        kilometrageInput->setGeometry(QRect(140, 150, 131, 21));
        modeleInput = new QLineEdit(groupBox);
        modeleInput->setObjectName("modeleInput");
        modeleInput->setGeometry(QRect(560, 80, 113, 26));
        marqueInput = new QLineEdit(groupBox);
        marqueInput->setObjectName("marqueInput");
        marqueInput->setGeometry(QRect(330, 80, 113, 26));
        dateArrivageInput = new QDateEdit(groupBox);
        dateArrivageInput->setObjectName("dateArrivageInput");
        dateArrivageInput->setGeometry(QRect(430, 150, 110, 26));
        dateSortieInput = new QDateEdit(groupBox);
        dateSortieInput->setObjectName("dateSortieInput");
        dateSortieInput->setGeometry(QRect(680, 150, 91, 26));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 30, 891, 541));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Design sans titre (3) (1).png")));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(460, 540, 101, 20));
        ajouterButton = new QPushButton(groupBox);
        ajouterButton->setObjectName("ajouterButton");
        ajouterButton->setGeometry(QRect(30, 260, 221, 41));
        supprimerButton = new QPushButton(groupBox);
        supprimerButton->setObjectName("supprimerButton");
        supprimerButton->setGeometry(QRect(30, 310, 221, 41));
        modifierButton = new QPushButton(groupBox);
        modifierButton->setObjectName("modifierButton");
        modifierButton->setGeometry(QRect(40, 370, 221, 41));
        tt = new QLineEdit(groupBox);
        tt->setObjectName("tt");
        tt->setGeometry(QRect(200, 210, 113, 26));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(750, 480, 93, 28));
        matriculeInput_3 = new QLineEdit(groupBox);
        matriculeInput_3->setObjectName("matriculeInput_3");
        matriculeInput_3->setGeometry(QRect(590, 480, 113, 26));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 300, 93, 28));
        tableView_2 = new QTableView(groupBox);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(590, 210, 256, 192));
        label_8->raise();
        label->raise();
        matriculeInput->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        kilometrageInput->raise();
        modeleInput->raise();
        marqueInput->raise();
        dateArrivageInput->raise();
        dateSortieInput->raise();
        label_9->raise();
        ajouterButton->raise();
        supprimerButton->raise();
        modifierButton->raise();
        tt->raise();
        pushButton->raise();
        matriculeInput_3->raise();
        pushButton_2->raise();
        tableView_2->raise();
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 510, 871, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1004, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AUTO-CARE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Matricule</span></p></body></html>", nullptr));
        matriculeInput->setText(QCoreApplication::translate("MainWindow", "135 tun 4789", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">marque</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Kilom\303\251trage</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Mod\303\251le</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Type de la panne</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Date d'arrivage</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Date de sortie</span></p></body></html>", nullptr));
        kilometrageInput->setText(QCoreApplication::translate("MainWindow", "123", nullptr));
        modeleInput->setText(QCoreApplication::translate("MainWindow", "q5", nullptr));
        marqueInput->setText(QCoreApplication::translate("MainWindow", "bmw", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic; text-decoration: underline; color:#5555ff;\">Kilom\303\251trage</span></p></body></html>", nullptr));
        ajouterButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        supprimerButton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        modifierButton->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "stat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
