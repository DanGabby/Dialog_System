#include "presenter.h"

Presenter::Presenter(View *view, Model *model)
{
    // перебрасываем сылки на представление и модель
    this->view = view;
    this->model = model;
}
// налаживается связь между слотами и сигналами модели и представления
void Presenter::ProvideConnections()
{
    // Начало и конец работы диалоговой системы
    QObject::connect(view,SIGNAL(SIGNAL_StartWork(void)),model,SLOT(SLOT_StartWork(void)));
    QObject::connect(&model->signalSender,SIGNAL(SIGNAL_EndOfWork(void)),view,SLOT(SLOT_EndOfWork(void)));

    // Отправка-Обработка запроса
    QObject::connect(view,SIGNAL(SIGNAL_Query(QString)),model,SLOT(SLOT_QueryReceived(QString)));

    // Отправка моделью в представление данных, полученных в результате обработки запроса
    // иметь по сигналу-слоту на каждый тип персылаемых данных - рабочий способ (может есть способ лучше?)
    QObject::connect(&model->signalSender, SIGNAL(SIGNAL_DataTransferStart(void)),
                     view, SLOT(SLOT_DataTransferStart(void)));
    QObject::connect(&model->signalSender, SIGNAL(SIGNAL_DataTransferEnd(void)),
                     view, SLOT(SLOT_DataTransferEnd(void)));
    QObject::connect(&model->signalSender, SIGNAL(SIGNAL_SendQuestion(QString)),
                     view, SLOT(SLOT_ReceiveQuestion(QString)));
    QObject::connect(&model->signalSender, SIGNAL(SIGNAL_SendAnswers(QList<QString>)),
                     view, SLOT(SLOT_ReceiveAnswers(QList<QString>)));
}
