/*ethernet_interface.c 
Author: Swetha Varadarajan
Date created: May 25, 2017

Usage:
sudo ./a.out port_name ip_addr mac_addr

*need to use sudo mode in order to configure the address

Program to accept ip_addr and mac_addr
that needs to be configured for ethernet interface

*/


#include<stdio.h>
#include<stdlib.h>

void main(int argc,char** argv)
{
	char *port_name, *ip_addr, *mac_addr;
	char buffer[100];

	if(argc > 3)
	{	
		port_name = argv[1];
		ip_addr   = argv[2];
		mac_addr  = argv[3];
	}	
	else
	{
		printf("Usage:./a.out port_name ip_addr mac_addr\n");
		exit(0);
	}
	
	sprintf(buffer, "%s\t%s\t%s\n","ifconfig",port_name,ip_addr);
	printf(buffer);
	system(buffer);
	sprintf(buffer, "%s\t%s\t%s\t%s\t%s\n","ifconfig","eth0","hw","ether",mac_addr);
	printf(buffer);
	system(buffer);

}
