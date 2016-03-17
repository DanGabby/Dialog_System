#include "hashtable.h"
#include <iostream>

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
        empty[i] = true;
}

void HashTable::Insert(SemNetObj* val, int key)
{
    // вычисляем хеш
    HashIndexType hashKey = CalculateHash(key);
    // кол-во ячеек массива, проверенных во время поиска свободного места (для выхода из цикла)
    int used = 0;
    // пока не нашли свободное место или не проверили все ячейки
    while ( !empty[hashKey] && used < SIZE )
    {
        hashKey = (hashKey + 1) % SIZE;
        used++;
    }
    // если нашли свободное место, кладём туда данные
    if ( used < SIZE )
    {
        HTCell cell(val, key);
        values[hashKey] = cell;
        empty[hashKey] = false;
    }
}

void HashTable::Insert(SemNetObj* val, string stringKey)
{
    int key = KeyGen(stringKey);
    Insert(val,key);
}

SemNetObj* HashTable::GetByKey(int key)
{
    HashIndexType hashKey = CalculateHash(key);
    while ( (values[hashKey].GetKey() != key) && !empty[hashKey] )
        hashKey = (hashKey + 1) % SIZE;
    //cout << hashKey;
    return values[hashKey].GetVal();
}

SemNetObj* HashTable::GetByKey(string stringKey)
{
    int key = KeyGen(stringKey);
    return GetByKey(key);
}

HashIndexType HashTable::CalculateHash(int key)
{
    return key % SIZE;
}

int HashTable::KeyGen(string stringKey)
{
    // как преобразовать строки в int? Буду складывать коды символов
    // надо проверить, насколько уникально кодируются строки
    int output = 0;
    for (int i = 0; i < stringKey.length(); i++)
        output += stringKey[i];
    return output;
}
