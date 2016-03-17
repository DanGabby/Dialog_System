#include "simplesemnetobject.h"

SimpleSemNetObj::SimpleSemNetObj(string q, string a[])
{
    this->question = q;
    for (int i = 0; i < MAX_ANSWERS_NUMBER; i++)
        this->answers[i] = a[i];
}

void SimpleSemNetObj::Execute(DataSender *dataSender)
{
    // сообщаем, что передача данных завершена
    emit dataSender->DataTransferStartSIGNAL();
    // порождаем сигналы, отвечающие за передачу данных во View
    emit dataSender->SendQuestionSIGNAL(question);
    emit dataSender->SendAnswersSIGNAL(answers);
    // сообщаем, что передача данных началась
    emit dataSender->DataTransferEndSIGNAL();
}
