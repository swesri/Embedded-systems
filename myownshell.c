/* 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main()
{

pid_t pid;
int option,stat,i,count=0,word=0;
char cmdbuf[80];
char temp[80];
char *charmsg[4];

	while(1)
	{
		printf("myshell>");
		//gets(cmdbuf);
		fgets (cmdbuf, 100, stdin);
		//printf("%s\n",cmdbuf);

		for(i=0;i<=strlen(cmdbuf);i++)
		{
			temp[count++]=cmdbuf[i];
			if(cmdbuf[i] == '\0')
			{
				printf("I came in!\n");
				count=0;
				charmsg[word++]=temp;
				//temp[0] = "NULL";
			}
		} 
		charmsg[word]=0;
		for(i=0;i<word;i++)
			printf("%s\n",charmsg[i]);

		if(strncmp(cmdbuf,"ver",3)==0)
		{
			printf("Simple shell version\n");
			continue;
		}

		if(strncmp(cmdbuf, "quit",4) ==0)
			exit(0);

		if(fork()==0)
		{
			if(execvp(charmsg[0],charmsg)<0)
			{
				printf("Here\n");
				perror("Error:");
			}
			exit(0);
		}
		pid=wait(&stat);

	}
}
