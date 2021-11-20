/* Stack implementation using Linked list */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

enum choices { START, PUSH, POP , PEEK, IS_EMPTY, DISPLAY, EXIT };
enum boolean { true = 1, false = 0};

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *head = NULL;
int stack_count = 0;

void stack_push();
int stack_pop();
void stack_peek();
int is_empty();
void display_stack();
void stack_menu();
int integer_input();

void main()
{
    int choice;
    while(choice != EXIT)
    {
        stack_menu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case PUSH:
                stack_push();
                stack_count++;
                break;
            
            case POP:
                if(stack_pop())
                    stack_count--;
                break;
                
            case PEEK:
                stack_peek();
                break;
                
            case IS_EMPTY:
                is_empty()?printf("\nStack is empty."):printf("Stack is not empty. It contains %d elements", stack_count);
                break;
                
            case DISPLAY:
                display_stack();
                break;
                
            case EXIT:
                printf("\nTerminating .....");
                exit(0);
                
            default:
                printf("\nPlease enter valid choices : ");
        }
    }
}

// push items to the top of stack 
void stack_push()
{
    // push from top i.e head part of linked list
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) 
    {
        printf("\nCannot push as memory is not available.");
    }
    else
    {
        // take the data input from user
        new_node->data = integer_input();
        // link the node with previous head node 
        new_node->next = head;
        // update head pointer to point new node 
        head = new_node;
        
        // print message
        printf("\n%d pushed into top of stack successfully.", new_node->data);
        
    }
    
}

// pop elements from the top of stack 
int stack_pop()
{
    // pop/remove node from the begining 
    if(is_empty())
    {
        printf("\nUnderFlow! Cannot pop elements from Empty stack.");
        return false;
    }
    else
    {
        int temp_data= head->data;
        node *temp_head = head;
        
        head = head->next;
        
        // free the first node of list 
        free(temp_head);
        printf("\n%d poped from stack.", temp_data);
        
        return true;
    }
}

// peek the data at the top of stack 
void stack_peek()
{
    // print the data part of the head of list 
    if(is_empty())
        printf("\nCannot Peek. Stack is empty");
    else
        printf("\nThe top of Stack contains %d.", head->data);
}

// display the contents of stack 
void display_stack()
{
    node *temp_ptr = head;
    if(is_empty())
    {
        printf("\nOops! Stack is Empty.");
    }
    else
    {
        printf("\nTOS\n");
        while(temp_ptr != NULL)
        {
            // print the data part of nodes
            printf("%d\n", temp_ptr->data);
            
            // update temp_ptr to iterate forward
            temp_ptr = temp_ptr->next;
        }
    }   
}

// menu for stack operations 
void stack_menu()
{
    printf("\n----------------------------------------------------------\n");
    printf("Choose an operation to perform:\n");
    printf("----------------------------------------------------------\n");
    printf("1: PUSH       (ADD AN ELEMENT TO THE STACK)\n");
    printf("2: POP        (DELETE AN ELEMENT FROM THE TOP OF STACK)\n");
    printf("3: PEEK       (DISPLAY CONTENT AT THE TOP OF STACK)\n");
    printf("4: IS_EMPTY   (FIND IF THE STACK IS EMPTY)\n");
    printf("5: DISPLAY    (DISPLAY THE CONTENTS OF STACK)\n");
    printf("6: EXIT       (TERMINATE THE PROGRAM)\n");
    printf("----------------------------------------------------------\n");
}

// find if the stack is empty 
int is_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

// returns the integer input from user 
int integer_input()
{
    int temp_data;
    printf("\nEnter Integer value : ");
    scanf("%d", &temp_data);
    return temp_data;
}
