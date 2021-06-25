#include <iostream>
#include <cstddef>
#include "StackProtDef.hpp"

using std::cout;
using std::endl;
using namespace StackPrototype;


// РЕАЛИЗАЦИЯ ДЕСТРУКТОРА АБСТРАКТНОГО КЛАССА ДАННЫХ

AData::~AData() {
    //cout << "Message: destruct StackPrototype::AData" << endl;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ЭЛЕМЕНТА СТЕКА

StackElement::StackElement(AData* inData, StackElement* newNext) {
    data = inData;
    next = newNext;
}

StackElement::~StackElement() {
    //cout << "Message: destruct StackElement" << endl;
}

AData* StackElement::GetData() {
    return data;
}

void StackElement::SetData(AData* inData) {
    data = inData;
}

StackElement* StackElement::GetNextElement() {
    return next;
}

void StackElement::SetNextElement(StackElement* newNext) {
    next = newNext;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ АБСТРАКТНОГО КЛАССА СТЕКА

AStack::AStack() {}

AStack::~AStack() {
    //cout << "Message: destruct AStack" << endl;
}

void AStack::Push(AData* inData) {
    StackElement* newElem = new StackElement(inData, head); // создаем новый элемент
    head = newElem; // устанавливаем указатель головы на newElem
    count++;
}

AData* AStack::Pop() {
    if (head == NULL) return NULL; // если стек пуст - вернуть null
    AData* outData = head->GetData(); // берем данные из головы
    StackElement* nextElem = head->GetNextElement(); // получаем указатель на следующий элемент
    delete head; // удаляем голову
    head = nextElem; // устанавливаем голову на следующий элемент
    count--;
    return outData;
}

AData* AStack::Peek() {
    if (head == NULL) return NULL; // если стек пуст - вернуть null
    return head->GetData();
}

int AStack::LengthStack() {
    return count;
}

bool AStack::DeleteStack() {
    if (head == NULL) return false; // если стек пуст - вернуть false
    StackElement* nextElem = head->GetNextElement(); // получаем указатель на следующий элемент
    while (nextElem != NULL) {
        delete head->GetData(); // удаляем данные головы
        delete head; // удаляем голову
        head = nextElem; // устанавливаем голову на следующий элемент
        nextElem = head->GetNextElement(); // запоминаем указатель на следующий элемент
    }
    delete head->GetData(); // удаляем данные головы
    delete head; // удаляем голову
    head = NULL; // обнуляем указатель
    return true;
}
