#include <iostream>
using namespace std;


class SLL
{
public:
	int data;
	SLL* next;
	SLL()
	{
		data = 0;
		next = NULL;
	}
	void append_node(SLL**);
	void prepend_node(SLL**);
	void print_node(SLL*);
	int count_nodes(SLL*);
	void insert_node(int, int, SLL*);
	void sort_nodes(SLL*);
	void reverse_link(SLL**);
	void add_node_with_sorting(SLL**);
	//void sort_sll_using_reverse_link(SLL** ptr);
	void deleteNode(SLL**, int);
	void deleteNthNodeFromBack(SLL**, int);
};
void SLL::append_node(SLL** ptr)
{
	SLL* n = new SLL();
	cout << "Enter the data you want to append : ";
	cin >> n->data;
	if (*ptr == 0)
	{
		n->next = *ptr;
		*ptr = n;
	}
	else
	{
		SLL* l = *ptr;
		while (l->next != 0)
		{
			l = l->next;
		}
		n->next = l->next;
		l->next = n;

	}

}
void SLL::print_node(SLL* ptr)
{
	cout << endl;
	cout << "**********AVAILABLE DATA************" << endl;
	while (ptr)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
	cout << "************************************" << endl;
}
void SLL::prepend_node(SLL** ptr)
{
	SLL* n = new SLL();
	cout << "Enter the data you want to prepand :";
	cin >> n->data;
	n->next = *ptr;
	*ptr = n;
}
int SLL::count_nodes(SLL* ptr)
{
	int count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}
void SLL::insert_node(int existingval, int newval, SLL* ptr)
{
	SLL* n = new SLL();
	while (ptr->data != existingval)
	{
		ptr = ptr->next;
	}
	if (ptr == 0)
	{
		cout << "entered existing data not found in the linked list" << endl;
	}
	else
	{
		SLL* l = ptr;
		n->data = newval;
		n->next = l->next;
		l->next = n;
	}
}
void SLL::sort_nodes(SLL* ptr)
{
	while (ptr->next != 0)
	{
		SLL* n = ptr;

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
void SLL::reverse_link(SLL** ptr)
{
	SLL* prev, * curr, * next;
	curr = *ptr;
	prev = 0;
	while (curr != 0)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*ptr = prev;
}
void SLL::add_node_with_sorting(SLL** ptr)
{
	SLL* n = new SLL();
	cout << "Enter the data you want to append with sorting : ";
	cin >> n->data;
	if (*ptr == 0)
	{
		n->next = *ptr;
		*ptr = n;
	}
	else if(n->data < (*ptr)->data)
	{
		n->next = *ptr;
		n = *ptr;
	}
	else
	{
		SLL* temp = *ptr;
		while (temp->next!=0 && n->data > temp->next->data)
		{
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}
}
/*void SLL::sort_sll_using_reverse_link(SLL** ptr)
{
	if (*ptr == 0 && (*ptr)->data > (*ptr)->next->data)
	{
		SLL* temp = (*ptr)->next;
		(*ptr)->next =(*ptr)->next->next;
		(*ptr)->next->next = (*ptr);
		(*ptr) = temp;		
	}
	else
	{
		SLL* temp = *ptr;
		while (temp->next != 0)
		{
			if (temp->data > temp->next->data)
			{

			}
		}
	}

}
*/
void SLL::deleteNode(SLL** ptr, int data)
{
	SLL* temp = *ptr;
	SLL* temp1=0;
	if (*ptr == 0)
	{
		cout << "Linked list is empty" << endl;
	}
	if ((*ptr)->data == data)
	{

		(*ptr) = (*ptr)->next;
		delete temp;
		//return;
	}
	else
	{
		while(temp!= 0)
		{
			if (temp->data == data)
			{
				temp1->next = temp->next;
				delete temp;
				//return;
			}
			temp1 = temp;
			temp = temp->next;
		}
		return;
	}
	cout << "Entered data is not in entire linked list" << endl;
}
void SLL::deleteNthNodeFromBack(SLL** ptr, int n)
{
	SLL* first = *ptr;
	SLL* second = *ptr;
	for (int i = 0; i < n; i++)
	{
		if (second->next == NULL)
		{
			if (i == (n - 1))
			{
				*ptr = (*ptr)->next;
				return;
			}
		}
		second = second->next;
	}
	while (second->next != 0)
	{
		first = first->next;
		second = second->next;
	}
	first->next = first->next->next;
}



int main()
{
	SLL* head = 0;
	SLL s;
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
		cout << "7) sort linked list by changing link" << endl;
		cout << "8) reverse link" << endl;
		cout << "9) sort when inserted" << endl;
		cout << "10) delete the data from the linked list" << endl;
		cout << "11) delete the Nth node from the back of the linked list" << endl;
		cout << "12) clear screen" << endl;
		cout << "****************************************************************************************" << endl;
		cout << endl;
		cout << "select option :";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			s.append_node(&head);
		}
		break;
		case 2:
		{
			s.prepend_node(&head);
		}
		break;
		case 3:
		{
			int existingval, newval;
			cout << "Enter the data after you want to add data : ";
			cin >> existingval;
			cout << "Enter the new data : ";
			cin >> newval;
			s.insert_node(existingval, newval, head);

		}
		break;
		case 4:
		{
			cout << "no. of nodes in the linked list is : " << s.count_nodes(head) << endl;
		}
		break;
		case 5:
		{
			s.print_node(head);
		}
		break;
		case 6:
		{
			s.sort_nodes(head);
		}
		break;
		case 7:
		{
			//s.sort_sll_using_reverse_link(&head);
		}
		case 8:
		{
			s.reverse_link(&head);
		}
		break;
		case 9:
		{
			s.add_node_with_sorting(&head);
		}
		case 10:
		{
			int data = 0;
			cout << "Enter the data you want to delete" << endl;
			cin >> data;
			s.deleteNode(&head,data);
		}
		case 11:
		{
			int n = 0;
			cout << "Enter the node no. you want to delete" << endl;
			cin >> n;
			s.deleteNthNodeFromBack(&head, n);
		}
		case 12:
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
