#ifndef ANSWER_H
#define ANSWER_H
#include <QString>

class Answer
{

public:
    ~Answer() {}
    Answer(QString text, unsigned int _id_db);
    const unsigned int getIdDb();
    const QString* getText();
    void setText(QString _text);

private:
    /**
     * ID from database
     */
    const unsigned int mIdDb;
    /**
     * text of answer
     */
    QString mText;

};
#endif // ANSWER_H
