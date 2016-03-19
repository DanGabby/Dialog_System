#ifndef MODEL_H
#define MODEL_H
#define ANSWERS_MAX_NUMB 5
#include <QObject>
#include "dialogstorage.h"
#include "DSObjects/semnetobj.h"
#include "DSObjects/simplesno.h"
#include "datasender.h"
#include "dialogworker.h"

#define START "dialog start"
class Model : public QObject
{
    Q_OBJECT
public:
    Model(DialogStorage *storage);
    ~Model(){}
    // отвечает за передачу данных в представление: порождает сигналы, которые обрабатывает view
    SignalSender signalSender;

public slots:
    // обработка запроса из view
    void SLOT_QueryReceived(QString query);
    // начало работы: система готовится обрабатывать запросы
    void SLOT_StartWork();
private:
    // определяет способ хранения диалога в памяти
    DialogStorage* storage;
    // определяет принцип перехода от одного вопроса к другому
    // TODO #1: написать интерфейс для worker
    // TODO #2: ВОВРЕМЯ ПЕРЕСТАТЬ ПИСАТЬ ИНТЕРФЕЙСЫ
    DialogWorker worker;    
};

#endif // MODEL_H
