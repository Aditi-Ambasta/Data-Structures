#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}; struct Node *node,*front=NULL,*rear=NULL,*temp=NULL;

struct Node* createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));

    node->data=info;
    node->next=NULL;
    return node;
}

//addatend---->enqueue
//deleteatfront---->dequeue
//queuefront
//queuerear
//display

void enQueue(int data){
    node=createNode(data);
    if(front==NULL && rear==NULL){
        front=node;
        rear=node;
    }
    else{
        rear->next=node;
        rear=node;
    }
}

void deQueue(){
	if(front==NULL){
		printf("\n Queue is Empty");

	}
	else{
		temp=front;
		printf("\n%d Element Dequed",front->data);
		front=front->next;
		free(temp);

	}
}

void queueFront(){
	if(front==NULL){
		printf("\n Queue is Empty");
	}
	else{
		printf("Element at Front is: %d",front->data);

	}
}
void queueRear(){
	if(front==NULL){
		printf("\n Queue is Empty");
	}
	else{
		printf("Element at Rear is: %d",rear->data);

	}
}

void displayQueue(){
	if(front==NULL){
		printf("\n Queue is Empty");
	}
	else{
		printf("\n Queue is:");
		temp=front;
		while(temp!=NULL){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
	}
}

void main(){
	int data,choice;
    do{
	printf ("\n***LINKED LIST**\n1.EnQueue\n2.DeQueue\n3.QueueFront\n4.QueueRear\n5.Exit\n");
	printf("\n Enter Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\n Enter Data to add in Queue: ");
			scanf("%d",&data);
			enQueue(data);
			displayQueue();
			break;
		case 2: deQueue();
			displayQueue();
			break;
		case 3: queueFront();
			break;
		case 4:queueRear();
			break;
		case 5: exit(0);
			break;

        }
    }while(choice!=5);
    getch();
}