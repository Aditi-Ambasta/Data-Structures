#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
int count=0;

struct node* insert(struct node* r,int data){
    if(r==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->data=data;
        r->left=NULL;
        r->right=NULL;
    }
    else if(data<r->data){
        r->left=insert(r->left,data);
    }
    else if(data>r->data){
        r->right=insert(r->right,data);
    }
    return r;
}

struct node* findmin(struct node* r){
    if(r==NULL){
        return 0;
    }
    else{
        while(r->left!=NULL){
            r=r->left;
        }
        return r;
    }
}

struct node* delete(struct node* r,int data){
    struct node* temp;
    if(r==NULL){
        printf("List Empty, cannot perform delete operation");
        return 0;
    }
    else if(data<r->data){
        r->left=delete(r->left,data);
    }
    else if(data>r->data){
        r->right=delete(r->right,data);
    }
    else if(r->left!=NULL && r->right!=NULL){
        temp=findmin(r->right);
        r->data=temp->data;
        r->right=delete(r->right,r->data);
    }
    else{
        temp=r;
        if(r->left==NULL){
            r=r->right;
        }
        else if(r->right==NULL){
            r=r->left;
        }
        free(temp);
    }
    return r;
}

int countnodes(){
    printf("%d",count);
}

int height(struct node* r){
    int hleft,hright;
    if(r==NULL){
        return 0;
    }
    hleft=height(r->left);
    hright=height(r->right);
    if(hleft>hright){
        return(1+hleft);
    }
    return(1+hright);
}

void inOrder(struct node* r){
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ",r->data);
        inOrder(r->right);
    }
}

void preOrder(struct node* r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r){
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ",r->data);
    }
}

void search(struct node* r, int data){
    if(r==NULL){
        printf("List Empty, cannot perform search operation");
    }
    else if(r->data==data){
        printf("Element found");
    }
    else if(data<r->data){
        search(r->left,data);
    }
    else if(data>r->data){
        search(r->right,data);
    }
}

void mirrorTree(struct node* r){
    struct node* temp;
    if(r!=NULL){
        mirrorTree(r->left);
        mirrorTree(r->right);
        temp=r->left;
        r->left=r->right;
        r->right=temp;
    }
}

void main(){
    int ch,data;
    do{
        printf("\n*****BINARY SEARCH TREE OPERATIONS*****\n");
        printf("\n1. Insert Node\n2. Delete Node\n3. PreOrder Traversal\n4. Inorder Traversal\n");
        printf("5. PostOrder Traversal\n6. Search\n7. Count Nodes\n8. Find Height\n9. Mirror Image\n10.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:	printf("Enter the data you want to Insert:");
                scanf("%d",&data);
                root=insert(root,data);
                printf("Element in the BST:\n");
                preOrder(root);
                count++;
                break;
            case 2:	printf("Enter the data you want to Delete:");
                scanf("%d",&data);
                delete(root,data);
                printf("Element in the BST:\n");
                preOrder(root);
                count--;
                break;
            case 3: printf("PreOrder Traversal:\n");
                preOrder(root);
                break;
            case 4: printf("InOrder Traversal: \n");
                inOrder(root);
                break;
            case 5:	printf("PostOrder Traversal: \n");
                postOrder(root);
                break;
            case 6:	printf("Enter the element you want to search:");
                scanf("%d",&data);
                search(root,data);
                break;
            case 7:	countnodes();
                break;
            case 8:	printf("Height of the Tree is: %d",height(root));
                break;
            case 9:	printf("Mirror Image of Binary Tree is:");
                mirrorTree(root);
                inOrder(root);
                break;
            case 10: exit(0);
            default: printf("Please enter valid choice again");
        }
    }while(ch!=10);
    getch();
}