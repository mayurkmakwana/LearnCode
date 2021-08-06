#include<iostream>
using namespace std;

class stack
{
private:
	int top;
	int arr[5];
public:
	stack();
	bool isEmpty();
	bool isFull();
	void push(int);
	int pop();
	void display();
	int count();              //returns total no.'s of element present in the stack
	int peek(int);            //returns element at the passing index to the function
	void change(int, int);    //change the value of the particular index
};

stack::stack()
{
	top = -1;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 0;
	}
}
bool stack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool stack::isFull()
{
	if (top == 4)
		return true;
	else
		return false;
}
void stack::push(int val)
{
	if (!isFull())
	{
		arr[++top] = val;
	}
	else
	{
		cout << "STACK IS OVERFLOW !!" << endl;
	}
}
int stack::pop()
{
	if (!isEmpty())
	{
		int popVal = arr[top];
		arr[top] = 0;
		top--;
		return popVal;
	}
	else
	{
		cout << "STACK IS UNDERFLOW" << endl;
		return 0;
	}
}
void stack::display()
{
	cout << "***********" << endl;
	for (int i = top; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
	cout << "***********" << endl;
}
int stack::count()
{
	return ++top;
}
int stack::peek(int i)
{
	if (!isEmpty())
	{
		return arr[i];
	}
	else
	{
		cout << "STACK IS UNDERFLOW" << endl;
		return 0;
	}
	
}
void stack::change(int pos, int val)
{
	if (pos >= 0 && pos <= 4)
	{
		arr[pos] = val;
		cout << "value changed at location " << pos << " is " << val << endl;
	}
	else
	{
		cout << "please enter value between 0-4" << endl;
	}
}


int main()
{
	stack s;
	int option,value,position;
	do
	{
		cout << "What operation do you want to perform ? Select options from the below and enter 0 for the exit" << endl;
		cout << "1) push" << endl;
		cout << "2) pop" << endl;
		cout << "3) isEmpty" << endl;
		cout << "4) isFull" << endl;
		cout << "5) count" << endl;
		cout << "6) peek" << endl;
		cout << "7) change" << endl;
		cout << "8) display" << endl;
		cout << "9) clear screen" << endl;
		cout << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Enter the value you want to push : ";
			cin >> value;
			cout << endl;
			s.push(value);
		}
		break;
		case 2:
		{
			cout << "popped value is " << s.pop() << endl;
		}
		break;
		case 3:
		{
			if (s.isEmpty())
			{
				cout << "stack is empty" << endl;
			}
			else
			{
				cout << "stack is not empty" << endl;
			}
		}
		break;
		case 4:
		{
			if (s.isFull())
			{
				cout << "stack is full" << endl;
			}
			else
			{
				cout << "stack is not full" << endl;
			}
		}
		break;
		case 5:
		{
			cout << "Total no. of element in the stack is " << s.count() << endl;
		}
		break;
		case 6:
		{
			cout << "Enter the position which you want to know the value : ";
			cin >> position;
			cout << endl;
			cout << "value at " << position << " is " << s.peek(position) << endl;

		}
		break;
		case 7:
		{
			cout << "Enter the index at which you want to change the value : ";
			cin >> position;
			cout << endl;
			cout << "Enter the new value : ";
			cin >> value;
			cout << endl;
			if (position >= 0 && position <= 4)
			{
				s.change(position,value);
			}
			else
			{
				cout << "Enter index between 0-4" << endl;
			}

		}
		break;
		case 8:
		{
			s.display();
		}
		break;
		case 9:
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