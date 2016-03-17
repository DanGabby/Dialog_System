#ifndef VIEW_H
#define VIEW_H
#define ANSWERS_MAX_NUMB 5
#define EMPTY_STRING_VAL "EMPTY"
#include <QTextStream>
#include <string>
using namespace std;
//const string EMPTY_VALUE = "EMPTY";
//  сейчас предтавление реализовано единственым способом: консоль
class View : public QObject
{
    Q_OBJECT

public:
    View();
    void Init();
    // получить ответ пользователя из консоли
    void ConsoleQuery();
    void Update();
signals:
    // передаёт модели запрос пользователя
    // ЗАПРОС = ВОПРОС + ОТВЕТ
    void QuerySIGNAL(string query);
public slots:
    void DataTransferStartSLOT();
    // АААААААААААААА, МНОГО БУКВ
    // эти слоты отвечают за приём данных из модели
    //??? Что делает слот?
    // обновляет информацию на экране или
    // обновляет поля данных, а затем вызывается update, который обновляет экран?
    // поля вопроса и ответов определёно понадобятся для формирования запроса к модели и проверки корректности ответа
    // значит эти поля нужны
    // более сложные форматы данных? Разберусь, когда появятся такие форматы данных
    void ReceiveQuestionSLOT(string question);
    void ReceiveAnswersSLOT(string answers[]);
    // когда закончилась пересылка данных из модели и надо обновить view
    void DataTransferEndSLOT();
private:
    string question;
    string answer;
    string answers[ANSWERS_MAX_NUMB];
};

#endif // VIEW_H
