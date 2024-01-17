//stack
#include<stdio.h>
#include<conio.h>
#define MAX 5
//push,pop,top,display------>functions
int tos=-1,stack[MAX];
void push(int data){
    if(tos==(MAX-1))
        printf("\nStack is full");
    else{
        tos++;
        stack[tos]=data;
        printf("\nAfter push stack is --->");
    }
}
void pop(){
    if(tos==-1)
        printf("\nStack is empty");
    else{
        printf("\nElement poped is %d",stack[tos]);
        tos--;
    }
}
void top(){
    if(tos==-1)
        printf("\nStack is empty");
    else{
        printf("\nData att top is %d",stack[tos]);
    }
}
void display(){
    int i;
    if(tos==-1)
        printf("\nStack is empty cannot display");
    else{
        for(i=tos;i>=0;i--){
            printf("\n\t\t\t%d",stack[i]);
            printf("\n\t\t\t________");
        }
    }
}
int main(){
    int data,choice;
    do{
        printf("\n**STACK OPERATIONS**");
        printf("\n1.PUSH\n2.POP\n3.TOP\n4.DISPLAY\n5.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter data to push: ");
                scanf("%d",&data);
                push(data);
                display();
                break;
        case 2: pop();
                display();
                break;
        case 3: top();
                display();
                break;
        case 4: display();
                break;
        case 5: printf("thankyou!");
                break;
        }
    }while (choice!=5);
    getch();
    return 0;
}