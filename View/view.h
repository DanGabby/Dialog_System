#ifndef VIEW_H
#define VIEW_H
#include <QList>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
using namespace std;

//  сейчас предтавление реализовано единственым способом: консоль
class View : public QObject
{
    Q_OBJECT

public:
    View(QCoreApplication *app);
    void Init();
    // получить ответ пользователя из консоли
    void ConsoleQuery();
    void Update();
signals:
    // сообщает модели, что пора начинать работу
    void SIGNAL_StartWork();
    // передаёт модели запрос пользователя
    // ЗАПРОС = ВОПРОС + ОТВЕТ
    void SIGNAL_Query(QString query);
public slots:
    // приём данных из модели
    void SLOT_DataTransferStart();
    void SLOT_ReceiveQuestion(QString question);
    void SLOT_ReceiveAnswers(QList<QString> answers);
    // когда закончилась пересылка данных из модели и надо обновить view
    void SLOT_DataTransferEnd();
    // когда модель закончила выполнение сценария, view должна как-то отреагировать
    void SLOT_EndOfWork();
private:
    QString question;
    QString answer;
    QList<QString> answers;

    QCoreApplication *app;
};

#endif // VIEW_H
