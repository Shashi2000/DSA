/* SINGLY LINKED LIST IMPLEMENTATION */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

/* =========================================================================
    TERMS USED :
        IN_BEG       : INSERT IN BEGINING 
        IN_END       : INSERT IN END 
        IN_AFTER_POS : INSERT AFTER POSITION 
        DEL_FROM_BEG : DELETE NODE FROM HEAD POSITION
        DEL_FROM_END : DELETE NODE FROM TAIL POSITION
        DEL_AT_POS   : DELETE NODE ON THE BASIS OF GIVEN POSITION (INPUT)
        IS_EMPTY     : CHECK IF LIST IS EMPTY 
        DISPLAY      : TRAVERSE THROUGH THE WHOLE LIST 
        SEARCH       : SEARCH FOR THE NODE WITH PARTICULAR KEY
        
    GLOBAL VARIABLES 
        head         : points to the begining of list 
        tail         : points to the ending of list 
        list_count   : takes account of the elements in list
        
     +---+----+     +---+----+      +---+----+      +---+----+ 
    | A  |****|--->| B  |****|---->| C  |****|---->| D  |****|----> NULL
    +---+----+     +---+----+      +---+----+      +---+----+ 

   ========================================================================= */

enum choices  
{
    EXIT, IN_BEG, IN_END, IN_AFTER_POS, 
    DEL_FROM_BEG, DEL_FROM_END, DEL_AFTER_POS, 
    IS_EMPTY, DISPLAY, SEARCH 
};

struct Node
{
  int data;
  struct Node* next;
};

// change the struct Node to something small 
typedef struct Node node;

// global variables 
node* head = NULL;
node* tail = NULL; // optional
int list_count = 0;

// insertion of nodes into list 
void insert_at_begining();
void insert_at_end();
void insert_after_position();

// deletion of nodes from list 
void delete_from_begining();
void delete_from_end();
void delete_after_position();

// search 
void search_node();

// helper functions 
void display_list();
void list_menu();
void mini_menu();
bool is_empty();

// helper functions
int get_correct_position();
int integer_input();
char character_input();

