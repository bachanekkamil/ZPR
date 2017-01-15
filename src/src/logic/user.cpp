#include "logic/user.h"
#include <QDebug>



User::User(QString name, unsigned int id, QDateTime time_created):mName(name), mIdDb(id), mTimeCreated(time_created)
{

}

unsigned int User::getIdDb() const{

    return mIdDb;
}


const QString &User::getName() const{

    return mName;
}

const QDateTime* User::getTimeCreated() const{
    return &mTimeCreated;
}
