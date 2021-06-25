#include <iostream>
#include <cstddef>
#include "StackDef.hpp"

using std::cout;
using std::endl;
using namespace CustomStack;


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССОВ ДАННЫХ СТЕКА
    
StackData::StackData(int inValue) {
    value = inValue;
}

StackData::~StackData() {
    //cout << "Message: destruct StackData" << endl;
}

int StackData::GetValue() {
    return value;
}

void StackData::SetValue(int inValue) {
    value = inValue;
}


// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА СТЕКА

Stack::Stack() {
    head = NULL;
    count = 0;
}

Stack::Stack(int inValue) {
    StackData* newData = new StackData(inValue);
    head = new StackPrototype::StackElement(newData, NULL);
    count = 1;
}

Stack::~Stack() {
    AStack::DeleteStack();
    //cout << "Message: destruct Stack" << endl;
}

void Stack::Push(int inValue) {
    StackData* newData = new StackData(inValue);
    AStack::Push(newData);
}

int Stack::Pop() {
    StackData* outData = (StackData*)AStack::Pop();
    return outData->GetValue();
}

int Stack::Peek() {
    StackData* outData = (StackData*)AStack::Peek();
    return outData->GetValue();
}

int Stack::LengthStack() {
    return count;
}

// void Stack::PrintStack() {
//     while (head != NULL) {
//         cout << Pop() << " ";
//     }
//     cout << endl;
// }

// КОСТЫЛЬ

void Stack::PrintStack() {
    StackPrototype::StackElement* stackElem = head;
    StackData* outData;
    while (stackElem != NULL) {
        outData = (StackData*)stackElem->GetData();
        cout << outData->GetValue() << " ";
        stackElem = stackElem->GetNextElement();
    }
    cout << endl;
}
