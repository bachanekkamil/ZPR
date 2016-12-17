#include "logic/user.h"

/**
 * pull data from database
 */
User::User():id_db(0){

}

/**
 * create new user and add to database, throw exception if saving to database
 * unsuccessful
 */
User::User(QString _name):id_db(0){

}


User::~User(){

}


unsigned int User::getIdDb(){

    return 0;
}


const QString* User::getName(){

    return  NULL;
}


void User::setName(QString _name){

}
