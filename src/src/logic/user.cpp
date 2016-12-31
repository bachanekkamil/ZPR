#include "logic/user.h"
#include <QDebug>

/**
 * pull data from database
 */
User::User():mIdDb(0){

}

/**
 * create new user and add to database, throw exception if saving to database
 * unsuccessful
 */
User::User(QString name, unsigned int id, QDateTime time_created):mName(name), mIdDb(id), mTimeCreated(time_created)
{
    qDebug() << "User created. Id:";
    qDebug() << QString::number(mIdDb);
}


User::~User(){
 qDebug() << "User deleted from memory. Id:";
 qDebug() << QString::number(mIdDb);
}


unsigned int User::getIdDb(){

    return 0;
}


const QString* User::getName(){

    return &mName;
}

const QDateTime* User::getTimeCreated(){
    return &mTimeCreated;
}


void User::setName(QString _name){

}
