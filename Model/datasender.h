#ifndef DATASENDER_H
#define DATASENDER_H
#include <QObject>
using namespace std;
// отвечает за передачу данных в представление
class SignalSender : public QObject
{
    Q_OBJECT
signals:
    void SIGNAL_SendQuestion(QString question);
    void SIGNAL_SendAnswers(QList<QString> answers);
    void SIGNAL_DataTransferStart();
    void SIGNAL_DataTransferEnd();
    void SIGNAL_EndOfWork();
public:
    SignalSender(){}
    ~SignalSender(){}
};

#endif // DATASENDER_H
