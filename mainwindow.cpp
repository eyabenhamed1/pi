#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voiture.h"
#include <QMessageBox>
#include <QtCharts>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(arduinoo()));//automatique read mel arduino

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::arduinoo() {
    //eya
        QString data = A.read_from_arduino();
        if (!data.isEmpty()) {
            bool isValidCode = verifyCode(data);
            if (isValidCode) {
                qDebug() << "Code valide : " << data;
                //aymen
                A.write_to_arduino("0");
                 QMessageBox::information(this, "reussie ", "matricule : "+data+" existe dans la  base");

            } else {

                qDebug() << "Code invalide : " << data;
                QMessageBox::warning(this, "reussie ", "matricule : "+data+" n'existe pas dans la  base");
            }
        }

}
//eya
bool MainWindow::verifyCode(QString data)
{
    QSqlQuery query;

    qDebug() << "Preparing query to verify code:" << data; // Debug input data
    query.prepare("SELECT * FROM VOITURE WHERE matricule = :code");
    query.bindValue(":code", data);

    if (query.exec()) {
        qDebug() << "Query executed successfully.";
        if (query.next()) {
            qDebug() << "Code found in database:" << data;
            return true; // Code exists in the database
        } else {
            qDebug() << "Code not found in database:" << data;
        }
    } else {
        qDebug() << "Query execution error:" ;
    }

    return false; // Code not found or query execution failed
}

void MainWindow::on_ajouterButton_clicked()
{
    QString MATRICULE=ui->matriculeInput->text();
    QString MARQUE=ui->marqueInput->text();
    QString MODELE=ui->modeleInput->text();
    QString KILOMETRAGE=ui->kilometrageInput->text();
    QString DATE_ARRIVAGE=ui->dateArrivageInput->date().toString();
    QDate DATE_SORTIE=ui->dateSortieInput->date();
    QString TYPE_DE_PANNE=ui->comboBox->currentText();
    QRegularExpression matriculeRegex(R"(^\d{4} [A-Z]{3} \d{3}$)");

    voiture v(MATRICULE,MARQUE,MODELE,KILOMETRAGE,DATE_ARRIVAGE,DATE_SORTIE,TYPE_DE_PANNE);
    if(MATRICULE =="" || MARQUE =="" || MODELE =="" || KILOMETRAGE =="" || DATE_ARRIVAGE =="" || TYPE_DE_PANNE =="" )
    {
        QMessageBox::critical(nullptr, QObject::tr("erreur"),
                    QObject::tr("veuillez remplir les champs\n"), QMessageBox::Cancel);
    }
    else{
        if(TYPE_DE_PANNE!="mecanique" && TYPE_DE_PANNE!="electrique" && TYPE_DE_PANNE!="vidange" && TYPE_DE_PANNE!="autre" ){
            QMessageBox::critical(nullptr, QObject::tr("erreur"),
                        QObject::tr("le type doit etre mecanique ou electrique ou vidange ou autre"), QMessageBox::Cancel);
        }
        else{
            if(!matriculeRegex.match(MATRICULE).hasMatch())
            {
                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                            QObject::tr("la matricule doit etre comme ca xxxx TUN xxx"), QMessageBox::Cancel);
            }
            else{
                if(KILOMETRAGE.contains(QRegExp("[^0-9]")))
                {
                    QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                QObject::tr("le kilometrage doit contient que de nombre"), QMessageBox::Cancel);
                }
                else{
        v.ajouter();
        ui->tableView->setModel(v.afficher());
                }
            }
        }
    }

}

void MainWindow::on_supprimerButton_clicked()
{
    QString MATRICULE=ui->matriculeInput->text();
    voiture v;
    v.supprimer(MATRICULE);
    ui->tableView->setModel(v.afficher());
}

void MainWindow::on_modifierButton_clicked()
{
    QString MATRICULE=ui->matriculeInput->text();
    QString MARQUE=ui->marqueInput->text();
    QString MODELE=ui->modeleInput->text();
    QString KILOMETRAGE=ui->kilometrageInput->text();
    QString DATE_ARRIVAGE=ui->dateArrivageInput->date().toString();
    QDate DATE_SORTIE=ui->dateSortieInput->date();
    QString TYPE_DE_PANNE=ui->comboBox->currentText();
    voiture v(MATRICULE,MARQUE,MODELE,KILOMETRAGE,DATE_ARRIVAGE,DATE_SORTIE,TYPE_DE_PANNE);
    v.modifier();
    ui->tableView->setModel(v.afficher());
}



