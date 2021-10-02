/* Queue implementation using array */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1, linear_queue[SIZE];

enum choices {START, ENQUEUE, DEQUEUE, DISPLAY, PEEK, EXIT};

void display_menu();
void mini_menu();
void enQueue();
void deQueue();
void peek();
void display_queue();

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
            case EXIT:
                exit(0);
            default:
                printf("Enter valid choices (1 | 2 | 3 | 4 | 5 |) :\t");
        }
    }
    while(choice != 5);
    

    return 0;
}

void display_menu()
{
    printf("\tSelect the operation:\n");
    printf("\t|====================================================|\n");
    printf("\t|1\t: Insert Element into Queue                  |\n");
    printf("\t|2\t: Delete Element from Queue                  |\n");
    printf("\t|3\t: Display Elements of Queue                  |\n");
    printf("\t|4\t: Peek the front  of Queue                   |\n");
    printf("\t|5\t: Exit                                       |\n");
    printf("\t|====================================================|\n");
    
}

void mini_menu()
{
    printf("\n");
    printf("+--------------------------------------------------------------------+\n");
    printf("| [1: Inqueue | 2: Dequeue | 3: Display Queue | 4: Peek  | 5: Exit ] |\n");
    printf("+--------------------------------------------------------------------+\n");
}

// insert element into the Queue
void enQueue()
{
    // check if the queue is full 
    if(rear == SIZE-1)
    {
        // queue is full
        printf("OverFlow! Queue is full.\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        // if the queue is completely empty then
        front = 0;
        rear = 0;
    }
    else
    {
        // queue is not completely filled
        rear++;
    }
    
    // take input for insertion into the queue         
    printf("Enter the element to insert into the Queue :  ");
    scanf("%d", &linear_queue[rear]);
    printf("%d entered into the Queue.", linear_queue[rear]);

    
}

// delete element from the Queue i.e from front 
void deQueue()
{
    // check if the queue is empty
    if(front != -1)
    {
        // Queue is not empty so delete element from the front
        printf("%d removed from the front of the Queue.\n", linear_queue[front]);
        
        // increase the front 
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
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
    if(front == -1 && rear == -1)
        printf("Oops! Queue is empty.\n");
    else if(front <= rear)
        printf("The front of the Queue contains : %d\n", linear_queue[front]);
}

// display the elements of queue 
void display_queue()
{
    int i;
    if(rear != -1)
    {
        // display the queue 
        printf("The contents of Queue are : ");
        for(i = front; i <= rear; i++)
        {
            printf("%d  ", linear_queue[i]);
            if(i != rear)
                printf(", ");
        }
    }
    else
    {
        printf("Oops! There is no element in Queue to display.\n");
    }
}







