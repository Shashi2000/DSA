/* Stack implementation using array */
#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX], ToS = -1;

enum choices {START, PUSH, POP, PEEK, IS_EMPTY, DISPLAY, INITIALIZE, EXIT};

void stack_menu();
void initialize_stack();
void stack_push();
void stack_pop();
void stack_peek();
void is_stack_empty();
void stack_display();    // top of stack = ToS

int main()
{
    int choice;
    
    stack_menu();
    do
    {
        
        // ask for choice
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
          case PUSH:            // PUSH = 1
            stack_push();
            break;
          case POP:             // POP = 2
            stack_pop();
            break;
          case PEEK:            // PEEK = 3
            stack_peek();
            break;
          case IS_EMPTY:        // IS_EMPTY = 4
            is_stack_empty();
            break;
          case DISPLAY:         // DISPLAY = 5
          {
            stack_display();
            break;
          }
          case INITIALIZE:      // INITIALIZE = 6 
          {
            initialize_stack();
            break;  
          }
          case EXIT:            // EXIT = 7
          {
            printf("\nTerminating the program.\n");
            exit(0);  
          }
            
          default:
            printf("Please enter a valid choice: (1 | 2 | 3 | 4 | 5 | 6 | 7)\n");
        }
         
         
    }
    while(choice != 7);
    
    
}


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
    printf("6: INITIALIZE (INSERT INITIAL VALUE TO STACK)\n");
    printf("7: EXIT       (TERMINATE THE PROGRAM)\n");
    printf("----------------------------------------------------------\n");
}

// initialize stack
void initialize_stack()
{
    if(ToS == MAX-1)
    {
        printf("OverFlow! Cannot insert any elements into full Stack.\n");        
        return;
    }
    else
    {
        printf("\nInitializing stack...\n");
        for(int i=ToS+1; i<MAX; i++)
        {
            printf("Enter the value to be pushed:\t");
            scanf("%d", &stack[i]);
            ToS++;
        }
    }
}

// push elements into top of the stack 
void stack_push()
{
    int val;
    // check for overflow
    if(ToS == MAX-1)
    {
        printf("\nStack overflow encountered !\n");
        return;
    }
   
    // push the value to the top of the stack
    printf("Enter the value to be pushed:\t");
    scanf("%d", &val);
    
    ToS++;
    // insert the value into array
    stack[ToS] = val;

}

void stack_pop()
{
    // check if stack is empty
    if(ToS == -1)
    {
        printf("UnderFlow! Cannot pefrom deletion as Stack is EMPTY!\n");
    }
    else
    {
        ToS--;
    }
}

// find the top of the stack 
void stack_peek()
{
    if(ToS != -1)
        printf("The top of the stack contains : %d.\n", stack[ToS]);
    else
        printf("Sorry! The Stack is empty.\n");
}

// find if the Stack is empty 
void is_stack_empty()
{
    if(ToS > -1)
        printf("The stack is not empty. It has %d elements currently.\n", ++ToS);
    else
        printf("The stack is empty.\n");
}

// display the stack members
void stack_display()
{
    int i;
    if(ToS == -1)
        printf("Sorry ! There is nothing in the stack to display.\n");
    else
        printf("The elements in current stack with size %d are:\n",MAX);
        
    // Display the elements of Stack 
    
    for(i=ToS; i >= 0; i--)
    {
       printf("|  %d  |\n", stack[i]);
       printf(" ------\n");
    }
}




