#include <iostream>

using namespace std;

struct node {
	int value = 0;
	string name = "default";
	node* next;
};

struct list {
private:
	int length = 0;
public:
	node* first;

	void add(node* e, int pos= -1)
	{
		if (pos == -1)
		{
			if (length == 0)
			{
				first = e;
				length +=1;
				return;
			}
			node* next_node = first;
			while (next_node->next)
			{
				next_node = next_node->next;
			}

			next_node->next = e;
			length += 1;
		}
		else
		{
			if (pos == 0)
			{
				e->next = first;
				first = e;
				length += 1;
				return;
			}
			int ind = 0;
			node* next_node = first;
			node* prev = first;
			while (next_node->next)
			{
				ind += 1;
				next_node = next_node->next;
				if (ind == pos)
					break;
				prev = prev->next;
			}

			prev->next = e;
			e->next = next_node;
			length += 1;
		}
	};
	void show()
	{
		if (isEmpty())
		{
			cout << "List is empty!" << endl;
			return;
		}
		node* next_node = first;
		cout << next_node->name << ": ";
		cout << next_node->value << "   ";
		while (next_node->next)
		{
			next_node = next_node->next;
			cout << next_node->name << ": ";
			cout << next_node->value << "   ";
		}
		//cout << endl << "LEN = " << length << endl;
	};

	bool contain(string name)
	{
		if (isEmpty()) return false;
		node* next_node = first;
		if (name == next_node->name)
			return true;

		while (next_node->next)
		{
			next_node = next_node->next;
			if (name == next_node->name)
				return true;

		}
		return false;
	}

	void remove(string name)
	{
		if (isEmpty()) return;

		node* next_node = first;
		if (name == next_node->name)
		{
			if (next_node->next)
				first = next_node->next;
			else
				first = NULL;

			length -= 1;
			return;
		}

		node* prev = first;
		//node* temp;
		while (next_node->next)
		{
			next_node = next_node->next;

			if (name == next_node->name)
			{
				//temp = next_node;
				prev->next = next_node->next;;
				length -= 1;
				//delete(temp);
				return;
			}
			prev = prev->next;
		}
	}

	void removeAll(string name)
	{
		node* next_node = first;
		if (name == next_node->name)
		{
			first = next_node->next;
			length -= 1;
		}
		next_node = first;
		node* prev = first;
		while (next_node->next)
		{
			next_node = next_node->next;

			if (name == next_node->name)
			{
				prev->next = next_node->next;
				length -= 1;
			}
			else
			{
				prev = prev->next;
			}
		}
	}

	int lenght()
	{
		return length;
	}

	bool isEmpty()
	{
		return lenght() == 0;
	}

	void clear()
	{
		first = nullptr;
		length = 0;
		
		/*
		* ///Gives error ///
		if (isEmpty())
		{
			return;
		}

		node* curr = first;
		node* next = nullptr;

		while (curr != nullptr)
		{
			next = curr->next;
			delete(curr);
			curr = next;
		}
		*/
		
	}

	int indexOf(string name)
	{
		if (isEmpty()) return -1;

		node* next_node = first;
		if (name == next_node->name)
		{
			return 0;
		}
		int index = 1;
		node* prev = first;
		while (next_node->next)
		{
			next_node = next_node->next;

			if (name == next_node->name)
			{
				return index;
			}
		}

		return -1;
	}

	void removeRep()
	{
		if (isEmpty()) return;

		node* next_node1 = first;
		node* next_node2 = first;
		node* prev = nullptr;

		int ind = 0;
		int ind_2 = 0;
		string temp_name;
		int temp_value;
		while (next_node1->next)
		{
			next_node2 = first;
			ind = 0;
			while (next_node2->next)
			{
				next_node2 = next_node2->next;

				if (next_node1->name == next_node2->name && next_node1 != next_node2)
				{
					temp_name = next_node1->name;
					temp_value = next_node1->value;

					ind = indexOf(next_node1->name);
					removeAll(next_node2->name);

					node* new_old_node = new node;
					new_old_node->name = temp_name;
					new_old_node->value = temp_value;

					add(new_old_node, ind);
				}
				ind++;
			}
			next_node1 = next_node1->next;
		}

		return;
	}

	void reverse()
	{
		node* prev = nullptr;
		node* curr = first;
		node* next = nullptr;

		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;

			prev = curr;
			curr = next;
		}
		first = prev;
		return;
	}

	string* toArray(string* list_tab)
	{
		if (isEmpty())
		{
			return list_tab;
		}
		
		node* next_node = first;
		int ind = 0;
		do {
			list_tab[ind] = next_node -> name;
			next_node = next_node->next;
			ind++;
		} while (next_node->next);
		
		list_tab[ind] = next_node->name;

		return list_tab;
	}
};



int main()
{
	list* my_list = new list();

	node* my_node_1 = new node();
	my_node_1->value = 0;
	my_node_1->name = "podwojny element";

	node* my_node_2 = new node();
	my_node_2->value = 11;
	my_node_2->name = "sec node";

	node* my_node_3 = new node();
	my_node_3->value = 1919;
	my_node_3->name = "oo";

	node* my_node_4 = new node();
	my_node_4->value = 3232;
	my_node_4->name = "cztery";

	node* my_node_5 = new node();
	my_node_5->value = 1;
	my_node_5->name = "podwojny element";

	node* my_node_6 = new node();
	my_node_6->value = 2;
	my_node_6->name = "podwojny element";

	my_list->add(my_node_1);
	my_list->add(my_node_2);
	my_list->add(my_node_3,0);

	

	cout << "LISTA: " << endl;
	my_list->show();
	cout <<endl<< "REVERSED: " << endl;
	my_list->reverse();
	my_list->show();

	string* arr = new string[my_list->lenght()];
	my_list->toArray(arr);

	cout << endl<< "AS ARRAY:" << endl;
	for (int i = 0; i < my_list->lenght(); i++)
	{
		cout << *(arr + i) << "  ";
	}

	/*cout << endl;
	cout << "aaaa: " << my_list->contain("aaaa") << endl;
	cout << "sec node: " << my_list->contain("sec node") << endl;

	my_list->remove("sec node");
	cout << "removed sec node" << endl;
	my_list->show();

	my_list->remove("do not contain");
	cout << "removed do not contain" << endl;
	my_list->show();
	*/

	my_list->add(my_node_4);
	my_list->add(my_node_5);
	my_list->add(my_node_6);
	cout <<endl<< "With rep: " << endl;
	my_list->show();
	my_list->removeRep();
	cout <<endl<< "Without rep: " << endl;
	my_list->show();


	cout << endl<< "idndex of "<<"oo :" << my_list->indexOf("oo") << endl;

	cout << endl <<"LEN = "<< my_list->lenght() << endl;
	my_list->removeAll("podwojny element");
	cout << "removed podwojny element" << endl;
	my_list->show();
	cout << endl <<"LEN = "<< my_list->lenght() << endl;
	cout << endl <<"EMPTY = "<< my_list->isEmpty() << endl;

	my_list->clear();
	my_list->show();
	cout <<"EMPTY = "<< my_list->isEmpty() << endl;

	delete (my_list);
	delete (my_node_1);
	delete (my_node_2);
	delete (my_node_3);
	delete (my_node_4);
	delete (my_node_5);
	delete (my_node_6);
}
