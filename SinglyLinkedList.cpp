#include<iostream>
using namespace std;
struct node
{
	int val;
	struct node* next;
};
void PrintList(struct node*);
struct node* CreateNode(int);
struct node* CreateSLL();
int Search(struct node*, int);
struct node* InsertNode(struct node*, int, int);
struct node* DeleteNode(struct node*, int);
struct node* DeleteSLL(struct node*);
int main()
{
	struct node* head;
	int x, pos;
	head = CreateSLL();
	cout << "Elements in linked list:\n";
	PrintList(head);
	cout << "\nEnter the element you want to find the position of:\n";
	cin >> x;
	pos = Search(head, x);
	pos == -1 ? cout << x << " not present in linked list\n" : cout << "The position of " << x << " is " << pos << "\n";
	cout << "\nEnter the position in linked list where you want to insert the element and its value:\n";
	cin >> pos >> x;
	head = InsertNode(head, pos, x);
	cout << "\nElements in linked list after insertion:\n";
	PrintList(head);
	cout << "\nEnter the position of the element you want to delete from linked list:\n";
	cin >> pos;
	head = DeleteNode(head, pos);
	cout << "\nElements in linked list after deletion:\n";
	PrintList(head);
	cout << "\nDeleting linked list...the linked list looks as:\n";
	head = DeleteSLL(head);
	PrintList(head);
	return 0;
}
void PrintList(struct node* head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
struct node* CreateNode(int x)
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->val = x;
	head->next = NULL;
	return head;
}
struct node* CreateSLL()
{
	struct node* head = CreateNode(4), *ptr = head;
	ptr->next = CreateNode(15);
	ptr = ptr->next;
	ptr->next = CreateNode(7);
	ptr = ptr->next;
	ptr->next = CreateNode(40);
	ptr = ptr->next;
	return head;
}
int Search(struct node* head, int x)
{
	int pos = 0;
	while (head != NULL)
	{
		pos++;
		if (head->val == x)
		{
			return pos;
		}
		head = head->next;
	}
	return -1;
}
struct node* InsertNode(struct node *head, int pos, int x)
{
	node* newnode = CreateNode(x);
	if (pos == 1)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		node* ptr, * prev = head;
		int c = 1;
		ptr = head;
		while (c < pos && ptr != NULL)
		{
			c++;
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = newnode;
		newnode->next = ptr;
	}
	return head;
}
struct node* DeleteNode(struct node* head, int pos)
{
	struct node* ptr;
	if (pos == 1)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
	else
	{
		int c = 1;
		node* prev = head;
		ptr = head;
		while (c < pos && ptr != NULL)
		{
			c++;
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = ptr->next;
		free(ptr);
	}
	return head;
}
struct node* DeleteSLL(struct node* head)
{
	node* ptr;
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
	return head;
}