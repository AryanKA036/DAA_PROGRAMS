#include <stdio.h>
void merge(int arr[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=arr[left+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[100],arr_size;
    printf("Enter the number of elements: ");
    scanf("%d",&arr_size);
    printf("Enter the elements:\n");
    for(int i=0;i<arr_size;i++)
        scanf("%d",&arr[i]);
    printf("Given array: ");
    printArray(arr,arr_size);
    mergeSort(arr,0,arr_size-1);
    printf("Sorted array: ");
    printArray(arr,arr_size);
    return 0;
}

/*  OUTPUT 
Enter the size of array: 7
Enter the elements: 22
5
33
75
70
69
85
Sorted array: 5 22 33 69 70 75 85*/ 
