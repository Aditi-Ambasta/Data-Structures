#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//stack using linked list

struct Node{
    int data;
    struct Node *next;
}; struct Node *node,*top=NULL,*temp=NULL;

struct Node* createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));

    node->data=info;
    node->next=NULL;
    return node;
}

//addatfront---->push
//deleteatfront---->pop
//peek
//display

void push(int data){
    node=createNode(data);
    if(top==NULL){
        top=node;
    }
    else{
        node->next=top;
        top=node;
    }
}

void pop(){
    temp=top;
    if(top==NULL){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nElement poped from stack: %d",temp->data);
        top=top->next;
        free(temp);
    }
}

void peek(){
    if(top==NULL){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nTop element of Stack: %d",top->data);
    }
}

void displayStack(){
    temp=top;
    if(top==NULL){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nDisplaying Stack: ");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void main(){
    int choice,data;
    do{
        printf("\n>>>>> STACK OPERATIONS <<<<<");
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY STACK\n5.EXIT");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter data to push in stack: ");
                    scanf("%d",&data);
                    push(data);
                    displayStack();
                    break;
            case 2: pop();
                    displayStack();
                    break;
            case 3: peek();
                    break;
            case 4: displayStack();
                    break;
            case 5: printf(">>> EXIT <<<");
                    exit(0);
                    break;
        }
    }while(choice!=5);

    getch();
}