void MainWindow::on_pushButton_clicked()
{
     voiture v;
    ui->tableView->setModel(v.tri());
}

void MainWindow::on_matriculeInput_3_textChanged(const QString &arg1)
{
    voiture v;
    ui->tableView->setModel(v.rechercher(arg1));
}

void MainWindow::on_pushButton_2_clicked()
{
        QSqlQuery query;
        query.exec("SELECT TYPE_DE_PANNE, COUNT(*) FROM VOITURE GROUP BY TYPE_DE_PANNE");

        QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            QtCharts::QPieSlice *slice = new QtCharts::QPieSlice(type, count);
            series->append(slice);
        }

        QtCharts::QChart *chart = new QtCharts::QChart();
        chart->addSeries(series);
        chart->setTitle("Statistics based on VOITURE type_de_panne");
        chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->tableView_2);
        chartView->resize(ui->tableView_2->size());
        chartView->show();


}
void MainWindow::alerte()
{
     QDate currentDate = QDate::currentDate();
     QSqlQuery query;
        query.prepare("SELECT matricule, date_sortie FROM voiture WHERE date_sortie BETWEEN :currentDate AND :Date");
        query.bindValue(":currentDate", currentDate);
        query.bindValue(":Date", currentDate.addDays(3));

        if (!query.exec()) {
            qDebug() << "Error executing query:";
            return;
        }
        QString warningMessage;
           while (query.next()) {
               QString matricule = query.value("matricule").toString();
               QDate dateSortie = query.value("date_sortie").toDate();
               warningMessage += QString("Car with matricule '%1' has a sortie date on %2\n")
                                     .arg(matricule, dateSortie.toString());
           }

           // Display warning if there are cars meeting the condition
           if (!warningMessage.isEmpty()) {
               QMessageBox::warning(nullptr, "Upcoming Date Sortie Warnings", warningMessage);
           } else {
               QMessageBox::information(nullptr, "No Warnings", "No cars have a sortie date within 3 days.");
           }

}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QSqlQuery query;
    query.prepare("SELECT matricule FROM voiture WHERE date_sortie = :date");
       query.bindValue(":date", date);

       if (!query.exec()) {
           QMessageBox::critical(this, "Query Error", "error");
           return;
       }
       ui->listWidget->clear();

          // Populate the list with results
          while (query.next()) {
              ui->listWidget->addItem(query.value("matricule").toString());
          }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    QPdfWriter pdf("C:/Users/benhamed eya/Documents/pi/voiture.pdf");

           QPainter painter(&pdf);
           int i = 4100;

                  QColor dateColor(0x4a5bcf);
                  painter.setPen(dateColor);

                  painter.setFont(QFont("Montserrat SemiBold", 11));
                  QDate cd = QDate::currentDate();
                  painter.drawText(7700,250,cd.toString("Ariana, El Ghazela"));
                  painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                  QColor titleColor(0x341763);
                  painter.setPen(titleColor);
                  painter.setFont(QFont("Montserrat SemiBold", 25));

                  painter.drawText(3000,2700,"Liste des voiture");

                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  //painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3300,9400,500);

                  painter.setFont(QFont("Montserrat SemiBold", 10));
                              painter.drawText(300,3600,"matricule");
                              painter.drawText(1500,3600,"marque");
                              painter.drawText(2500,3600,"modele");
                              painter.drawText(3500,3600,"kilometrage");
                              painter.drawText(4500,3600,"date_arrivage");
                              painter.drawText(6500,3600,"date_sortie");
                              painter.drawText(8500,3600,"type_de_panne");

                  painter.setFont(QFont("Montserrat", 10));
                  painter.drawRect(100,3300,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from voiture");
                  query.exec();
                  int y=4300;
                  while (query.next())
                  {
                      painter.drawLine(100,y,9490,y);
                      y+=500;
                      painter.drawText(300,i,query.value(0).toString());
                          painter.drawText(1500,i,query.value(1).toString());
                          painter.drawText(2500,i,query.value(2).toString());
                          painter.drawText(3500,i,query.value(3).toString());
                          painter.drawText(4500,i,query.value(4).toString());
                          painter.drawText(6500,i,query.value(5).toString());
                          painter.drawText(8500,i,query.value(6).toString());
                     i = i + 500;
                  }

                  int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
                  if (reponse == QMessageBox::Yes)
                  {
                      QDesktopServices::openUrl( QUrl::fromLocalFile("C:/Users/benhamed eya/Documents/pi/voiture.pdf"));
                      painter.end();
                  }
                  else
                  {
                      painter.end();
                  }
}
