/*4linked_list.h
Author: Swetha Varadarajan
Date created: May 9,2017

Contains all the routines for linked list
*/


struct node
{
  int data;
  struct node *next;
};

void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data  = new_data;
	new_node->next = (*head_ref);
	(*head_ref)    = new_node;
}

void insertAfter(struct node* prev_node, int new_data)
{
	if (prev_node == NULL) 
	{ 
		printf("the given previous node cannot be NULL");       
		return;  
	}  
	  
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	new_node->data  = new_data;
	new_node->next = prev_node->next; 
	prev_node->next = new_node;
}

void append(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref; 
	new_node->data  = new_data; 
	new_node->next = NULL; 
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}  
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;    
}

void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void deleteNode(struct node **head_ref, int position)
{
	int i;
	if (*head_ref == NULL)
	return;

	struct node* temp = *head_ref;
	if (position == 0)
	{
		*head_ref = temp->next;   
		free(temp);               
		return;
	}

	for (i=0; temp!=NULL && i<position-1; i++)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
	 	return;

	struct node *next = temp->next->next;
	free(temp->next); 
	temp->next = next;  
}

void reverse_print(struct node *p)
{
	if(p==NULL)
		return;
	reverse_print(p->next);
	printf("%d ",p->data);
}

int getCount(struct node* head)
{
	int count = 0; 
	struct node* current = head;  
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int getCount_rec(struct node* head)
{
	if (head == NULL)
		return 0;
	return 1 + getCount(head->next);
}

void swapNodes(struct node **head_ref, int x, int y)
{
	if (x == y) return;

	struct node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	struct node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else 
		*head_ref = currY;  

	if (prevY != NULL)
		prevY->next = currX;
	else  
		*head_ref = currX;

	struct node *temp = currY->next;
	currY->next = currX->next;
	currX->next  = temp;
}

static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void recursiveReverse(struct node** head_ref)
{
	struct node* first;
	struct node* rest;

	if (*head_ref == NULL)
		return;   

	first = *head_ref;  
	rest  = first->next;

	if (rest == NULL)
		return;   

	recursiveReverse(&rest);
	first->next->next  = first;  

	first->next  = NULL;          
	*head_ref = rest;              
}

struct node* getTail(struct node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}


struct node* partition(struct node* head, struct node* end,
                       struct node** newHead, struct node** newEnd)
{
    struct node* pivot = end;
    struct node* prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct node* quickSortRecur(struct node* head, struct node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    struct node* newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct node* pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node** headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

int isCircular(struct node* head)
{
    // An empty linked list is circular
    if (head == NULL)
       return 1;
 
    // Next of head
    struct node* new_node = head->next;
 
    // This loop would stope in both cases (1) If
    // Circular (2) Not circular
    while (new_node != NULL && new_node != head)
       new_node = new_node->next;
 
    // If loop stopped because of circular
    // condition
    return (new_node == head);
}

void printMiddle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}
