#include <iostream>
#include <cstddef>
#include "QueueDef.hpp"

using std::cout;
using std::endl;
using namespace CustomQueue;


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ДАННЫХ ОЧЕРЕДИ

QueueData::QueueData(Stack* inValue) {
    value = inValue;
}

QueueData::~QueueData() {
    delete value;
    value = NULL;
    //cout << "Message: destruct QueueData" << endl;
}

Stack* QueueData::GetValue() {
    return value;
}

void QueueData::SetValue(Stack* inValue) {
    value = inValue;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ОЧЕРЕДИ

Queue::Queue() {
    tail = NULL;
    count = 0;
}

Queue::~Queue() {
    AQueue::DeleteQueue();
    //cout << "Message: destruct Queue" << endl;
}

void Queue::AddQueueTail(Stack* inStack) {
    QueueData* newData = new QueueData(inStack); // создаем новые данные очереди
    AQueue::Enqueue(newData); // добавляем новый элемент в хвост очереди
}

void Queue::DeleteQueueHead() {
    AQueue::Dequeue();
}

void Queue::PrintQueue() {
    if (tail != NULL) {
        QueuePrototype::QueueElement* queueElem = tail->GetNextElement();
        QueueData* outData;
        while (queueElem != tail) {
            outData = (QueueData*)queueElem->GetData();
            outData->GetValue()->PrintStack();
            queueElem = queueElem->GetNextElement();
        }
        outData = (QueueData*)queueElem->GetData();
        outData->GetValue()->PrintStack();
    } else {
        cout << "Queue is empty" << endl;
    }
}

void Queue::DeleteQueue() {
    AQueue::DeleteQueue();
}

void Queue::AddData(int inValue) {
    QueueData* queueHeadData = (QueueData*)tail->GetNextElement()->GetData(); // получаем данные головы очереди
    queueHeadData->GetValue()->Push(inValue); // получаем стек и ложим в него данные
}

void Queue::DeleteData() {
    QueueData* queueHeadData = (QueueData*)tail->GetNextElement()->GetData(); // получаем данные головы очереди
    queueHeadData->GetValue()->Pop(); // получаем стек и забираем из него голову
}

void Queue::PrintQueueHead() {
    if (tail != NULL) {
        QueuePrototype::QueueElement* queueElem = tail->GetNextElement();
        QueueData* outData = (QueueData*)queueElem->GetData();
        outData->GetValue()->PrintStack();
    } else {
        cout << "Queue is empty" << endl;
    }
}

// НЕ ИСПОЛЬЗУЮТСЯ

// void Queue::AddElement(int inValue) {
//     Stack* newStack = new Stack(inValue); // создаем новый стек
//     QueueData* newData = new QueueData(newStack); // создаем новые данные
//     AQueue::Enqueue(newData); // добавляем элемент в хвост очереди
// }

// void Queue::AddData(int inValue) {
//     QueueData* newData;
//     if (tail == NULL) { // если очередь пуста
//         Stack* newStack = new Stack(inValue); // создаем новый стек
//         newData = new QueueData(newStack); // создаем новые данные
//         AQueue::Enqueue(newData); // добавляем элемент в хвост очереди
//     } else {
//         newData = (QueueData*)tail->GetData(); // получаем данные из хвоста
//         newData->GetValue()->Push(inValue); // получаем из данных стек и ложим в него значение
//     }
// }

// void Queue::PrintElement() {
//     if (tail != NULL) {
//         QueueData* outData = (QueueData*)AQueue::Dequeue(); // получаем данные из головы
//         outData->GetValue()->PrintStack(); // пишем стек в консоль
//     } else {
//         cout << "Queue is empty" << endl;
//     }
// }

// void Queue::PrintQueue() {
//     if (tail != NULL) {
//         while (tail != NULL) {
//             QueueData* outData = (QueueData*)AQueue::Dequeue();
//             outData->GetValue()->PrintStack();
//         }
//     } else {
//         cout << "Queue is empty" << endl;
//     }
// }
