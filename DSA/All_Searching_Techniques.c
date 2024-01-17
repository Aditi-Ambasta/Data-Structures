// #include<stdio.h>
// #include<conio.h>

//Linear search

// void main(){
//     int i,j,n,a[100],element,flag=0;
//     printf("\nEnter number of elements in array: ");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         printf("\nEnter %d element in array: ",i+1);
//         scanf("%d",&a[i]);
//     }
//     printf("Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
//     printf("\nEnter element to search: ");
//     scanf("%d",&element);
//     for(i=0;i<n;i++){
//         if(a[i]==element){
//             flag=1;
//             break;
//         }
//     }
//     if(flag==1){
//         printf("\nElement present at position %d",i+1);
//     }
//     else{
//         printf("\nElement not present");
//     }
// }


//Binary Search 

// #include<stdio.h>
// #include<conio.h>

// void main(){
//     int i,j,n,a[100],element,m;
//     int flag=0;
//     printf("\nEnter number of elements in array: ");
//     scanf("%d",&n);
//     printf("\nEnter sorted array: ");
//     for(i=0;i<n;i++){
//         printf("\nEnter %d element in array: ",i+1);
//         scanf("%d",&a[i]);
//     }
//     printf("Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
//     printf("\nEnter element to search: ");
//     scanf("%d",&element);
//     int f=0;
//     int l=n-1;
//     while(f<=l){
//         m=(f+l)/2;
//         if(a[m]==element){
//             flag=1;
//             break;
//         }
//         else if(a[m]>element){
//             l=m-1;
//         }
//         else if(a[m]<element){
//             f=m+1;
//         }
//     }
//     if (flag==1){
//         printf("\nElement present at position %d",m+1);
//     }
//     else{
//         printf("\nElement not present");
//     }
// }


//Binary Search using Recurssion
// #include<stdio.h>
// #include<conio.h>

// int binarySearch(int f, int l, int n, int a[100], int data){
//     int m;
//     m=(f+l)/2;
//     if(f>l)
//         return -1;
//     else if(a[m]==data)
//         return m;
//     else if(a[m]<data)
//         return binarySearch(m+1, l, n, a, data);
//     else if(a[m]>data)
//         return binarySearch(f, m-1, n, a, data);
// }

// void main(){
//     int i,n,a[100],data;
//     printf("\nEnter number of elements in array: ");
//     scanf("%d",&n);
//     printf("\nEnter sorted array: ");
//     for(i=0;i<n;i++){
//         printf("\nEnter %d element in array: ",i+1);
//         scanf("%d",&a[i]);
//     }
//     printf("Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
//     printf("\nEnter element to search: ");
//     scanf("%d",&data);
//     int r=binarySearch(0, n-1, n, a, data);
//     if(r==-1){
//         printf("\nElement not found");
//     }
//     else{
//         printf("Element found at %d position",r+1);
//     }
// }


//fibonacci search
#include<stdio.h>
#include<conio.h>

int minimum(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

void main(){
    int i,n,a[100],x;
    printf("\nEnter number of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter sorted array: ");
    for(i=0;i<n;i++){
        printf("\nEnter %d element in array: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d",&x);

    int offset=-1;
    int fm2=0;
    int fm1=1;
    int fm=fm2+fm1;
    while(fm<n){
        fm2=fm1;
        fm1=fm;
        fm=fm2+fm1;
    }
    while(fm>1){
        i=minimum(offset+fm2,n-1);
        if(a[i]<x){
            fm=fm1;
            fm1=fm2;
            fm2=fm-fm1;
            offset=i;
        }
        else if(a[i]>x){
            fm=fm2;
            fm1=fm1-fm2;
            fm2=fm-fm1;
        }
        else{
            printf("\n");
            break;
        }
    }
    if(fm1 && a[offset+1]==x){
        printf("Element found at %d position",(offset+1)+1);
    }
    else{
        printf("Invalid!");
    }
}
