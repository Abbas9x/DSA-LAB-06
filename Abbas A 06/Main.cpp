#include <iostream>
#include <sstream>
using namespace std;

class Node {
private:
    int Data;
    Node* Next;

public:
    Node(int Data){
        this->Data = Data;
        Next = nullptr;
    }

    int getData(){
        return this->Data;
    }

    Node* getNext(){
        return this->Next;
    }

    void setNext(Node* nextptr){
        Next = nextptr;
    }
};

class LinkedList {
private:
    Node *Head;

public:
    LinkedList() {
        Head = nullptr;
    }

    bool isEmpty(){
        return Head == nullptr;
    }

    void InsertAtEnd(int Data){
        Node *newNode = new Node(Data);
        if (isEmpty()){
            Head = newNode;
        } else {
            Node *p = Head;
            while(p->getNext() != nullptr){
                p = p->getNext();
            }
            p->setNext(newNode);
        }
    }

    void RemoveFromFront(){
        if (isEmpty()){
            cout << "\nError! The Queue is Empty.\n";
            return;
        }

        Node *temp = Head;
        cout << "\nRemoved Value: " << Head->getData() << "\n";
        Head = Head->getNext();
        delete temp;
    }

    void InsertSorted(int Data){
        Node *newNode = new Node(Data);

        if (isEmpty() || Head->getData() > Data){
            newNode->setNext(Head);
            Head = newNode;
        } else {
            Node *p = Head;
            Node *q = nullptr;

            while (p != nullptr && p->getData() <= Data){
                q = p;
                p = p->getNext();
            }

            q->setNext(newNode);
            newNode->setNext(p);
        }
    }

    void Pop(){
        if (isEmpty()){
            cout << "\nError! The Stack is Empty.\n";
            return;
        }

        Node *p = Head;
        Node *q = nullptr;

        if (Head->getNext() == nullptr) {
            cout << "\nPopped Value: " << Head->getData() << "\n";
            delete Head;
            Head = nullptr;
            return;
        }

        while(p->getNext() != nullptr){
            q = p;
            p = p->getNext();
        }

        cout << "\nPopped Value: " << p->getData() << "\n";
        delete p;
        q->setNext(nullptr);
    }

    void DisplayList(){
        if (isEmpty()){
            cout << "\nThe List is Empty.\n";
            return;
        }
        Node *p = Head;
        while (p != nullptr){
            cout << p->getData() << " -> ";
            p = p->getNext();
        }
        cout << "NULL\n";
    }

    ~LinkedList(){
        Node *p = Head;
        Node *q;
        while (p != nullptr){
            q = p->getNext();
            delete p;
            p = q;
        }
    }
};

void MainMenu();
void StackMenu(LinkedList &intList);
void QueueMenu(LinkedList &intList);
void PriorityQueueMenu(LinkedList &intList);
int getValidChoice();
bool isValidMenuChoice(int &choice, int min = 1, int max = 4);

int main(){
    LinkedList intList;
    bool isRunning = true;

    while(isRunning){
        MainMenu();
        int choice = getValidChoice();

        while(!isValidMenuChoice(choice)){
            choice = getValidChoice();
        }

        switch(choice){
            case 1:
                StackMenu(intList);
                break;
            case 2:
                QueueMenu(intList);
                break;
            case 3:
                PriorityQueueMenu(intList);
                break;
            case 4:
                isRunning = false;
                break;
            default:
                cout << "\nInvalid Option.\n";
        }
    }

    return 0;
}

void StackMenu(LinkedList &intList) {
    bool isRunning = true;
    int data;
    while(isRunning){
        cout << "\n---------- Linked List (Stack) ------------\n";
        cout << "\n1.Push";
        cout << "\n2.Pop";
        cout << "\n3.Display Stack";
        cout << "\n4.MainMenu";
        cout << "\n\nEnter your Choice: ";

        int choice = getValidChoice();
        switch(choice){
            case 1:
                cout << "\nEnter number to push: ";
                cin >> data;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears any leftover input
                intList.InsertAtEnd(data);
                break;
            case 2:
                intList.Pop();
                break;
            case 3:
                intList.DisplayList();
                break;
            case 4:
                isRunning = false;
                break;
            default:
                cout << "\nInvalid Option!\n";
        }
    }
}

void QueueMenu(LinkedList &intList) {
    bool isRunning = true;
    int data;
    while(isRunning){
        cout << "\n---------- Linked List (Queue) ------------\n";
        cout << "\n1.Insert";
        cout << "\n2.Remove";
        cout << "\n3.Display Queue";
        cout << "\n4.MainMenu";
        cout << "\n\nEnter your Choice: ";

        int choice = getValidChoice();
        switch(choice){
            case 1:
                cout << "\nEnter number to insert: ";
                cin >> data;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                intList.InsertAtEnd(data);
                break;
            case 2:
                intList.RemoveFromFront();
                break;
            case 3:
                intList.DisplayList();
                break;
            case 4:
                isRunning = false;
                break;
            default:
                cout << "\nInvalid Option!\n";
        }
    }
}

void PriorityQueueMenu(LinkedList &intList) {
    bool isRunning = true;
    int data;
    while(isRunning){
        cout << "\n---------- Linked List (Priority Queue) ------------\n";
        cout << "\n1.Insert";
        cout << "\n2.Remove";
        cout << "\n3.Display Queue";
        cout << "\n4.MainMenu";
        cout << "\n\nEnter your Choice: ";

        int choice = getValidChoice();
        switch(choice){
            case 1:
                cout << "\nEnter number to insert: ";
                cin >> data;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                intList.InsertSorted(data);
                break;
            case 2:
                intList.RemoveFromFront();
                break;
            case 3:
                intList.DisplayList();
                break;
            case 4:
                isRunning = false;
                break;
            default:
                cout << "\nInvalid Option!\n";
        }
    }
}

void MainMenu() {
    cout << "\n---------- Linked List ------------\n";
    cout << "\n1.Stack Menu";
    cout << "\n2.Queue Menu";
    cout << "\n3.Priority Queue";
    cout << "\n4.Exit";
    cout << "\n\nEnter your Choice: ";
}

int getValidChoice() {
    int x;
    string input;
    bool isValid = false;

    while (!isValid) {
        getline(cin, input);
        stringstream ss(input);
        if (ss >> x && ss.eof()) {
            isValid = true;
        } else {
            cout << "\nInvalid input! Please enter a number.\n";
        }
    }

    return x;
}

bool isValidMenuChoice(int &choice, int min, int max) {
    if (choice >= min && choice <= max) {
        return true;
    } else {
        cout << "\nInvalid choice! Please enter a number between " << min << " and " << max << ".\n";
        return false;
    }
}
