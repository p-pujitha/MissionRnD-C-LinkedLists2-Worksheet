/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * cn(int n1)
{
	struct node *nn = (struct node *)malloc(sizeof(struct node));
	nn->num = n1;
	nn->next = NULL;
	return nn;
}


struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	struct node *res = NULL;
	struct node *nn, *n = NULL;
	while (head1 != NULL || head2 != NULL)
	{
		if (head1 == NULL)
		{
			nn = cn(head2->num);
			head2 = head2->next;
		}
		else if (head2 == NULL)
		{
			nn = cn(head1->num);
			head1 = head1->next;
		}
		else if (head1->num < head2->num)
		{
			nn = cn(head1->num);
			head1 = head1->next;
		}
		else if (head1->num > head2->num)
		{
			nn = cn(head2->num);
			head2 = head2->next;
		}
		else if (head1->num == head2->num)
		{
			nn = cn(head2->num);
			head2 = head2->next;
			goto lab;
		}

		else
		{
			nn = cn(head1->num);
			n = n->next;
			head1 = head1->next;
		}
	lab:
		if (n == NULL)
		{
			n = nn;
			res = n;
		}
		else
		{
			n->next = nn;
			n = nn;
		}
		n->next = NULL;
	}
	return res;
}