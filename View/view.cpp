#include "view.h"
#include <iostream>
#include <QTextStream>
using namespace std;

View::View()
{}

void View::Init()
{
    emit QuerySIGNAL("dialog start");
}

void View::ConsoleQuery()
{
    cin >> answer;
    string query;
    query = question + ' ' + answer;
    emit QuerySIGNAL(query);
}

void View::Update()
{
    cout << question << endl;
    // я этот цикл уже 3 раза скопировал,ЭТО ЖЕ C++, НАПИШИ ПРОЦЕДУРКУ ДЛЯ ОБРАБОТКИ МАССИВОВ, ЧЕССЛОВО
    int i = 0;
    while ((answers[i] != EMPTY_STRING_VAL) && (i < ANSWERS_MAX_NUMB))
    {
        cout << answers[i] << endl;
        i++;
    }
}

void View::DataTransferStartSLOT()
{
    // "обнуляем" поля данных
    question =EMPTY_STRING_VAL;
    for (int i = 0; i < ANSWERS_MAX_NUMB; i++)
        answers[i] = EMPTY_STRING_VAL;
}

void View::ReceiveQuestionSLOT(string question)
{
    this->question = question;
}

void View::ReceiveAnswersSLOT(string answers[])
{
    int i = 0;
    while (answers[i] != EMPTY_STRING_VAL && i < ANSWERS_MAX_NUMB)
    {
        this->answers[i] = answers[i];
        i++;
    }
}

void View::DataTransferEndSLOT()
{
    Update();
}
