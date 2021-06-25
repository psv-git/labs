namespace StackPrototype {


    // ОБЬЯВЛЕНИЕ АБСТРАКТНОГО КЛАССА ДАННЫХ

    class AData {
    public:
        virtual ~AData() = 0;
    };


    // ОБЬЯВЛЕНИЕ КЛАССА ЭЛЕМЕНТА СТЕКА

    class StackElement {
    private:
        AData* data; // указатель на данные
        StackElement* next; // указатель на следующий элемент
    public:
        StackElement(AData* inData, StackElement* newNext);
        ~StackElement();
        AData* GetData(); // получить данные
        void SetData(AData* inData); // установить данные
        StackElement* GetNextElement(); // получить следующий элемент
        void SetNextElement(StackElement* newNext); // установить следующий элемент
    };


    // ОБЬЯВЛЕНИЕ АБСТРАКТНОГО КЛАССА СТЕКА

    class AStack {
    protected:
        // поля
        StackElement* head; // указатель на голову
        int count; // количество элементов
        // методы
        AStack();
        virtual ~AStack() = 0; // деструктор должен быть реализован в классе-наследнике
        void Push(AData* inData); // положить данные в голову
        AData* Pop(); // взять данные из головы
        AData* Peek(); // просмотреть данные из головы
        int LengthStack(); // узнать количество элементов
        bool DeleteStack(); // удалить все элементы
    };


}
