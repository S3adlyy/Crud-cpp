#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Crud.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    QString name = ui->name->text();
    QString region = ui->region->text();
    QString codepostal = ui->cp->text();
    QString directeur = ui->directeur->text();
    QString nbe = ui->nbe->text();
    QString email = ui->email->text();
    QString phone = ui->numbre->text();
    QString province = ui->province->text();

    if (name.isEmpty() || region.isEmpty() || codepostal.isEmpty() || directeur.isEmpty() ||
        nbe.isEmpty() || email.isEmpty() || phone.isEmpty() || province.isEmpty()) {
        QMessageBox::warning(this, "input probleme", "all fields are required");
        return;
    }
    bool ok1, ok2, ok3;// ****** idha 3andik ay variable int 9bal ma t insertih fi wist l constructor convertih to int ! ******
    int phoneInt = phone.toInt(&ok1);
    int codepostalInt = codepostal.toInt(&ok2);
    int nbeInt = nbe.toInt(&ok3);

    if (!ok1 || !ok2 || !ok3) {
        QMessageBox::warning(this, "input Error", "Phone, Code Postal, and NBE must be numeric");
        return;
    }
    Crud add(name, email, region, province, directeur, phoneInt, codepostalInt, nbeInt);
    add.add_etablissemnt();

    ui->name->clear();
    ui->region->clear();
    ui->cp->clear();
    ui->directeur->clear();
    ui->nbe->clear();
    ui->email->clear();
    ui->numbre->clear();
    ui->province->clear();

    QMessageBox::information(this, "Success", "Etablissement added successfully!");
}

void MainWindow::on_pushButton_clicked()
{
    Crud see;
    see.display_etablissement(ui->tableWidget);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString id=ui->id->text();
    bool test;
    int idint=id.toInt(&test);
    Crud drop;
    drop.delete_etablissement(idint);
}



