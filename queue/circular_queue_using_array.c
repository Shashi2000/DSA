/* Circular Queue implementation using array */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1, circular_queue[SIZE];

enum choices {START, ENQUEUE, DEQUEUE, DISPLAY, PEEK, IS_FULL, IS_EMPTY, EXIT};

void display_menu();
void mini_menu();
void enQueue();
void deQueue();
void peek();
void display_queue();
bool is_full();
bool is_empty(); 

int main()
{
    int choice; 
    
    // mega menu 
    display_menu();
    do
    {
        // display menu
        mini_menu();
        printf("Enter your choice :\t");
        scanf("%d", &choice);
        
        // perform specific actions based on 
        switch(choice)
        {
            case ENQUEUE:
                enQueue();
                break;
            case DEQUEUE:
                deQueue();
                break;
            case PEEK:
                peek();
                break;
            case DISPLAY:
                display_queue();
                break;
            case IS_FULL:
                (is_full())? printf("Queue is full!\n"): printf("Queue is not full\n");
                break;
            case IS_EMPTY:
                (is_empty())? printf("Queue is Empty!\n"): printf("Queue is not Empty\n");
                break;
            case EXIT:
                printf("Terminating program.....");
                exit(0);
            default:
                printf("Enter valid choices (1 | 2 | 3 | 4 | 5 |) :\t");
        }
    }
    while(choice != 7);
    

    return 0;
}

void display_menu()
{
    printf("\t\tSelect the operation:\n");
    printf("\t\t|====================================================|\n");
    printf("\t\t|1\t: Insert Element into Queue                 |\n");
    printf("\t\t|2\t: Delete Element from Queue                 |\n");
    printf("\t\t|3\t: Display Elements of Queue                 |\n");
    printf("\t\t|4\t: Peek the front  of Queue                  |\n");
    printf("\t\t|5\t: Check if the Queue is full                |\n");
    printf("\t\t|6\t: Check if the Queue is empty               |\n");
    printf("\t\t|7\t: Exit                                      |\n");
    printf("\t\t|====================================================|\n");
    
}

void mini_menu()
{
    printf("\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("| [1: Inqueue | 2: Dequeue | 3: Display Queue | 4: Peek  | 5: IS_FULL | 6: IS_EMPTY | 7: EXIT] |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
}

// insert element into the Queue
void enQueue()
{
    // check if the queue is full 
    if((rear == SIZE-1 && front == 0) || (front == rear + 1))
    {
        // queue is full
        printf("OverFlow! Queue is full.\n");
        return;
    }
    else
    {
        // queue is completely empty 
        if(rear == -1)      // only rear can be checked
        {
            front = 0;
            rear = 0;
        }
        else if(rear == SIZE - 1)       // front <= 0 but front != 0 in this case 
        {
            // circular queue implementation
            rear = 0;
        }
        else
        {
            // queue is not completely filled
            rear++;
        }
        
    }
    
    // take input for insertion into the queue         
    printf("Enter the element to insert into the Queue :  ");
    scanf("%d", &circular_queue[rear]);
    printf("%d entered into the Queue.", circular_queue[rear]);
    
}

// delete element from the Queue i.e from front 
void deQueue()
{
    // check if the queue is empty
    if(front != -1)
    {
        int temp = circular_queue[front];
        
         
        if(front == rear)
        {
            // there is only one element left so initialize to the begining
            front = -1;
            rear = -1;
        }
        else if(front == SIZE - 1)
        {
            // front gets to the end so we set it to the front of Circular queue 
            front = 0;
        }
        else
            front++;
        // Queue is not empty so delete element from the front
        printf("%d removed from the front of the Queue.\n", temp);
    }
    else
    {
        // there is underflow
        printf("UnderFlow! Cannot perfom deletion on Empty Queue.\n");
    }
}

// peek the front of queue 
void peek()
{
    if(front == -1)
        printf("Oops! Queue is empty.\n");
    else
        printf("The front of the Queue contains : %d\n", circular_queue[front]);
        
}

// display the elements of queue 
void display_queue()
{
    int i;
    if(rear != -1)
    {
        // display the queue 
        printf("The contents of Queue are : ");
        /*
            |*|x|x|*|*|     |*|*|x|*|*|         |*|*|*|*|*|
            R      F           R   F             F      R
        */
        if(front > rear)
        {
            // display first half from the front of the queue 
            for(i = front; i < SIZE; i++)
            {
                printf("%d ", circular_queue[i]);
            }
            
            // display second half upto front from 0 to rear
            for(i = 0; i <= rear; i++)
            {
                printf("%d ", circular_queue[i]);
            }
            
        }
        else
        {
            /*
                |*|*|*|*|*|     |*|*|*|*|*|    
                F        R         F     R
            */
            for(i = front; i<= rear; i++)
            {
                
                printf("%d  ", circular_queue[i]);
                if(i != rear)
                    printf(", ");
            }
        }
    }
    else
    {
        printf("Oops! There is no element in Queue to display.\n");
    }
}

// check if queue is empty
bool is_empty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

// check if queue is full 
bool is_full()
{
    if((rear == SIZE -1 && front == 0) || (front == rear+1))
        return true;
    else
        return false;
}





