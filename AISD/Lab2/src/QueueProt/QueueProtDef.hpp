namespace QueuePrototype {


    // ОБЬЯВЛЕНИЕ АБСТРАКТНОГО КЛАССА ДАННЫХ

    class AData {
    public:
        virtual ~AData() = 0;
    };


    // ОБЬЯВЛЕНИЕ КЛАССА ЭЛЕМЕНТА ОЧЕРЕДИ

    class QueueElement {
    private:
        AData* data; // указатель на данные
        QueueElement* next; // указатель на следующий элемент
    public:
        QueueElement(AData* inData, QueueElement* newNext);
        ~QueueElement();
        AData* GetData(); // получить данные
        void SetData(AData* inData); // установить данные
        QueueElement* GetNextElement(); // получить следующий элемент очереди    
        void SetNextElement(QueueElement* newNext); // установить следующий элемент
    };


    // ОБЬЯВЛЕНИЕ АБСТРАКТНОГО КЛАССА ОЧЕРЕДИ

    class AQueue {
    protected:
        // поля
        QueueElement* tail; // хвост очереди
        int count; // количество элементов
        // методы
        AQueue();
        virtual ~AQueue() = 0; // деструктор должен быть реализован в классе-наследнике
        void Enqueue(AData* inData); // добавить данные в хвост
        AData* Dequeue(); // взять данные из головы
        AData* Peek(); // посмотреть данные из головы
        int LengthQueue(); // узнать количество элементов
        bool DeleteQueue(); // удалить все элементы
    };


}
