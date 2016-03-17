#ifndef PRESENTER_H
#define PRESENTER_H
#include <QObject>
#include "view.h"
#include "model.h"
//#include "hashtable.h"
//typedef HashTable ModelSemNet;

class Presenter
{
public:    
    Presenter(){}
    ~Presenter(){}
    Presenter(View *view, Model *model);
    // нужны ли проверки на "удалось ли создать связь"?
    void ProvideConnections();
private:
    View* view;
    Model* model;
    // объект-контейнер даных
};

#endif // PRESENTER_H
