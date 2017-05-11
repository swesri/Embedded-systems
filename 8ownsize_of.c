/*8ownsize_of.c
Author: Swetha Varadarajan
Date created: May 11,2017

Program to implement the sizeof() function

*/

#include<stdio.h>
#define mysizeof(p) ((char*)(&p+1) - (char*)(&p))

void main(int argc,char** argv)
{
	int a;
	double b;
	char c;

	printf("Size of int is %ld bytes\n",mysizeof(a));
	printf("Size of double is %ld bytes\n",mysizeof(b));
	printf("Size of char is %ld bytes\n",mysizeof(c));
}
