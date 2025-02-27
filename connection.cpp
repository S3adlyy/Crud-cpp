#include "connection.h"


connection::connection(){}

bool connection::set_connection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Sentra_Projet2A2");
    db.setUserName("sentra");
    db.setPassword("sentra0");
    return db.open();
}

QSqlDatabase connection::get_database(){
    return QSqlDatabase::database(); // function get treutorni l current database ili 3andik
}
