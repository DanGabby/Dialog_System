#ifndef DATASENDER_H
#define DATASENDER_H
#include <QObject>
#include <string>
using namespace std;
class DataSender : public QObject
{
    Q_OBJECT
signals:
    void SendQuestionSIGNAL(string question);
    void SendAnswersSIGNAL(string answers[]);
    void DataTransferStartSIGNAL();
    void DataTransferEndSIGNAL();
public:
    DataSender();
};

#endif // DATASENDER_H