// MAIN IMPLEMENTATION 
void main()
{
    printf("%p", head);
    int choice;
    list_menu();
    do
    {
        mini_menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice)
        {
            case IN_BEG:
                insert_at_begining();
                list_count++;
                break;
                
            case IN_END:
                insert_at_end();
                list_count++;
                break;
                
            case IN_AFTER_POS:
                insert_after_position();
                list_count++;
                break;
                
            case DEL_FROM_BEG:
                delete_from_begining();
                list_count--;
                break;
                
            case DEL_FROM_END:
                delete_from_end();
                list_count--;
                break;
                
            case DEL_AFTER_POS:
                delete_after_position();
                list_count--;
                break;
                
            case DISPLAY:
                display_list();
                break;
                
            case IS_EMPTY:
                is_empty()?printf("\nEmpty"):printf("\nNot Empty!\nList contains %d elements.", list_count);
                break;
                
            case SEARCH:
                search_node();
                break;
                
            case EXIT:
                printf("\nTerminating ....");
                exit(0)
                    ;
            default:
                printf("\nPlease enter valid choice : (1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0)");
                
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
    
    // input the data into list
    node_ptr->data = integer_input();
    
    // update the head pointer 
    node_ptr->next = head;
    head = node_ptr;
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
    int i, position = get_correct_position();
    
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

// deletion_from_begining
void delete_from_begining()
{
    if(is_empty())
    {
        printf("\nCannot perfom deletion. List is empty.");
    }
    else
    {
        // get the second node 
        node *second_node = head->next;
    
        // free the memory
        printf("\nElement %d from begining of list is deleted successfully.", head->data);
        free(head);
        
        // update the head field to point second_node 
        head = second_node;
        
    }
}

// DELETION FROM THE END I.E TAIL OF LIST
void delete_from_end()
{
    node *last_node = head;
    node *prev_node;
    
    // check if list is empty 
    if(is_empty())
    {
        printf("\nCannot perfom deletion. List is empty.");
    }
    else
    {
        // list has only one element i.e head and tail is same 
        if(head->next == NULL)
        {
            printf("\nOnly one element found.\nNode containing %d is removed successfully from end.", head->data);
            free(last_node);
            // update the head as list is empty  
            head = NULL;
        }
        else
        {
            // list has two or more elements 
            
            // traverse to the last node 
            while(last_node->next != NULL)
            {
                prev_node = last_node;
                last_node = last_node->next;
            }
            
            // unlink the last node 
            prev_node->next = NULL;
            
            printf("\nNode containing %d is removed successfully from end of list.", last_node->data);
            free(last_node);
        }
    }
}


// DELETION OF NODE AT GIVEN POSITION 
void delete_after_position()
{
    // find the required node at given position
    int position = get_correct_position();
    int temp_data, i;
    
    node *temp_node = head;
    node *next_node;
    
    if(is_empty())
    {
        printf("\nCannot perform deletion as list is empty.");
    }
    else
    {
        // list has only one element 
        if(head->next == NULL)
        {
            printf("\nOnly one element found.\nNode containing %d is removed successfully from end.", head->data);
            free(temp_node);
            // update the head as list is empty  
            head = NULL;
        }
        else if(position == 1)
        {
            // remove the first element from the list 
            delete_from_begining();
        }
        else
        {
            // traverse upto given position -1 
            for(i=1; i < position -1; i++)
            {
                // find the next_node 
                temp_node = temp_node->next;
            }
            // store data for printing.
            temp_data = temp_node->data;
            
            // get the node to be deleted 
            next_node = temp_node->next;
            
            // unlink the node to be deleted 
            temp_node->next = next_node;
            
            // free the memory 
            free(temp_node);
            printf("\nNode containing %d is deleted successfully.", temp_data);
        }
    }
    
}

// CHECK IF LIST IS EMPTY (RETURNS BOOLEAN VALUES)
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
    
    // check if the list is empty
    if(is_empty())
    {
        printf("\nList is empty!");
        return;
    }
    else
    {
        node* temp_ptr = head;
        while(temp_ptr != NULL)
        {
            printf("%d--> ", temp_ptr->data);
            temp_ptr = temp_ptr->next;
        }
        if(temp_ptr == NULL)
            printf("NULL");
    }
}

// SEARCH PARTICULAR NODE BASED ON KEY
void search_node()
{
    // get the value to search for 
    int key = integer_input();
    int flag, index = 1;
    node *temp_node = head;
    
    if(is_empty())
    {
       printf("\nList is empty.");
    }
    else
    {
        while(temp_node->next != NULL)
        {
            if(temp_node->data == key)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            
            // update the index 
            index++;
            // termination criteria for loop
            temp_node = temp_node->next;
        }
        // if the node with key is found then
        if(flag == 1)
        {
            printf("\n%d found at position %d.", key, index);
        }
        else
        {
            printf("\n%d not found in the list.", key);
        }
        
    }
}

// GET APPROPIRATE POSITIONAL VALUES FROM USER (VALIDATE THE POSITION GIVEN BY USER)
int get_correct_position()
{
    int pos, i;
    do
    {
        // if list is empty pos does not matter 
        if(head == NULL)
        {
            return 0;
        }
        else
        {
            printf("\nEnter the position after which you want to insert a node : ");
            scanf("%d", &pos);
            
            // give error msg
            if(pos > list_count)
                printf("\nInvalid position given! List has only %d elements.", list_count);
        }
    }
    while(pos > list_count);
    
    return pos;
}

// TAKE INTEGER INPUT FROM USER
int integer_input()
{
    int temp_int_data;
    printf("\nEnter the integer data : ");
    scanf("%d", &temp_int_data);
    return temp_int_data;
}

// TAKE CHARACTER INPUT FROM USER (* CHARACTER AS DATA PART OF LIST) 
char character_input()
{
    char temp_char_data;
    printf("Enter the character : ");
    scanf("%c", &temp_char_data);
    return temp_char_data;
}

// DESCRIPTIVE MENU OF AVAILABLE ACTIONS TO BE PERFORMED ON LIST
void list_menu()
{
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("====================== Choose an operation to perform: ======================\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("1  : IN_BEG             (ADD AN ELEMENT IN THE BEGINING)\n");
    printf("2  : IN_END             (ADD AN ELEMENT IN THE END)\n");
    printf("3  : IN_AFTER_POS       (ADD AN ELEMENT AFTER GIVEN POSITION)\n");
    printf("4  : DEL_FROM_BEG       (REMOVE AN ELEMENT FROM THE BEGINING)\n");
    printf("5  : DEL_FROM_END       (REMOVE AN ELEMENT ROM THE END)\n");
    printf("6  : DEL_AFTER_POS      (REMOVE AN ELEMENT AFTER GIVEN POSITION)\n");
    printf("7  : IS_EMPTY           (FIND IF THE LIST IS EMPTY)\n");
    printf("8  : DISPLAY            (DISPLAY THE CONTENTS OF LIST)\n");
    printf("9  : SEARCH             (SEARCH THE NODE CONTAINING GIVEN DATA)\n");
    printf("0  : EXIT               (TERMINATE THE PROGRAM)\n");
    printf("------------------------------------------------------------------------------\n");
}

// MINIFIED VERSION OF DESCRIPTIVE MENU 
void mini_menu()
{
    printf("\n");
    printf("+------------------------------------------------------------------------------+\n");
    printf("| [ 1: IN_BEG | 2: IN_END | 3: IN_AFTER_POS | 4: DEL_FROM_BEG | 9: SEARCH ]    |\n");
    printf("+------------------------------------------------------------------------------+\n");
    printf("| [ 5: DEL_FROM_END | 6: DEL_AFTER_POS   | 7: IS_EMPTY | 8: DISPLAY | 0: EXIT] |\n");
    printf("+------------------------------------------------------------------------------+\n");
}
