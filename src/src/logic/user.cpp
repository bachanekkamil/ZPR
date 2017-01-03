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

}


User::~User(){

}


unsigned int User::getIdDb() const{

    return mIdDb;
}


const QString* User::getName() const{

    return &mName;
}

const QDateTime* User::getTimeCreated() const{
    return &mTimeCreated;
}


void User::setName(QString _name){

}
