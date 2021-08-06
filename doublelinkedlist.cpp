#include <iostream>
using namespace std;


class DLL
{
public:
	int data;
	DLL* prev;
	DLL *next;
	DLL()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}
	void append_node();
	void prepend_node();
	void print_node();
	int count_nodes();
	void insert_node(int, int);
	void sort_nodes();
	void reverse_data();
	void delete_node(int);
};

DLL *head = 0;

void DLL::append_node()
{
	DLL* n = new DLL();
	cout << "Enter the data you want to append : ";
	cin >> n->data;
	if (head == 0)
	{
		n->next = head;
		n->prev = head;
		head = n;
	}
	else
	{
		DLL* l = head;
		while (l->next != 0)
		{
			l = l->next;
		}

		n->next = l->next;
		n->prev = l;
		l->next = n;
	}

}
void DLL::print_node()
{
	DLL* ptr = head;
	cout << endl;
	cout << "**********AVAILABLE DATA************" << endl;
	while (ptr)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
	cout << "************************************" << endl;
}
void DLL::prepend_node()
{
	DLL* n = new DLL();
	cout << "Enter the data you want to prepend : ";
	cin >> n->data;
	if (head == 0)
	{
		n->next = head;
		n->prev = head;
		head = n;
	}
	else
	{
		n->next = head;
		n->prev = 0;
		head->prev = n;
		head = n;
	}
	    
}
int DLL::count_nodes()
{
	DLL* ptr = head;
	int count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}
void DLL::insert_node(int existingval, int newval)
{
	DLL* n = new DLL();
	DLL* temp = head;
	while (temp)
	{
		if (temp->data == existingval)
		{
			n->next = temp->next;
			n->prev = temp->next->prev;
			temp->next = n;
			temp->next->prev = n;
			n->data = newval;
			return;
		}
		temp = temp->next;
	}
}
void DLL::sort_nodes()
{
	DLL* ptr = head;
	while (ptr->next != 0)
	{
		DLL* n = head;

		while (n->next != 0)
		{
			if ((n->data) > (n->next->data))
			{
				int temp;
				temp = n->data;
				n->data = n->next->data;
				n->next->data = temp;
			}
			n = n->next;
		}
		ptr = ptr->next;
	}
}
void DLL::reverse_data()
{
	DLL* ptr = head;
	while (ptr->next != 0)
	{
		ptr = ptr->next;
	}
	cout << "********REVERSED DATA*************" << endl;
	while(ptr!= 0)
	{
		cout << ptr->data << endl;
		ptr = ptr->prev;
	}
	cout << "**********************************" << endl;


}
void DLL::delete_node(int deldata)
{
	DLL* temp = head;
	while (temp)
	{
		if (temp->data == deldata)
		{
			if (temp->prev == 0)
			{
				head = temp->next;
			}
			if (temp->next != 0)
			{
				temp->next->prev = temp->prev;
			}
			if (temp->prev != 0)
			{
				temp->prev->next = temp->next;
			}
			delete temp;
			return;
		}
		temp = temp->next;
	}
	cout << "Entered data not available in list" << endl;
}



int main()
{
	DLL d;
	int op;
	do
	{
		cout << "****************************************************************************************" << endl;
		cout << "Which operation do you want to perform...select from the below options..for exit enter 0" << endl;
		cout << "1) append data" << endl;
		cout << "2) prepend data" << endl;
		cout << "3) insert data" << endl;
		cout << "4) count node" << endl;
		cout << "5) print data" << endl;
		cout << "6) sort data" << endl;
		cout << "7) reverse data" << endl;
		cout << "8) delete node" << endl;
		cout << "9) clear screen" << endl;
		cout << "****************************************************************************************" << endl;
		cout << endl;
		cout << "select option :";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			d.append_node();
		}
		break;
		case 2:
		{
			d.prepend_node();
		}
		break;
		case 3:
		{
			int existingval, newval;
			cout << "Enter the data after you want to add data : ";
			cin >> existingval;
			cout << "Enter the new data : ";
			cin >> newval;
			d.insert_node(existingval, newval);

		}
		break;
		case 4:
		{
			cout << "no. of nodes in the linked list is : " << d.count_nodes() << endl;
		}
		break;
		case 5:
		{
			d.print_node();
		}
		break;
		case 6:
		{
			d.sort_nodes();
		}
		break;
		case 7:
		{
			d.reverse_data();
		}
		break;
		case 8:
		{ 
			int deletedata;
			cout << "Enter the data you want to delete : ";
			cin >> deletedata;
			d.delete_node(deletedata);
		}
		break;
		case 9:
		{
			system("cls");
		}
		break;
		default:
		{
			cout << "Entered wrong option" << endl;
		}
		}



	} while (op != 0);
	return 0;
}
