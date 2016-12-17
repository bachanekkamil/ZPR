#ifndef USER_H
#define USER_H
#include "boost/date_time/posix_time/posix_time.hpp"
#include <QString>

class User
{

public:
    User();
    User(QString _name);
    ~User();
    unsigned int getIdDb();
    const QString* getName();
    void setName(QString _name);

private:
    const unsigned int id_db;
    QString name;
    const boost::posix_time::ptime time_created;

};

#endif // USER_H
