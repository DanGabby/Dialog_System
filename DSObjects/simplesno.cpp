#include "simplesno.h"

SimpleSNO::SimpleSNO(QString q, QList<QString> a)
{
    this->question = q;
    this->answers = a;
}

void SimpleSNO::Execute(SignalSender *signalSender)
{
    emit signalSender->SIGNAL_DataTransferStart();

    emit signalSender->SIGNAL_SendQuestion(question);
    emit signalSender->SIGNAL_SendAnswers(answers);

    emit signalSender->SIGNAL_DataTransferEnd();
}
