//circular queue
#include<conio.h>
#include<stdio.h>
#define N 5

int front=-1; int rear=-1; int queue[N];

void Enque(int data);
void Dequeue();
void display();

int main()
{
	int choice, data;
	do
	{
		printf("\n****QUEUE OPERATION****\n1.ADD IN QUEUE\n2.DELETE IN THE QUEUE\n3.DISPLAY THE LIST\n4.EXIT");
		printf("\nEnter your choice"); 
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to add in queue "); 
                scanf("%d",&data);
				Enque(data);
				printf("\nDisplaying the List: ");
				display();
				break;

			case 2:
				Dequeue();
				printf("\nDisplaying the List: ");
				display();
				break;

			case 3:
				printf("The Queue list is: "); 
                display();
				break;
			case 4:
				printf("thanks ok!");
				break;

		}
	} while(choice!=4);
	return 0;
}

void Enque(int data)
{
	if(front==-1 && rear==-1)
	{
		front=0; rear=0;
		queue[rear]=data;
	}
	else if((rear+1)%N==front)
	{
		printf("\nThe Queue is Full");
	}
	else
	{
		rear=(rear+1)%N;
		queue[rear]=data;

	}
}


void Dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is Empty");
	}
	else if(front==rear)
	{

		front=-1; rear=-1;
		printf("\nQueue is Empty");
	}
	else
	{
		printf("\nDeleted Element of the Queue",queue[front]);
		front=(front+1)%N;

	}
}

void display()
{
	int i; 
    printf("\n");
	if(front==-1 && rear==-1)
		printf("\nQueue is Empty");
	else
	{
	 if (front > rear)
	{
		for (i = front; i < N; i++)
		{
			printf("%d ", queue[i]);
		}
		for (i = 0; i <= rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	else
	{
		for (i = front; i <= rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	}
}
