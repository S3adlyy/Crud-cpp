#ifndef CRUD_H
#define CRUD_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QTableWidget>
class Crud{
private:
    QString name;QString email;QString region;QString province;QString directeur;
    int phone;int codepostal;int nbe;
public:
    Crud(QString name,QString email,QString region,QString province,QString directeur,int phone,int codepostal,int nbe); // constructor ll insert
    Crud();//dif constructor ll display

    void add_etablissemnt();
    void delete_etablissement(int id);
    void modifi_etablissement(int id);
    void display_etablissement(QTableWidget *tableWidget);
};


#endif // CRUD_H
