#include <stdio.h>
#include<string.h>
struct patient{
  char name[20];
  int age;
  char disease[20];
  }p[10];
void swap (int*a, int*b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}
void heapify(char arr[],int n, int i){
int largest =i;
int left =2*i+1;
int right =2*i+2;
if (left < n && strcmp(arr[left].name>arr[largest].name)>0)
    largest=left;
if (right < n && arr[right]>arr[largest])
    largest=right;
if(largest !=i){
    swap(&arr[i],&arr[largest]);
    heapify(arr,n,largest);
}
}
void heapSort(char arr[],int n ){
for (int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int arr[],int n){
for(int i=0;i<n;i++)
    printf("%d",arr[i]);
    printf("\n");
}
int main()
{
int arr[50],x,i;
printf("Enter the number of patient:\n");
scanf("%d",&x);
printf("Enter the patient details:\n");
for(int i=0;i<x;i++)
{
 scanf("%c",&p[i].name);
 scanf("%c",&p[i].age);
 scanf("%c",&p[i].disease);
}
int n=x;
heapSort(arr,n);
printf("Sorted arrays are \n");
printArray(arr,n);
}

