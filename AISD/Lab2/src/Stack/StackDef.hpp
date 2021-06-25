#include "../StackProt/StackProtDef.hpp"

namespace CustomStack {


    // ОБЬЯВЛЕНИЕ КЛАССА ДАННЫХ СТЕКА

    class StackData : public StackPrototype::AData {
    private:
        int value; // значение
    public:
        StackData(int inValue);
        ~StackData();
        int GetValue(); // получить значение
        void SetValue(int inValue); // установить значение
    };


    // ОБЬЯВЛЕНИЕ КЛАССА СТЕКА

    class Stack : public StackPrototype::AStack {
    public:
        Stack();
        Stack(int inValue);
        ~Stack();
        void Push(int inValue); // добавить данные в голову
        int Pop(); // взять данные из головы
        int Peek(); // посмотреть данные из головы
        int LengthStack(); // получить количество элементов
        void PrintStack(); // вывести стек на печать
    };


}
