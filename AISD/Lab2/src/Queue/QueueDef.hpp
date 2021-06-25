#include "../QueueProt/QueueProtDef.hpp"
#include "../Stack/StackDef.hpp"

namespace CustomQueue {

    using CustomStack::Stack;
    using CustomStack::StackData;


    // ОБЬЯВЛЕНИЕ КЛАССА ДАННЫХ ОЧЕРЕДИ

    class QueueData : public QueuePrototype::AData {
    private:
        Stack* value; // значение
    public:
        QueueData(Stack* inValue); 
        ~QueueData();
        Stack* GetValue(); // получить значение
        void SetValue(Stack* inValue); // установить значение
    };


    // ОБЬЯВЛЕНИЕ КЛАССА ОЧЕРЕДИ

    class Queue : public QueuePrototype::AQueue {
    public:
        Queue();
        ~Queue();
        void AddQueueTail(Stack* inStack); // добавить новый элемент в хвост очереди (включить в очередь)
        void DeleteQueueHead(); // удалить голову очереди (продвинуть очередь)
        void PrintQueue(); // вывести очередь на печать (просмотр очереди)
        void DeleteQueue(); // удалить очередь
        void AddData(int inValue); // добавить данные в стек головы очереди (включить в стек)
        void DeleteData(); // удалить данные из стека головы очереди (удалить из стека)
        void PrintQueueHead(); // вывести голову очереди на печать (просмотр стека)
    };


}
