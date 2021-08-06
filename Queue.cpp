#include<iostream>
using namespace std;

class queue
{
private:
	int front, rear, arr[5];
public:
	queue();
	bool isEmpty();
	bool isFull();
	void enqueue(int);
	int dequeue();
	void display();
	int count();              //returns total no.'s of element present in the stack
	
};

queue::queue()
{
	front=-1;
	rear = -1;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 0;
	}
}
bool queue::isEmpty()
{
	if (front == -1 && rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool queue::isFull()
{
	if (rear==4)
		return true;
	else
		return false;
}
void queue::enqueue(int val)
{
	if (!isFull())
	{
		arr[++rear] = val;
	}
	else
	{
		cout << "QUEUE IS OVERFLOW !!" << endl;
	}
}
int queue::dequeue()
{
	if (!isEmpty())
	{
		int dequeueVal = arr[++front];
		arr[front] = arr[rear];
		arr[rear] = 0;
		rear--;
		front--;
		return dequeueVal;
	}
	else
	{
		cout << "QUEUE IS UNDERFLOW" << endl;
		return 0;
	}
}
void queue::display()
{
	cout << "*****REAR******" << endl;
	for (int i = 4; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
	cout << "*****FRONT******" << endl;
}
int queue::count()
{
	return rear+1;
}



int main()
{
	queue s;
	int option, value, position;
	do
	{
		cout << "**********************************************************************************************" << endl;
		cout << "What operation do you want to perform ? Select options from the below and enter 0 for the exit" << endl;
		cout << "1) enqueue" << endl;
		cout << "2) dequeue" << endl;
		cout << "3) isEmpty" << endl;
		cout << "4) isFull" << endl;
		cout << "5) count" << endl;
		cout << "6) display" << endl;
		cout << "7) clear screen" << endl;
		cout << "***********************************************************************************************" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Enter the value you want to enqueue : ";
			cin >> value;
			cout << endl;
			s.enqueue(value);
		}
		break;
		case 2:
		{
			cout << "dequeued value is " << s.dequeue() << endl;
		}
		break;
		case 3:
		{
			if (s.isEmpty())
			{
				cout << "queue is empty" << endl;
			}
			else
			{
				cout << "queue is not empty" << endl;
			}
		}
		break;
		case 4:
		{
			if (s.isFull())
			{
				cout << "queue is full" << endl;
			}
			else
			{
				cout << "queue is not full" << endl;
			}
		}
		break;
		case 5:
		{
			cout << "Total no. of element in the queue is " << s.count() << endl;
		}
		break;
		case 6:
		{
			s.display();
		}
		break;
		case 7:
		{
			system("cls");
		}
		break;
		default:
		{
			cout << "entered wrong option" << endl;
		}
		}

	} while (option != 0);

	return 0;
}
