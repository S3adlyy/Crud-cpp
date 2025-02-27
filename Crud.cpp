#include "Crud.h"
#include "connection.h"
#include <QTabWidget>
#include <QDebug>

Crud::Crud(QString name, QString email, QString region, QString province, QString directeur, int phone, int codepostal, int nbe) {
    this->name = name;
    this->email = email;
    this->region = region;
    this->province = province;
    this->directeur = directeur;
    this->phone = phone;
    this->codepostal = codepostal;
    this->nbe = nbe;
}
Crud::Crud(){} // constructor ll display

void Crud::add_etablissemnt() {
    connection c;
    QSqlDatabase db = c.get_database();

    if (db.open()) {
        QSqlQuery thisdb(db);
        thisdb.prepare("INSERT INTO ETABLISSEMENT (ETABLISMENT_NAME, CODEPOSTAL, REGION, PROVINCE, EMAIL, PHONE_NUMBRE, DIRECTEUR, NOMBRE_OF_ROOMS) "
                       "VALUES (:name, :codepostal, :region, :province, :email, :phone, :directeur, :nbe)");
        thisdb.bindValue(":name", name);
        thisdb.bindValue(":codepostal", codepostal);
        thisdb.bindValue(":region", region);
        thisdb.bindValue(":province", province);
        thisdb.bindValue(":email", email);
        thisdb.bindValue(":phone", phone);
        thisdb.bindValue(":directeur", directeur);
        thisdb.bindValue(":nbe", nbe);

        if (thisdb.exec()) {
            qDebug() << "etablissement added!";
        } else {
            qDebug() << "probleme" << thisdb.lastError().text();
        }

        db.close();
    } else {
        qDebug() << "problem connecting to the database" << db.lastError().text();
    }
}


void Crud::display_etablissement(QTableWidget *tableWidget) {
    connection c;
    QSqlDatabase db = c.get_database();

    if (db.open()) {
        QSqlQuery thisdb(db);
        thisdb.prepare("SELECT * FROM ETABLISSEMENT");

        if (thisdb.exec()) {
            tableWidget->clear();
            tableWidget->setRowCount(0);

            QStringList headers = {"Name", "Email", "Region", "Province", "Directeur", "Phone", "Code Postal", "NBE"};
            tableWidget->setColumnCount(headers.size());
            tableWidget->setHorizontalHeaderLabels(headers);

            int row = 0;
            while (thisdb.next()) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(thisdb.value("ETABLISMENT_NAME").toString()));
                tableWidget->setItem(row, 1, new QTableWidgetItem(thisdb.value("EMAIL").toString()));
                tableWidget->setItem(row, 2, new QTableWidgetItem(thisdb.value("REGION").toString()));
                tableWidget->setItem(row, 3, new QTableWidgetItem(thisdb.value("PROVINCE").toString()));
                tableWidget->setItem(row, 4, new QTableWidgetItem(thisdb.value("DIRECTEUR").toString()));
                tableWidget->setItem(row, 5, new QTableWidgetItem(thisdb.value("PHONE_NUMBRE").toString()));
                tableWidget->setItem(row, 6, new QTableWidgetItem(thisdb.value("CODEPOSTAL").toString()));
                tableWidget->setItem(row, 7, new QTableWidgetItem(thisdb.value("NOMBRE_OF_ROOMS").toString()));

                row++;
            }

            qDebug() << "Data displayed successfully";
        } else {
            qDebug() << "Error executing query:" << thisdb.lastError().text();
        }

        db.close();
    } else {
        qDebug() << "Problem connecting to the database:" << db.lastError().text();
    }
}

void Crud::delete_etablissement(int id) {
    connection c;
    QSqlDatabase db = c.get_database();

    if (db.open()) {
        QSqlQuery thisdb(db);
        thisdb.prepare("DELETE FROM ETABLISSEMENT WHERE id = :id");
        thisdb.bindValue(":id", id);

        if (thisdb.exec()) {
            qDebug() << "Etablissement deleted successfully!";
        } else {
            qDebug() << "Error deleting etablissement:" << thisdb.lastError().text();
        }
        db.close();
    } else {
        qDebug() << "Problem connecting to the database:" << db.lastError().text();
    }
}


void Crud::modifi_etablissement(int id) {
    connection c;
    QSqlDatabase db = c.get_database();

    if (db.open()) {
        QSqlQuery thisdb(db);
        thisdb.prepare("UPDATE ETABLISSEMENT "
                       "SET ETABLISMENT_NAME = :name, "
                       "CODEPOSTAL = :codepostal, "
                       "REGION = :region, "
                       "PROVINCE = :province, "
                       "EMAIL = :email, "
                       "PHONE_NUMBRE = :phone, "
                       "DIRECTEUR = :directeur, "
                       "NOMBRE_OF_ROOMS = :nbe "
                       "WHERE id = :id");

        // Bind the new values to the query
        thisdb.bindValue(":name", name);
        thisdb.bindValue(":codepostal", codepostal);
        thisdb.bindValue(":region", region);
        thisdb.bindValue(":province", province);
        thisdb.bindValue(":email", email);
        thisdb.bindValue(":phone", phone);
        thisdb.bindValue(":directeur", directeur);
        thisdb.bindValue(":nbe", nbe);
        thisdb.bindValue(":id", id);

        // Execute the query
        if (thisdb.exec()) {
            qDebug() << "Etablissement updated successfully!";
        } else {
            qDebug() << "Error updating etablissement:" << thisdb.lastError().text();
        }

        db.close(); // Close the database connection
    } else {
        qDebug() << "Problem connecting to the database:" << db.lastError().text();
    }
}
