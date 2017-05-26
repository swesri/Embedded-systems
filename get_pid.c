/*get_pid.c 
Author: Swetha Varadarajan
Date created: May 25, 2017

Usage:
./a.out 

Program to print pid name using C program

*/

#include<stdio.h>


void main(int argc,char** argv)
{
	int pid;
	char buffer[100];
	pid = getpid();
	printf("I am in process, my process id: %d\n", getpid());
	printf("I am in process, my parent process id: %d\n", getppid());
	sprintf(buffer, "%s%u%s","cat /proc/",pid,"/comm");
	printf(buffer);
	system(buffer);

	while(1);
}
