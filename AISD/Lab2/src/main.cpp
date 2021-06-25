#include <iostream>
#include <cstddef>
#include <string>
#include "Queue/QueueDef.hpp"

using namespace std;
using namespace CustomQueue;


void PrintMenu() {
    system("clear");
    cout << "CHOOSE OPERATION NUMBER:" << endl;
    cout << "1 - Add Queue Tail" << endl << "2 - Delete Queue Head" << endl;
    cout << "3 - Print Queue" << endl << "4 - Delete Queue" << endl << endl;
    cout << "5 - Add Data" << endl << "6 - Delete Data" << endl;
    cout << "7 - Print Queue Head" << endl << endl << "8 - Exit" << endl << endl;
    cout << ">";
}


void ClearInput() {
    while (cin.get() != '\n') continue; 
}


int main() {
    Queue* queue = new Queue();
    Stack* stack;
    bool isLoop = true;
    char command;
    string str;
    while(isLoop) {
        PrintMenu();
        cin >> command;
        if ((command < '1') || (command > '8')) command = '0';
        ClearInput();
        switch (command) {
            case '0':
                cout << "Wrong command number." << endl;
                system("sleep 2");
                break;
            case '1':
                cout << "Enter new stack ( # - stop ): " << endl;
                str = "";
                stack = new Stack();
                while (str != "#") {
                    cin >> str;
                    try {
                        int num = stoi(str, nullptr, 10);
                        stack->Push(num);
                    }
                    catch (const std::invalid_argument& ia) {
                        //cout << "Invalid argument: " << ia.what() << endl;
                    }
                }
                queue->AddQueueTail(stack);
                break;
            case '2':
                queue->DeleteQueueHead();
                cout << "Queue head has been deleted." << endl;
                system("sleep 2");
                break;
            case '3':
                queue->PrintQueue();
                system("sleep 10");
                break;
            case '4':
                queue->DeleteQueue();
                cout << "Queue has been deleted." << endl;
                system("sleep 2");
                break;
            case '5':
                cout << "Enter the data: ";
                cin >> str;
                try {
                    int num = stoi(str, nullptr, 10);
                    queue->AddData(num);
                }
                catch (const std::invalid_argument& ia) {
                    //cout << "Invalid argument: " << ia.what() << endl;
                }
                break;
            case '6':
                queue->DeleteData();
                cout << "Stack element has been deleted." << endl;
                system("sleep 2");
                break;
            case '7':
                queue->PrintQueueHead();
                system("sleep 10");
                break;
            case '8':
                isLoop = false;
                if (queue != NULL) delete queue;
                break;
        }
    }

    return 0;
}
