#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
}; 

int size = 0; 
  
struct Node* create_Node(int data) 
{ 
    // allocating space 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
  
void insert_node(struct Node** current, int pos, int data) 
{ 
	if (pos < 1 || pos > size + 1) 
		printf("position %d is not valid\n", pos);
	else { 
		while (pos--) {
			if (pos == 0) { 
					struct Node* temp = create_Node(data);
					temp->next = *current; 
					*current = temp; 
			} 
			else
				current = &(*current)->next; 
			} 
			size++; 
	} 
} 
  
void print_list(struct Node* head) 
{ 
    while (head != NULL) { 
				printf(" %d", head->data);
        head = head->next; 
    } 
    printf("  size is: %d\n", size);
} 

int main() 
{ 
	struct Node* head = NULL;

	//filling the intial list manually
	head = create_Node(1);
  head->next = create_Node(2); 
  head->next->next = create_Node(3); 
  head->next->next->next = create_Node(4);
	size = 4;

	printf("list before insertion: \n");
	print_list(head); 

	printf("list after insertion of 10 at position 5: \n"); 
	insert_node(&head, 5, 10); 
	print_list(head); 

	printf("list after insertion of 0 at position 1:  \n");
	insert_node(&head, 1, 0); 
	print_list(head); 
 
	printf("list after insertion of 200 at position 10:  \n");
	insert_node(&head, 10, 200); 
	print_list(head); 

	return 0; 
} 

