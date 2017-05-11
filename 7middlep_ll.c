/*7middlep_ll.c
Author: Swetha Varadarajan
Date created: May 11,2017

Program to print middle of linked list

*/

#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

void main(int argc,char** argv) 
{
	struct node* head = NULL;
	int i;

	for (i=5; i>0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddle(head);
	}
 
}
