#include "presenter.h"

Presenter::Presenter(View *view, Model *model)
{
    // перебрасываем сылки на представление и модель
    this->view = view;
    this->model = model;
}

void Presenter::ProvideConnections()
{
    // view сообщает модели, что получен запрос и передаёт его
    QObject::connect(view,SIGNAL(QuerySIGNAL(string)),model,SLOT(QueryReceivedSlot(string)));
    // модель, обработав запрос, сообщает view, что у неё есть данные,
    // которые неплохо было бы показать пользователю
    // за отправку данных отвечает dataSender
    QObject::connect(&model->dataSender, SIGNAL(DataTransferStartSIGNAL(void)),
                     view, SLOT(DataTransferStartSLOT(void)));
    QObject::connect(&model->dataSender, SIGNAL(DataTransferEndSIGNAL(void)),
                     view, SLOT(DataTransferEndSLOT(void)));
    QObject::connect(&model->dataSender, SIGNAL(SendQuestionSIGNAL(string)),
                     view, SLOT(ReceiveQuestionSLOT(string)));
    QObject::connect(&model->dataSender, SIGNAL(SendAnswersSIGNAL(string[])),
                     view, SLOT(ReceiveAnswersSLOT(string[])));
}
