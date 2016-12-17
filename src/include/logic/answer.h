#ifndef ANSWER_H
#define ANSWER_H
#include <QString>

class Answer
{

public:
    Answer();
    virtual ~Answer();

    Answer(QString text, unsigned int _id_db);
    const unsigned int* getIdDb();
    const QString* getText();
    void setText(QString _text);

private:
    /**
     * ID from database
     */
    const unsigned int id_db;
    /**
     * text of answer
     */
    QString text;

};
#endif // ANSWER_H
