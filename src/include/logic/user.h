//!
/*!
  \brief Contains class User - Stores info about user
  \author Kamil Bachanek
*/

#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>


//!  class User
/*!
  Stores info about user
*/
class User
{

public:
    //!  User constructor
    /*!
      \param name user name
      \param id id from DB
      \param time_created datetime when user was created
    */
    User(QString name, unsigned int id, QDateTime time_created);

    //!  getIdDb method
    /*!
      \return id from DB
    */
    unsigned int getIdDb() const;

    //!  getName method
    /*!
      \return id from DB
    */
    const QString& getName() const;

    //!  getTimeCreated method
    /*!
      \return datetime when user was created
    */
    const QDateTime* getTimeCreated() const;

private:
    const unsigned int mIdDb;
    QString mName;
    QDateTime mTimeCreated;

};

#endif // USER_H
