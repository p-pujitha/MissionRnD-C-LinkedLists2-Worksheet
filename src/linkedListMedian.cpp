/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int count = 0, n;
	float medianvalue;
	if (head == NULL) return -1;
	struct node *ptr = head;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	if ((count % 2) != 0)
	{
		int no = (count / 2) + 1;
		count = 1;
		ptr = head;
		while (ptr != NULL)
		{

			if (count == no)
			{
				//printf("Median=%f", ptr->data);
				medianvalue = ptr->num;
				return medianvalue;
				break;
			}
			ptr = ptr->next;
			count++;
		}
	}
	else{
		int n1 = 0, n2 = 0;
		int ct = 1;
		ptr = head;
		while (ptr != NULL)
		{

			if (ct == (count / 2))
				n1 = ptr->num;
			if (ct == ((count / 2) + 1))
			{
				n2 = ptr->num;
				break;
			}
			ptr = ptr->next;
			ct++;
		}
		//	printf("Median=%f", (n1 + n2) / (2.0));
		medianvalue = (n1 + n2) / (2.0);
		return medianvalue;
	}

}
	
