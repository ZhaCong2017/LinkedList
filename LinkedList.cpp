#include<iostream>
using namespace std;

struct node
{
	int num;
	node *next;
};

node *creatnode(int x)
{
	node *now = new node();
	now->next = NULL;
	now->num = x;
	return now;
}
node *buildlist()
{
	node *head = creatnode(0);
	node *now = head;
	for (int i = 1; i < 5; i++)
	{
		node *tmp = creatnode(i);
		now->next = tmp;
		now = tmp;
	}
	return head;
}

void print(node *head)
{
	while (head != NULL)
	{
		cout << head->num;
		head = head->next;
		if (head != NULL)
			cout << " -> ";
	}
	cout << endl;
}

void add(node *head, int x)
{
	node *now = head;
	if (now == NULL)
		head = creatnode(x);
	else
	{
		while (now->next != NULL)
			now = now->next;
		now->next = creatnode(x);
	}
}

node *remove(node *head, int x)
{
	if (head == NULL)
		return head;
	if (head->num == x)
	{
		head = head->next;
		return head;
	}
	node *now = head;
	node *nxt = head->next;
	while (nxt != NULL)
	{
		if (nxt->num == x)
		{
			now->next = nxt->next;
			return head;
		}
		else
		{
			now = now->next;
			nxt = nxt->next;
		}
	}
}


node *reverse(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	node *now = head->next;
	node *pre = head;
	node *lat = now->next;
	pre->next = NULL;
	do
	{
		now->next = pre;
		pre = now;
		now = lat;
		lat = lat->next;
	} while (lat != NULL);
	now->next = pre;
	return now;
}

int main()
{
	node *head = buildlist();
	print(head);

	add(head, 6);
	print(head);

	add(head, 7);
	print(head);

	head = reverse(head);
	print(head);

	head = reverse(head);
	print(head);

	head = remove(head, 0);
	print(head);

	head = remove(head, 2);
	print(head);

	head = remove(head, 7);
	print(head);
	system("pause");
	return 0;
}
