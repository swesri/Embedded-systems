/*4reverse_ll.c
Author: Swetha Varadarajan
Date created: May 9,2017

Reversal of linked list

*/


#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"


void main(int argc,char** argv) 
{
	struct node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	printf("Created Linked list is: \n");
	printList(head);
	printf("Reversed Linked list is: \n");
	reverse(&head);
	printList(head);
}
