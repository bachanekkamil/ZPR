#include "logic/answer.h"

///////////////////////////////////////////////////////////
//  Answer.cpp
//  Implementation of the Class Answer
//  Created on:      15-gru-2016 10:25:45
//  Original author: bacha
///////////////////////////////////////////////////////////






/**
 * use initialization list to set parameters:
 * - id_db
 * - QString
 * throws std::invalid_argument
 */
Answer::Answer(QString text, unsigned int _id_db):
    mIdDb(_id_db), mText(text)
{

}


const unsigned int Answer::getIdDb(){

    return  mIdDb;
}


const QString* Answer::getText(){

    return  NULL;
}


/**
 * throws std::invalid_argument
 */
void Answer::setText(QString _text){


}
