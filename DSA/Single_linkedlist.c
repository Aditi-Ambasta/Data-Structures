#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int count=0;
struct Node
{
	int data;
	struct Node *next;
};
struct Node *node,*list=NULL,*last=NULL,*temp=NULL,*p=NULL;

struct Node* createNode(int info)
{
	struct Node *node=(struct Node*) malloc(sizeof(struct Node));

	node->data=info;
	node->next=NULL;
	return node;
}

void addAtFront(int data){
    node=createNode(data);
    if(list==NULL){
        list=node;
        last=node;
    }
    else{
        node->next=list;
        list=node;
    }
}
void addAtEnd(int data){
    node=createNode(data);
    if(list==NULL){
        list=node;
        last=node;
    }
    else{
        last->next=node;
        last=node;
    }
}
void display(){
    if(list==NULL){
        printf("\nList is Empty!");
    }
    else{
        temp=list;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void deleteAtBegin(){
    temp=list;
    if(list==NULL){
        printf("\nList is Empty!");
    }
    else{
        printf("\nNode deleted: %d\n",temp->data);
        list=list->next;
        free(temp);
    }
}
void deleteAtEnd(){
    if(list==NULL){
        printf("\nList is Empty!");
    }
    else if(list->next==NULL)
		list=NULL;
    else{
        temp=list;
        p=list;
        while(temp->next!=NULL){
            p=temp;
            temp=temp->next;
        }
        free(temp);
        p->next=NULL;
        last=p;
    }
}
void insertAtposition(int data){
    int pos,i;
    node=createNode(data);
    printf("Enter position to insert Node: ");
    scanf("%d",&pos);
    temp=list;
    p=list;
    if(pos==1){
        addAtFront(data);
    }
    else if(pos==count+1){
        addAtEnd(data);
    }
    else{
        for(i=1;i<pos;i++){
            p=temp;
            temp=temp->next;
        }
        p->next=node;
        node->next=temp;
    }
}
int searchNode(int data){
    int flag=0,index=1;
    if(list==NULL){
        printf("\nList is Empty!");
    }
    else{
        temp=list;
        while (temp!=NULL){
            if(temp->data==data){
                flag=1;
                break;
            }
            temp=temp->next;
            index++;
        }
    }
    if(flag==1){
        return index;
    }
    else
        return 0;
}
int searchAndDelet(int data){
    int flag=0,index=1;
    if(list==NULL){
        printf("\nList is Empty!");
    }
    else{
        temp=list;
        p=list;
        while (temp!=NULL){
            if(temp->data==data){
                flag=1;
                break;
            }
            p=temp;
            temp=temp->next;
            index++;
        }
    }
    if(flag==1){
        p->next=temp->next;
        free(temp);
        return index;
    }
    else
        return 0;
}

void main()
{

	int data,choice,location;
	//clrscr();
    do
    {

	printf ("\n---LINKED LIST---\n1.Add at Front\n2.Add at End\n3.Delete At Begin\n4.Delete At End\n5.Insert At Position\n6.Search\n7.Search And Delete\n8.Display\n9.Exit");
	printf("\n Enter Your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\n Enter Data to add at Front: ");
				scanf("%d",&data);
				addAtFront(data);
				count++;
				display();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 2: printf("\n Enter Data to add at End: ");
				scanf("%d",&data);
				addAtEnd(data);
				count++;
				display();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 3: deleteAtBegin();
				count--;
				display();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 4: deleteAtEnd();
				count--;
				display();
				printf("\n Total Nodes in the list=%d",count);
				break;

		case 5: printf("\n Enter Data to add in Node: ");
				scanf("%d",&data);
				insertAtposition(data);
				count++;
				display();
				printf("\n Total Nodes in the list=%d",count);
				break;

		case 6: printf("\n Enter Data to Search in List: ");
				scanf("%d",&data);
				location=searchNode(data);
				display();
				printf("\n Total Nodes in the list=%d",count);
				if(location!=0)
					printf("\n %d Element found at Location=%d",data,location);
				else
					printf("\n Element Not Found");
				break;

		case 7: printf("\n Enter Data to Search and delet from List: ");
				scanf("%d",&data);
				location=searchAndDelet(data);
                count--;
				display();
				printf("\n Total Nodes in the list=%d",count);
				if(location!=0)
					printf("\n %d Element found at Location=%d and Deleted successfully",data,location);
				else
					printf("\n Element Not Found");
				break;

		case 8: display();
			break;

        case 9: printf("\nExiting.....");
            break;
		}

	}while(choice!=9);

	getch();

}