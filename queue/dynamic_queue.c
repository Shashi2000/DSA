/* IMPLEMENTATION OF QUEUE USING SINGLY LINKED LIST  */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

enum choices {
    START, ENQUEUE, DEQUEUE, FRONT, REAR, IS_EMPTY, DISPLAY, EXIT
};

// BLUE PRINT OF NODE 
struct Node 
{
    int data;
    struct Node *next;
};

typedef struct Node node;

// global variables
node *head = NULL;
int no_of_elements = 0;

void enQueue();
void deQueue();
void front();
void rear();
bool isEmpty();
void display_queue();
void menu();
int integer_input();

void main()
{
    int choices;
    do
    {
        menu();
        printf("\nEnter your choice : ");
        choices = integer_input();
        
        switch(choices)
        {
            case ENQUEUE:
                printf("\nEnter an integer : ");
                enQueue();
                no_of_elements++;
                break;
                
            case DEQUEUE:
                deQueue();
                no_of_elements--;
                break;
                
            case FRONT:
                front();
                break;
                
            case REAR:
                rear();
                break;
                
            case IS_EMPTY:
                if(isEmpty())
                    printf("\nUnderFlow Queue is empty.");
                else
                    printf("\nQueue is not Empty. It contains %d elements.", no_of_elements);
                break;
                
            case DISPLAY:
                display_queue();
                break;
                
            case EXIT:
                printf("\nTerminating ....");
                exit(0);
                
            default:
                printf("\nPlease enter valid choices (1 | 2 | 3 | 4 | 5 | 6 | 7) :");
        }
    }
    while(choices != EXIT);
}

// INSERT ELEMENT INTO QUEUE 
void enQueue()
{
    /*
        |A|**|-->|B|**|-->|C|**|-->|D|**|-->NULL 
        
        INSERT FROM THE END 
    */
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("\nMemory couldn't be allocated.");
    }
    else 
    {
        // take input for data 
        new_node->data = integer_input();
        
        if(isEmpty())
        {
            head = new_node;
            new_node->next = NULL;
        }
        else
        {
            // traverse to the end of list 
            node *last_node = head;
            while(last_node->next != NULL)
            {
                last_node = last_node->next;
            }
            
            last_node->next = new_node;
            new_node->next = NULL;
        }
        
        printf("\n%d inserted successfully from rear position.", new_node->data);
    }
}

// DELETE ELEMENT FROM QUEUE 
void deQueue()
{
    node *first_node = head;
    
    if(isEmpty())
    {
        printf("\nUnderFlow! Queue is empty.");
    }
    else
    {
        int temp_data = first_node->data;
        head = first_node->next;
        free(first_node);
        printf("%d removed successfully from front of Queue.", temp_data);
    }
}

// DISPLAY ELEMENTS OF QUEUE 
void display_queue()
{
    if(isEmpty())
    {
        printf("\nOops! The Queue is Empty.");
    }
    else
    {
        node *temp_node = head;
        printf("FRONT <-- ");
        while(temp_node != NULL)
        {
            printf("%d  ", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("<-- REAR");
    }
}

// DISPLAY FRONT ELEMENT OF QUEUE 
void front()
{
    if(!isEmpty())
        printf("\nThe element at the front of Queue is %d", head->data);
    else
        printf("\nQueue is empty");
}

// DISPLAY REAR ELEMENT OF QUEUE 
void rear()
{
    node *last_node = head;
    if(isEmpty())
    {
        printf("\nOops! The Queue is Empty.");
    }
    else
    {
        // traverse upto last node of list 
        while(last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        printf("\nThe element at rear position of Queue is %d", last_node->data);
    }
}

// FIND IF THE QUEUE IS EMPTY 
bool isEmpty()
{
    if(head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// TAKE INTEGER INPUT FROM USER
int integer_input()
{
    int temp_integer_data;
    scanf("%d", &temp_integer_data);
    return temp_integer_data;
}

// MENU FOR QUEUE 
void menu()
{
    printf("\n");
    printf("+-------------------------------------------------------------------------------------------+\n");
    printf("|                                   PERFORM QUEUE OPERATION                                 |\n");
    printf("+-------------------------------------------------------------------------------------------+\n");
    printf("+-------------------------------------------------------------------------------------------+\n");
    printf("| [1: ENQUEUE | 2: DEQUEUE | 3: FRONT | 4: REAR | 5: IS_EMPTY  | 6 : DISPLAY | 7 : EXIT   ] |\n");
    printf("+-------------------------------------------------------------------------------------------+\n");
}
