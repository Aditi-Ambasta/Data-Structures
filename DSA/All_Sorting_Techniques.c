#include<stdio.h>
#include<conio.h>
#define MAX 100

//Bubble Sort

void main(){
    int i,j,n,a[100],temp;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter %d element in array: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nBubble Sorted Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
/*
//Insertion sort

void main(){
    int i,j,n,a[100],temp;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter %d element in array: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("\nInsetion Sort Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

//Selection sort

void main(){
    int i,j,n,a[100],min,temp;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter %d element in array: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j; 
            }
            if (min ==j){
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
    }
    printf("\nSelection Sort Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}*/

//Merge Sort

// #include<stdio.h>
// #include<conio.h>
// #define MAX 100

// void mergelist(int a[], int lb, int mid, int ub){
    
//     int i=lb, j=mid+1, k=lb, b[MAX];
//     while(i<=mid && j<=ub){
//         if(a[i]<=a[j]){
//             b[k]=a[i];
//             i++;
//         }
//         else{
//             b[k]=a[j];
//             j++;
//         }
//         k++;
//     }
//     if(i>mid){
//         while(j<=ub){
//             b[k]=a[j];
//             j++;
//             k++;
//         }
//     }
//     else{
//         while(i<=mid){
//             b[k]=a[i];
//             i++;
//             k++;
//         }
//     }
//     for(i=lb;i<=ub;i++){
//         a[i]=b[i];
//     }
// }

// void mergeSort(int a[], int lb, int ub){

//     int mid;
//     if(lb<ub){
//         mid = (lb+ub)/2;
//         mergeSort(a,lb,mid);
//         mergeSort(a,mid+1,ub);
//         mergelist(a,lb,mid,ub);
//     }

// }

// void main(){
//     int n,i,a[MAX],lb,ub;
//     lb=0;
//     printf("\nEnter mumber of elements in Array to Sort: ");
//     scanf("%d",&n);
//     ub=n-1;
//     printf("\nEnter elements in Array to Sort-");
//     for(i=0;i<n;i++){
//         printf("\nEnter %d element: ",i+1);
//         scanf("%d",&a[i]);
//     }
//     printf("\nOriginal Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
//     mergeSort(a,lb,ub);
//     printf("\nSorted Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
// }

//Quick Sort

// int partition(int a[], int lb, int ub){
//     int pivot, s, e, temp;
//     pivot=a[lb];
//     s=lb;
//     e=ub;
//     while(s<e){
//         while(a[s]<=pivot)
//             s++;
//         while(a[e]>pivot)
//             e--;
//         if(s<e){
//             //swap start and end elements
//             temp = a[s];
//             a[s] = a[e];
//             a[e] = temp;
//         }
//     }
//     //swap lb/pivot and a[e]
//     temp = a[lb];
//     a[lb] = a[e];
//     a[e] = temp;
//     return e;
// }

// void quickSort(int a[], int lb, int ub){
//     int loc;
//     if(lb<ub){
//         loc = partition(a, lb, ub);
//         quickSort(a, lb, loc-1);
//         quickSort(a, loc+1, ub);
//     }
// }

// void main(){
//     int n,i,a[MAX],lb,ub;
//     lb=0;
//     printf("\nEnter mumber of elements in Array to Sort: ");
//     scanf("%d",&n);
//     ub=n-1;
//     printf("\nEnter elements in Array to Sort-");
//     for(i=0;i<n;i++){
//         printf("\nEnter %d element: ",i+1);
//         scanf("%d",&a[i]);
//     }
//     printf("\nOriginal Array: ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
//     quickSort(a,lb,ub);
//     printf("\nSorted Array (using Quick Sort): ");
//     for(i=0;i<n;i++){
//         printf("%d\t",a[i]);
//     }
// }
