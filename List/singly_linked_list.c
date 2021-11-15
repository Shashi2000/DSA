/* SINGLY LINKED LIST IMPLEMENTATION */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

/* =========================================================================
    TERMS USED :
        IN_BEG : INSERT IN BEGINING 
        IN_END : INSERT IN END 
        IN_AFTER_POS : INSERT AFTER POSITION 
        IS_EMPTY : CHECK IF LIST IS EMPTY 
        DISPLAY : TRAVERSE THROUGH THE WHOLE LIST 
        
    GLOBAL VARIABLES 
        head : points to the begining of list 
        tail : points to the ending of list 
        
     +---+----+     +---+----+      +---+----+      +---+----+ 
     | A |****|---->| B |****|----->| C |****|----->| D |****|----> NULL
     +---+----+     +---+----+      +---+----+      +---+----+ 

   ========================================================================= */

enum choices  {START, IN_BEG, IN_END, IN_AFTER_POS, IS_EMPTY, DISPLAY, EXIT };

struct Node
{
  int data;
  struct Node* next;
};

// change the struct Node to something small 
typedef struct Node node;

// global variables 
node* head = NULL;
node* tail = NULL; 

// functions 
void insert_at_begining();
void insert_at_end();
void insert_after_position();
void display_list();
void list_menu();
bool is_empty();
int integer_input();
char character_input();

// MAIN IMPLEMENTATION 

void main()
{
    int choice;
    do
    {
        list_menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case IN_BEG:
                insert_at_begining();
                break;
            case IN_END:
                insert_at_end();
                break;
            case IN_AFTER_POS:
                insert_after_position();
                break;
            case DISPLAY:
                display_list();
                break;
            case IS_EMPTY:
                is_empty()?printf("\nEmpty"):printf("\nNot Empty!");
                break;
            case EXIT:
                printf("\nTerminating ....");
                exit(0);
            default:
                printf("Please enter valid choice : (1 | 2 | 3 | 4 | 5 | 6)");
                
        }
    }
    while(choice != EXIT);
    
}


// insert a node at the begining of list 
void insert_at_begining()
{
    /*
        1. create a node 
        2. 
    */
    
    node* node_ptr = (node*)malloc(sizeof(node));
    
    if(is_empty())
    {
        // linked list is empty
        node_ptr->data = integer_input();
        
        // update head pointer
        head = node_ptr;
    }
    else
    {
        // linked list contains some nodes 
        
        // input the data into list
        node_ptr->data = integer_input();
        
        // update the head pointer 
        node_ptr->next = head;
        head = node_ptr;
    }
}


// insert a node at the end of list 
void insert_at_end()
{
    /* insert when list is completely empty 
       insert when list is partially empty
    */
    
    if(is_empty())
    {
        // its same as if we insert at the begining 
        insert_at_begining();
    }
    else
    {
        // create a node 
        node* node_ptr = (node*)malloc(sizeof(node));
        // insert value at the node 
        node_ptr->data = integer_input();
        
        node* temp_ptr = head;
        // find the last node of list 
        while(temp_ptr->next != NULL)
        {
            // get next node's address
            temp_ptr = temp_ptr->next;
        }
        
        // update the next and tail pointer
        temp_ptr->next = node_ptr;
        node_ptr->next = tail;
    }
    
}

// insert node after certain position 
void insert_after_position()
{
    int position, i;
    printf("\nEnter the position after which you want to insert a node : ");
    scanf("%d", &position);
    
    // if completely empty
    if(is_empty())
    {
        // position does not matter 
        insert_at_begining();
    }
    else
    {
        // create node 
        node* node_ptr = (node*)malloc(sizeof(node));
        // take data 
        node_ptr->data = integer_input();
        
        // traverse upto given position 
        node* temp_ptr = head;
        for(i=1; i<position; i++)
        {
            // update the temp_ptr 
            temp_ptr= temp_ptr->next;
        }
        // store the location of next node 
        node* next_node = temp_ptr->next;
        // insert the node 
        temp_ptr->next = node_ptr;
        node_ptr->next = next_node;
        
    }
}

bool is_empty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

void display_list()
{
    /* traverse form head to tail in linked list */
    
    node* temp_ptr = head;
    // check if the list is empty
    if(is_empty())
    {
        printf("\nList is empty!");
        return;
    }
    else
    {
        while(temp_ptr != NULL)
        {
            printf("%d--> ", temp_ptr->data);
            temp_ptr = temp_ptr->next;
        }
        if(temp_ptr == NULL)
            printf("NULL");
    }
}

// take integer input from user
int integer_input()
{
    int temp_int_data;
    printf("\nEnter the integer data : ");
    scanf("%d", &temp_int_data);
    return temp_int_data;
}

// take character input from user
char character_input()
{
    char temp_char_data;
    printf("Enter the character : ");
    scanf("%c", &temp_char_data);
    return temp_char_data;
}

// menu for list
void list_menu()
{
    printf("\n----------------------------------------------------------\n");
    printf("Choose an operation to perform:\n");
    printf("----------------------------------------------------------\n");
    printf("1: IN_BEG             (ADD AN ELEMENT IN THE BEGINING)\n");
    printf("2: IN_END             (ADD AN ELEMENT IN THE END)\n");
    printf("3: IN_AFTER_POS       (ADD AN ELEMENT AFTER GIVEN POSITION)\n");
    printf("4: IS_EMPTY           (FIND IF THE LIST IS EMPTY)\n");
    printf("5: DISPLAY            (DISPLAY THE CONTENTS OF LIST)\n");
    printf("6: EXIT               (TERMINATE THE PROGRAM)\n");
    printf("----------------------------------------------------------\n");
}
