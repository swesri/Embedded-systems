/*2anagram_st.c
Author: Swetha Varadarajan
Date Created: May 8, 2017

Program to verify if given 2 strings are anagrams. 

Usage: 
./a.out string1 string2 optional_choice_to_select_method(default 0)

Option choice to select method:
0. Sorting and comparison of strings (default)
1. Counting and comparing the character array

Returns: If the strings are anagram or not.

Note: The program is not case-sensitive. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(char *s) //Bubble-sort
{
	char tmp;
	int i, j, length;
	length=strlen(s);
	for(i=0; i<length-1; i++)
		for (j=i+1; j<length; j++)
			if (s[i] > s[j])
	   		{
		 		tmp=s[i];
		 		s[i]=s[j];
		 		s[j]=tmp;
	   		}
}


void method0(char *str1, char *str2)
{
	sort(str1);
	sort(str2);
	
	if(!strcmp(str1,str2))
		printf("Given strings are anagrams\n");
	else
		printf("Given strings are not anagrams\n");
}

void method1(char *str1, char *str2)
{
	int i, *count1, *count2;
	count1 = (int*) calloc(128,sizeof(int));
	count2 = (int*) calloc(128,sizeof(int));

	for(i=0;i<strlen(str1);i++)
	{
		count1[str1[i]]++;
		count2[str2[i]]++;
	}		

	for(i=0;i<128;i++)
		if(count1[i]!=count2[i])
			{
				printf("Given strings are not anagrams\n"); 
				free(count1); free(count2); 
				exit(0);
			}
	
	free(count1); free(count2);
	printf("Given strings are anagrams\n");
	
}

void main(int argc,char** argv)
{
	char *str1, *str2;
	int choice=0;

	if(argc > 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		choice =1;
	}
	else if(argc > 2)
	{
		str1 = argv[1];
		str2 = argv[2];
	}
	else
	{
		printf("Usage:./a.out string1 string2 optional_choice_to_select_method\n");
		printf("Option choice to select method:\n");
		printf("0. Sorting and comparison of strings (default) \n1. Counting and comparing the character array\n");
		exit(0);
	}

	if(strlen(str1)==strlen(str2))
	{
		char tmp1, tmp2;
		int i=0;

		while (str1[i]) //make the program non case-sensitive
		{
			tmp1= toupper(str1[i]);
			str1[i]=tmp1; 
			tmp2= toupper(str2[i]); 
			str2[i]=tmp2; 
			i++;
		}
							
		if(choice)
			method1(str1,str2);
		else
			method0(str1,str2);
	}
	else
		printf("Given strings are not anagrams\n");
		
}
