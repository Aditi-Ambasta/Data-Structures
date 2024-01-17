#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; 
};

struct node *createList(struct node *);
struct node *addAtBegin(struct node *,int data);
struct node *addAtEnd(struct node *,int data);
void concate();
void split();
void copy();
void display(struct node *);
void delete(struct node *);

struct node *createList(struct node *start)
{
int i,n,data;
start=NULL;
printf("Enter the number of nodes:");
scanf("%d",&n);
if(n==0)
{
	return start;
}
printf("Enter the data into nodes:");
scanf("%d",&data);
start=addAtBegin(start,data);
for(i=2;i<=n;i++)
{
//printf("Enter the data into nodes:");
scanf("%d",&data);
start=addAtEnd(start,data);
}
return start;
}

void display(struct node *start)
{
struct node *temp;
if(start==NULL)
{
	printf("List is empty");
	return;
}
temp=start;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}}


struct node *addAtEnd(struct node *start,int data)
{
struct node *temp,*p;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
p=start;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
temp->next=NULL;
return start;
}

struct node *addAtBegin(struct node *start,int data)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=start;
start=temp;
return temp;
}

void split()
{
struct node* start=NULL,*start1,*start2,*temp;
int value;
printf("Enter the list you want to split:\n");
start=createList(start);
printf("List is:");
display(start);
printf("\nEnter the element from where you want to split:");
scanf("%d",&value);

start1=start;
temp=start;
while(temp!=NULL)
{
if(temp->data==value)
{
	start2=temp->next;
	temp->next=NULL;
	break;
}
if(temp->next==NULL)
{
	printf("Please enter valid Splitting element again");
	 return;
}
temp=temp->next;
}

printf("\nGiven list splitted into two lists:\n");
printf("List 1:");
display(start1);
printf("\nList 2:");
display(start2);
}


void concate()
{
struct node *start1=NULL,*start2=NULL,*temp;
printf("Create List 1:\n");
start1=createList(start1);
printf("Create List 2:\n");
start2=createList(start2);
printf("\nFirst list:");
display(start1);
printf("\nSecond list:");
display(start2);

printf("\n\nConcatenated List is:\n");
if(start1==NULL)
{
	start1=start2;
	display(start1);
	return;
}
if(start2==NULL)
{
	display(start1);
	return;
}
temp=start1;
while(temp->next!=NULL)
{
	temp=temp->next;
}
temp->next=start2;
display(start1);
}

void delete(struct node *start)
{
struct node *temp;
while(start!=NULL)
{
temp=start;
start=start->next;
free(temp);
}
 }



void copy()
{
struct node *start1,*start2,*temp1,*temp2,*p;
int value;
printf("Create List 1:\n");
start1=createList(start1);
printf("Create List 2:\n");
start2=createList(start2);
printf("\nFirst list:");
display(start1);
printf("\nSecond list:");
display(start2);
printf("\nEnter the list value (1/2) of which you want elements to be copied:");
scanf("%d",&value);

if(value==1)
{
	temp1=start1;
	temp2=start2;
	while(temp1!=NULL)
	{
	p=temp2;

	if(temp2==NULL)
	{
		addAtEnd(start2,temp1->data);
	}
	else
	{
		temp2->data=temp1->data;
	}
	temp2=temp2->next;
	temp1=temp1->next;
	}

	if(p->next!=NULL)
	{
		delete(temp2);
		p->next=NULL;
	}
	printf("List after Copying the Elements:\n");
	printf("List 1:");
	display(start1);
	printf("\nList 2:");
	display(start2);
}
else if(value==2)
{
	temp1=start2;
	temp2=start1;
	while(temp1!=NULL)
	{
	p=temp2;
	if(temp2==NULL)
	{
		addAtEnd(start1,temp1->data);
	}
	else
	{
		temp2->data=temp1->data;
	}
	temp2=temp2->next;
	temp1=temp1->next;
	}
	if(p->next!=NULL)
	{
		delete(temp2);
		p->next=NULL;
	}
	printf("List after Copying the Elements:\n");
	printf("List 1:");
	display(start1);
	printf("\nList 2:");
	display(start2);
}

else
{
printf("Please enter valid list value");
}
}


void main()
{
int ch;
do{
printf("\n****Linked List Operations****\n");
printf("1. Concatenate\n2. Split\n3. Copy\n4. Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: concate();
	break;
case 2: split();
	break;
case 3: copy();
	break;
case 4: exit(0);
	break;
default: printf("Please enter valid choice");
}
}while(ch!=4);
getch();
}

// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>

// struct Node{
// 	int data;
// 	struct Node* next;
// };

// struct Node* addatbegin(struct Node* start,int data){
// 	start=NULL;
// 	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
// 	node->data=data;
// 	node->next=start;
// 	start=node;
// 	return node;
// }

// struct Node* addatend(struct Node* start,int data){
// 	struct Node* temp ,*node;
// 	node=(struct Node*)malloc(sizeof(struct Node));
// 	node->data=data;
// 	temp=start;
// 	while(temp->next!=NULL){
// 		temp=temp->next;
// 	}
// 	temp->next=node;
// 	node->next=NULL;
// 	return start;
// }

