#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class connection{
public:
    connection();
    bool set_connection();
    QSqlDatabase get_database();
};



#endif // CONNECTION_H
