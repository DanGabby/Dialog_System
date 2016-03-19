#include "view.h"
//#include <iostream>
//#include <QTextStream>
//using namespace std;
#define END "End of dialog."

View::View(QCoreApplication *app)
{
    this->app = app;
}

void View::Init()
{
    emit SIGNAL_Query("dialog start");
}

void View::ConsoleQuery()
{
    QTextStream qin(stdin);
    qin >> answer;
    QString query;
    query = question + ' ' + answer;
    emit SIGNAL_Query(query);
}

void View::Update()
{
//    qDebug() << question << endl;
//    for (int i = 0; i < answers.length(); i++)
//        qDebug() << answers[i] << endl;
    // создаю экземпляр QTextStream каждый раз, когда нужен ввод-вывод консоли
    // ну, так получилось
    QTextStream qout(stdout);
    qout << question << endl;
    for (int i = 0; i < answers.length(); i++)
        qout << answers[i] << endl;
}

void View::SLOT_DataTransferStart()
{
    // "обнуляем" поля данных
    question.clear();
    answers.clear();
}

void View::SLOT_ReceiveQuestion(QString question)
{
    this->question = question;
}

void View::SLOT_ReceiveAnswers(QList<QString> answers)
{
    this->answers = answers;
}

void View::SLOT_DataTransferEnd()
{
    // показать пользователю полученные даные
    Update();
    // получить новый запрос
    ConsoleQuery();
}

void View::SLOT_EndOfWork()
{
    QTextStream qout(stdout);
    qout << END << endl;
    // нужно как-то прервать цикл QT (не сработало)
    app->exit();
}