// void display(struct Node* start){
// 	struct Node* temp;
// 	if(start==NULL){
// 		printf("List is Empty");
// 	}
// 	else{
// 		temp=start;
// 		while(temp!=NULL){
// 			printf("%d\t",temp->data);
// 			temp=temp->next;
// 		}
// 	}
// }

// struct Node* createList(struct Node* start){
// 	int n,i,data;
// 	start=NULL;
// 	printf("\nEnter number of nodes in List: ");
// 	scanf("%d",&n);
// 	if(n==0){
// 		return start;
// 	}
// 	printf("\nEnter 1 element: ");
// 	scanf("%d",&data);
// 	start=addatbegin(start,data);
// 	for(i=2;i<=n;i++){
// 		printf("Enter %d element: ",i);
// 		scanf("%d",&data);
// 		start=addatend(start,data);
// 	}
// 	return start;
// }

// void split(){
// 	struct Node* start, *start1, *start2;
// 	int element;
// 	printf("\nEnter List you want to split: ");
// 	start=createList(start);
// 	printf("\nEnter element after which you want to split: ");
// 	scanf("%d",&element);
// 	start1=start;
// 	while(start!=NULL){
// 		if(start->data==element){
// 			start2=start->next;
// 			start->next=NULL;
// 		}
// 		if(start->next==NULL){
// 			printf("Please enter valid splitting element!");
// 			break;
// 		}
// 		start=start->next;
// 	}
// 	printf("\nList 1: ");
// 	display(start1);
// 	printf("\nList 2: ");
// 	display(start2);
// }

// void concate(){
// 	struct Node* start1, *start2, *temp;
// 	printf("\nEnter List 1: ");
// 	start1=createList(start1);
// 	printf("\nEnter List 2: ");
// 	start2=createList(start2);
// 	printf("\nList 1: ");
// 	display(start1);
// 	printf("\nList 2: ");
// 	display(start2);

// 	if(start1==NULL){
// 		display(start2);
// 	}
// 	else if(start2==NULL){
// 		display(start1);
// 	}
// 	else{
// 		temp=start1;
// 		while(temp->next!=NULL){
// 			temp=temp->next;
// 		}
// 		temp->next=start2;
// 		printf("\nConcatenated List: ");
// 		display(start1);
// 	}
// }

// void copy() {
//     struct Node *start1, *start2, *temp1, *temp2;
//     int choice;

//     printf("\nEnter List 1: ");
//     start1 = createList(start1);
//     printf("\nEnter List 2: ");
//     start2 = createList(start2);

//     printf("\nList 1: ");
//     display(start1);
//     printf("\nList 2: ");
//     display(start2);

//     printf("\nEnter (1/2) list to copy: ");
//     scanf("%d", &choice);

//     if (choice == 1) {
//         temp1 = start1;
//         temp2 = start2;

//         while (temp1 != NULL && temp2 != NULL) {
//             temp2->data = temp1->data;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }

//         // If List 2 is longer than List 1, delete extra nodes from List 2
//         while (temp2 != NULL) {
//             struct Node* temp = temp2;
//             temp2 = temp2->next;
//             free(temp);
//         }

// 		// If List 2 is shorter than List 1, add extra nodes to List 2
// 		while (temp1 != NULL) {
//             struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//             newNode->data = temp1->data;
//             newNode->next = NULL;

//             temp2->next = newNode;
//             temp2 = temp2->next;
//             temp1 = temp1->next;
//         }

//     } else if (choice == 2) {
//         temp1 = start1;
//         temp2 = start2;

//         while (temp1 != NULL && temp2 != NULL) {
//             temp1->data = temp2->data;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
// 		// shows error again but nevermind now
//         // If List 1 is longer than List 2, delete extra nodes from List 1
//         while (temp1 != NULL) {
//             struct Node* temp = temp1;
//             temp1 = temp1->next;
//             free(temp);
//         }

// 		// If List 1 is shorter than List 2, add extra nodes to List 1
//         while (temp2 != NULL) {
//             struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//             newNode->data = temp2->data;
//             newNode->next = NULL;

//             temp1->next = newNode;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
//     }

//     printf("\nLists after copying: ");
//     printf("\nList 1: ");
//     display(start1);
//     printf("\nList 2: ");
//     display(start2);
// }

// void main()
// {
// 	int ch;
// 	do{
// 		printf("\n****Linked List Operations****\n");
// 		printf("\n1. Concatenate\n2. Split\n3. Copy\n4. Exit");
// 		printf("\nEnter your choice: ");
// 		scanf("%d",&ch);
// 		switch(ch)
// 		{
// 			case 1: concate();
// 				break;
// 			case 2: split();
// 				break;
// 			case 3: copy();
// 				break;
// 			case 4: exit(0);
// 				break;
// 			default: printf("Please enter valid choice");
// 		}
// 	}while(ch!=4);
// 	getch();
// }