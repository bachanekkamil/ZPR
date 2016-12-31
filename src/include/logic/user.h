#ifndef USER_H
#define USER_H
#include "boost/date_time/posix_time/posix_time.hpp"
#include <QString>
#include <QDateTime>

class User
{

public:
    User();
    User(QString name, unsigned int id, QDateTime time_created);
    ~User();
    unsigned int getIdDb();
    const QString* getName();
    const QDateTime* getTimeCreated();
    void setName(QString _name);


private:
    const unsigned int mIdDb;
    QString mName;
    QDateTime mTimeCreated;

};

#endif // USER_H
