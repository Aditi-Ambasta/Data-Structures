#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int count=0;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node *node, *list=NULL, *last=NULL,*temp=NULL,*p=NULL,*q=NULL;

struct Node *createNode(int info) {
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));

	node->data=info;
	node->prev=NULL;
	node->next=NULL;
	return node;
}

void addAtFront(int data){
	if(list==NULL){
		list=node;
		last=node;
		list->prev=NULL;
		last->next=NULL;
	}
	else{
		list->prev=node;
		node->next=list;
		list=node;
		list->prev=NULL;
	}
}

void addAtEnd(int data){
	if(list==NULL){
		list=node;
		last=node;
		list->prev=NULL;
		last->next=NULL;
	}
	else{
		last->next=node;
		node->prev=last;
		last=node;
		last->next=NULL;
	}
}

void deleteAtFront(){
	if(list==NULL){
		printf("Empty list");
	}
	else{
		temp=list;
		list=temp->next;
		list->prev=NULL;
		free(temp);
	}
}

void deleteAtEnd(){
	if(list==NULL){
		printf("Empty list");
	}
	else{
		temp=last;
		last=temp->prev;
		last->next=NULL;
		free(temp);
	}
}

void Search(int info){
	int flag=0,index=1;
	if(list==NULL){
		printf("Empty list");
	}
	else{
		temp=list;

		while(temp!=NULL){
			if(temp->data==info){
				flag=1;
				break;
			}
			temp=temp->next;
			index++;
		}
		if(flag==1){
			return index;
		}
		else{
			return 0;
		}
	}
	return index;
}

void SearchandDelete(int info){
	int flag=0,index=1;
	if(list==NULL){
		printf("Empty list");
	}
	else{
		temp=list;
		p=list;
		while(temp!=NULL){
			if(temp->data==info){
				flag=1;
				break;
			}
			p=temp;
			temp=temp->next;
			index++;
		}
		if(flag==1){
			q=temp->next;
			q->prev=p;
			p->next=q;
			free(temp);
			return index;
		}
		else{
			return 0;
		}
	}
	return index;
}

void addAtPosition(int data){
	int i,position;
	printf("Enter position: ");
	scanf("%d",&position);
	node=createNode(data);
	if(position==1){
		addAtFront(data);
	}
	else if (position==count+1){
		addAtEnd(data);
	}
	else{
		temp=list;
		p=list;
		for(i=1;i<position;i++){
			p=temp;
			temp=temp->next;
		}
		p->next=node;
		node->prev=p;
		node->next=temp;
		temp->prev=node;
	}
}

void displayf(){
	if(list==NULL){
		printf("\nList is Empty");
	}
	else{
		temp=list;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}

void displayb(){
	if(list==NULL){
		printf("\nList is Empty");
	}
	else{
		temp=last;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->prev;
		}
	}
}