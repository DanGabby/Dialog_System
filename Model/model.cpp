#include "model.h"

Model::Model(DialogStorage *storage)
{
    this->storage = storage;
}

void Model::SLOT_QueryReceived(QString query)
{
    // получаю объект из формальной модели
    SemNetObj* obj = worker.Next(storage,query);
    // "выполняю" этот объект    
    obj->Execute(&signalSender);
}

void Model::SLOT_StartWork()
{
    // десерелизатор будет работать таким образом, что входная точка сценария окажется
    // в DialogStorage под ключом "dialog start"
    // чтобы корректно начать диалог, модель должна получить какой-то инициализирующий запрос
    SLOT_QueryReceived(START);
}
