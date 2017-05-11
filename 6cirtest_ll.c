/*6cirtest_ll.c
Author: Swetha Varadarajan
Date created: May 11,2017

Program to test if the linked list is circular

*/

#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

void main(int argc,char** argv) 
{
	struct node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	isCircular(a)? printf("The list is circular\n") : printf("The list is not circular\n") ;
 
	a->next->next->next->next = a;
 
    	isCircular(a)? printf("The list is circular\n") : printf("The list is not circular\n") ;
}
