#include <iostream>
#include <cstddef>
#include "QueueProtDef.hpp"

using std::cout;
using std::endl;
using namespace QueuePrototype;


// РЕАЛИЗАЦИЯ ДЕСТРУКТОРА АБСТРАКТНОГО КЛАССА ДАННЫХ

AData::~AData() {
    //cout << "Message: destruct QueuePrototype::AData" << endl;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ЭЛЕМЕНТА ОЧЕРЕДИ

QueueElement::QueueElement(AData* inData, QueueElement* newNext) {
    data = inData;
    next = newNext;
}

QueueElement::~QueueElement() {
    //cout << "Message: destruct QueueElement" << endl;
}

AData* QueueElement::GetData() {
    return data;
}

void QueueElement::SetData(AData* inData) {
    data = inData;
}

QueueElement* QueueElement::GetNextElement() {
    return next;
}

void QueueElement::SetNextElement(QueueElement* newNext) {
    next = newNext;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ АБСТРАКТНОГО КЛАССА ОЧЕРЕДИ

AQueue::AQueue() {}

AQueue::~AQueue() {
    //cout << "Message: destruct AQueue" << endl;
}

void AQueue::Enqueue(AData* inData) {
    QueueElement* newElem = new QueueElement(inData, NULL); // создаем новый элемент
    if (tail == NULL) {
        newElem->SetNextElement(newElem); // если очередь пуста - ссылается сам на себя
    } else {
        newElem->SetNextElement(tail->GetNextElement()); // устанавливаем next нового элемента на голову
        tail->SetNextElement(newElem); // устанавливаем next текущего хвоста на новый элемент
    }
    tail = newElem; // устанавливаем новый хвост
    count++;
}

AData* AQueue::Dequeue() {
    if (tail == NULL) return NULL; // если очередь пуста - вернуть null
    QueueElement* headElem = tail->GetNextElement(); // получаем указатель на голову
    AData* outData = headElem->GetData(); // получаем данные из головы
    if (tail == headElem) {
        delete tail; // если единственный элемент очереди - удаляем хвост
        tail = NULL; // обнуляем указатель
    } else {
        tail->SetNextElement(headElem->GetNextElement()); // устанавливаем next хвоста на новую голову
        delete headElem; // удаляем голову
    }
    count--;
    return outData;
}

AData* AQueue::Peek() {
    if (tail == NULL) return NULL; // если очередь пуста - вернуть null
    return tail->GetNextElement()->GetData(); // смотрим данные из головы
}

int AQueue::LengthQueue() {
    return count;
}

bool AQueue::DeleteQueue() {
    if (tail == NULL) return false; // если очередь пуста - вернуть false
    QueueElement* headElem = tail->GetNextElement(); // получаем указатель на голову
    while (headElem != tail) {
        tail->SetNextElement(headElem->GetNextElement()); // устанавливаем указатель на новую голову
        delete headElem->GetData(); // удаляем данные головы
        delete headElem; // удаляем голову
        headElem = tail->GetNextElement(); // получаем указатель на новую голову
    }
    delete tail->GetData(); // удаляем данные хвоста
    delete tail; // удаляем хвост
    tail = NULL; // обнуляем указатель
    return true;
}
