/*1bitwise_op.c 
Author: Swetha Varadarajan
Date created: May 8, 2017

Usage:
./a.out number_to_manipulate (default is 255)

Program to do bitwise operations on a given number:
1. bit set
2. bit clear
3. multiple bit set
4. multiple bit clear
5. replace bits with a mask

Option provided to perform 
1. one manipulation on a given number (default: set PassByRef to 0)
2. multiple manipulations on a given number (set PassByRef to 1)

Option provided to change number during the execution. 

Displays the output in both decimal and binary form. 
*/


#include<stdio.h>
#include<stdlib.h>
#define PassByRef 0 

//ToDo: Provide condition to mute print statements when using as a part of big project. 
 

void bin(unsigned int n)
{
	if (n > 1)
	        bin(n/2);
	printf("%u", n % 2);
}

void bit_set(unsigned int number, unsigned int position)
{
	printf("----------Bit-set---------\n");
	printf("Bit Position:\t%u\n",position);
	printf("Number before:\t%u\t", number); bin(number); printf("\n");
	number |= 1 << position;
	printf("Number after:\t%u\t", number); bin(number); printf("\n");
	printf("--------------------------\n");
}

void bit_set_PBR(unsigned int *number, unsigned int position)
{
	printf("----------Bit-set---------\n");
	printf("Bit Position:\t%u\n",position);
	printf("Number before:\t%u\t", *number); bin(*number); printf("\n");
	*number |= 1 << position;
	printf("Number after:\t%u\t", *number); bin(*number); printf("\n");
	printf("--------------------------\n");
}

void bit_clear(unsigned int number, unsigned int position)
{
	printf("----------Bit-clear---------\n");
	printf("Bit Position:\t%u\n",position);
	printf("Number before:\t%u\t", number); bin(number); printf("\n");
	number &= ~(1 << position);
	printf("Number after:\t%u\t", number); bin(number); printf("\n");
	printf("--------------------------\n");
}

void bit_clear_PBR(unsigned int *number, unsigned int position)
{
	printf("----------Bit-clear---------\n");
	printf("Bit Position:\t%u\n",position);
	printf("Number before:\t%u\t", *number); bin(*number); printf("\n");
	*number &= ~(1 << position);
	printf("Number after:\t%u\t", *number); bin(*number); printf("\n");
	printf("--------------------------\n");
}

void bits_set(unsigned int number, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-set---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Number before:\t%u\t", number); bin(number); printf("\n");
	number |= (((1<<(end_position-start_position+1))-1) << start_position);
	printf("Number after:\t%u\t", number); bin(number); printf("\n");
	printf("--------------------------\n");
}

void bits_set_PBR(unsigned int *number, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-set---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Number before:\t%u\t", *number); bin(*number); printf("\n");
	*number |= (((1<<(end_position-start_position+1))-1) << start_position);
	printf("Number after:\t%u\t", *number); bin(*number); printf("\n");
	printf("--------------------------\n");
}

void bits_clear(unsigned int number, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-clear---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Number before:\t%u\t", number); bin(number); printf("\n");
	number &= ~(((1<<(end_position-start_position+1))-1) << start_position);
	printf("Number after:\t%u\t", number); bin(number); printf("\n");
	printf("--------------------------\n");
}

void bits_clear_PBR(unsigned int *number, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-clear---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Number before:\t%u\t", *number); bin(*number); printf("\n");
	*number &= ~(((1<<(end_position-start_position+1))-1) << start_position);
	printf("Number after:\t%u\t", *number); bin(*number); printf("\n");
	printf("--------------------------\n");
}

void bits_replace(unsigned int number, unsigned int mask, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-replace---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Mask:\t%u\t",mask); bin(mask); printf("\n");
	printf("Number before:\t%u\t", number); bin(number); printf("\n");
	number &= ~(((1<<(end_position-start_position+1))-1) << start_position);
	number |= mask<<start_position;
	printf("Number after:\t%u\t", number); bin(number); printf("\n");
	printf("--------------------------\n");
}

void bits_replace_PBR(unsigned int *number, unsigned int mask, unsigned int start_position, unsigned int end_position)
{
	if(start_position>end_position)
	{
		printf("Enter valid bit positions (start_posiiton < end_position)\n");
		return;
	}
	printf("----------Bits-replace---------\n");
	printf("Bit Start Position:\t%u\n",start_position);
	printf("Bit End Position:\t%u\n",end_position);
	printf("Mask:\t%u\t",mask); bin(mask); printf("\n");
	printf("Number before:\t%u\t", *number); bin(*number); printf("\n");
	*number &= ~(((1<<(end_position-start_position+1))-1) << start_position);
	*number |= mask<<start_position;
	printf("Number after:\t%u\t", *number); bin(*number); printf("\n");
	printf("--------------------------\n");
}

void main(int argc,char** argv)
{
	unsigned int choice;
	unsigned int number=0xFF, mask;
	unsigned int position, start_position, end_position;

	if(argc > 1)
		number = atoi(argv[1]);

	while(1)
	{
		printf("Please enter one of the following choice to do bit manipulation on %u:\n", number);
		printf("1. Bit set\n");
		printf("2. Bit clear\n");
		printf("3. Bits set\n");
		printf("4. Bits clear\n");
		printf("5. Replace bits\n");
		printf("6. Enter new number\n");
		printf("7. Exit\n");
		scanf("%u",&choice);

		if(choice==7)
			exit(0);

		printf("The number of bits in the number is %lu\n", sizeof(number)*8);
		printf("Please enter the bit position from 0 to %lu\n", (sizeof(number)*8)-1);

		if(choice == 1)
		{
			printf("Enter position to set bit\n");
			scanf("%u",&position);	
			#if PassByRef
				bit_set_PBR(&number, position);
			#else
				bit_set(number, position);
			#endif
		}
		else if(choice == 2)
		{
			printf("Enter position to set clear\n");
			scanf("%u",&position);	
			#if PassByRef
				bit_clear_PBR(&number, position);
			#else
				bit_clear(number, position);
			#endif
		}
		else if(choice == 3)
		{
			printf("Enter start position to set bit\n");
			scanf("%u",&start_position);
			printf("Enter end position to set bit\n");
			scanf("%u",&end_position);	
			#if PassByRef
				bits_set_PBR(&number, start_position, end_position);
			#else
				bits_set(number, start_position, end_position);
			#endif
		}
		else if(choice == 4)
		{
			printf("Enter start position to clear bit\n");
			scanf("%u",&start_position);
			printf("Enter end position to clear bit\n");
			scanf("%u",&end_position);	
			#if PassByRef
				bits_clear_PBR(&number, start_position, end_position);
			#else
				bits_clear(number, start_position, end_position);
			#endif
		}
		else if(choice == 5)
		{
			printf("Enter the mask bits to replace in the given number\n");
			scanf("%u",&mask);
			printf("Enter start position of the mask bit\n");
			scanf("%u",&start_position);
			printf("Enter end position of the mask bit\n");
			printf("Caution!! end_position - start_position = number of bits in the mask\n");
			scanf("%u",&end_position);	
			#if PassByRef
				bits_replace_PBR(&number, mask, start_position, end_position);
			#else
				bits_replace(number, mask, start_position, end_position);
			#endif
		}
		else if(choice == 6)
		{
			printf("Enter the new number\n");
			scanf("%u",&number);
		}
		else
			printf("Please enter a valid choice\n");	 	
	}
}
