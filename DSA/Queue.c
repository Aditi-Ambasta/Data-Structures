//queue
#include<stdio.h>
#include<conio.h>
#define MAX 5
//enqueue, dequeue, queuefront, queuerear, display---->functions
int front=-1,rear=-1,queue[MAX];
void display()
{
    int i;
    if(rear==-1)
    printf("\n Queue is Empty.");
    else
    { 
        printf("FRONT:");
        for(i=front;i<=rear;i++)
        {
            printf("%d",queue[i]);
            printf(" ");
        }
        printf(":REAR");
    }
} 
void EnQueue(int data)
{
    if(rear==(MAX-1))
    printf("\n Queue is Full...");
    else
    {
        if(rear==-1)
            front=0;
        rear++;
        queue[rear]=data;
        printf("\n After Enqueue Operation Queue is:");
            display();
    }
    printf("\n FRONT=%d \t REAR=%d",front,rear);
}
void DeQueue()
{
    if(front==-1)
        printf("\n Queue is Underflow DeQueue Operation is not possible");
    else{
        printf("\n Element Dequeued is: %d\n",queue[front]);
        if(front==rear)
            front=rear=-1;
        else
            front++;
    display();
    printf("\n FRONT=%d \t REAR=%d",front,rear);
    }
}
void QueueFront()
{
    if(rear==-1)
        printf("\n Queue is Empty.");
    else
        printf("Data at the Front end of the Queue is: %d",queue[front]);
}
void QueueRear()
{
    if(rear==-1)
        printf("\n Queue is Empty.");
    else
        printf("Data at the Rear end of the Queue is: %d",queue[rear]);
}
int main()
{
 int data,choice;
do
    {
    printf("\n***QUEUE OPERATIONS***");
    printf("\n1. EnQueue\n2.DeQueue\n3.QueueFront\n4.QueueRear\n5.EXIT");
    printf("\n Enter The Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\n Enter Data to add into Queue:");
        scanf("%d",&data);
        EnQueue(data);
        break;
        case 2: DeQueue();
        break;
        case 3: QueueFront();
        break;
        case 4: QueueRear();
        break;
        case 5: printf("thankyou!");
                break;
        default: printf("\n Enter Correct Choice");
    }
    }while(choice!=5);
    getch();
    return 0;
} 