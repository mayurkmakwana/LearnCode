#include <QCoreApplication>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){ data=0; next = nullptr; }
    Node(int d) {data = d; next = nullptr;}
};

class Queue
{
public:
    Node *front,*rear;
    Queue()
    {
        front = rear = nullptr;
    }
    bool isEmpty();
    void enqueue(int);
    void dequeue();
    void print();
};

bool Queue::isEmpty()
{
    if(front==nullptr && rear==nullptr)
        return true;
    else
        return false;
}

void Queue::enqueue(int data)
{
    Node *new_node =  new Node(data);
    if(isEmpty())
    {
        front = rear = new_node;
        return;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

void Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        if(front==nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
}

void Queue::print()
{
    Node *temp = front;
    while(temp!=nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Queue myq;
    myq.enqueue(10);
    myq.enqueue(20);
    myq.enqueue(30);
    myq.enqueue(40);
    myq.print();
    myq.dequeue();
    myq.print();
    myq.dequeue();
    myq.print();

    return a.exec();
}

