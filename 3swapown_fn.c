/*3swapown_fn.c
Author: Swetha Varadarajan
Date created: May 9,2017

Program to swap two strings

Reference: geeksforgeeks website (http://www.geeksforgeeks.org/swap-strings-in-c/)

*/
#include<stdio.h>
#include<stdlib.h>

void swap(char **str1_ptr, char **str2_ptr)
{
	char *temp = *str1_ptr;
	*str1_ptr = *str2_ptr;
	*str2_ptr = temp;
}  
  
void main(int argc,char** argv)
{
	char *str1, *str2;
	
	if(argc > 2)
	{
		str1 = argv[1];
		str2 = argv[2];
		printf("Before Swapping:\tstr1 is %s\tstr2 is %s\n", str1, str2);
	}
	else
	{
		printf("Usage:./a.out string1 string2 \n");
		exit(0);
	}
	swap(&str1, &str2);
	printf("After Swapping :\tstr1 is %s\tstr2 is %s\n", str1, str2);
}
