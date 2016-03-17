#include "model.h"

void Model::QueryReceivedSlot(string query)
{
    // получаю объект из формальной модели
//    SemNetObj* obj = storage.GetByKey(query);
    SemNetObj* obj = worker.Next(&storage,query);
    // "выполняю" этот объект    
    obj->Execute(&dataSender);
}
