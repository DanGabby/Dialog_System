#ifndef MODEL_H
#define MODEL_H
#define ANSWERS_MAX_NUMB 5
#include <QObject>
#include "hashtable.h"
#include "semnetobj.h"
#include "datasender.h"
#include "dialogworker.h"
#include "simplesemnetobject.h"
//typedef HashTable DialogStorage;
//typedef DialogWorkerAutomat DialogWorker;

class Model : public QObject
{
    Q_OBJECT
public:
    Model()
    {
        //ТЕСТ
        string q;
        string a[5];
        for(int i=0; i < 5; i++)
            a[i] = "EMPTY";
        q = "Zarabotalo?";
        a[0] = "Da";
        storage.Insert(new SimpleSemNetObj(q,a),"dialog start");
        q = "Dovolen?";
        a[0] = "Net";
        storage.Insert(new SimpleSemNetObj(q,a),"Zarabotalo? Net");
    }
    ~Model(){}
    // отвечает за передачу данных в представление, порождает сигналы, которые обрабатывает view
    DataSender dataSender;
public slots:
    void QueryReceivedSlot(string query);
private:
    // определяет способ хранения диалога в памяти
    // сейчас это хеш-таблица
    HashTable storage;
    // определяет принцип перехода от одного вопроса к другому
    // сейчас работает автоматный подход
    DialogWorker worker;    
};

#endif // MODEL_H
