#include <stdio.h>
int recbin(int arr[], int s_index, int e_index, int element){
   if (e_index >= s_index){
      int mid= s_index + (e_index - s_index )/2;
      if (arr[mid] == element)
         return mid;
      if (arr[mid] > element)
         return recbin(arr, s_index, mid-1, element);
      return recbin(arr, mid+1, e_index, element);
   }
   return -1;
}
int main(void){
   int arr[20],n;
   printf("Enter no of elements in array: ");
   scanf("%d",&n);
   printf("Enter elements: ");
   for(int i=0; i<n; i++)
   {
       scanf("%d",&arr[i]);
   }
   int element;
   printf("Enter the element to be searched: ");
   scanf("%d",&element);
   int found_index = recbin(arr, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}
