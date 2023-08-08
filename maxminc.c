#include<stdio.h>


int findmax(int arr[], int low, int high)
{
    if(low==high){
        return (arr[low]);
    }

    else{
        int mid=(low+high)/2;
        int max1= findmax(arr,low,mid);
        int max2= findmax(arr,mid+1,high);
        return ( max1> max2 ) ? max1:max2 ;
    }
}

int findmin(int arr[],int low, int high)
{
    if(low==high)
    {
        return (arr[low]);
    }
    else
    {
        int mid=(low+high)/2;
        int min1= findmin(arr,low,mid);
        int min2= findmin(arr,mid+1,high);
        return (min1<min2)? min1: min2;
    }
}
int main()
{
    int  n,arr[20],low,high,mid;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Maximm number in the array: %d\n",findmax(arr,0,n-1));


    printf("Minimum in the array: %d",findmin(arr,0, n-1));


    return 0;
}
