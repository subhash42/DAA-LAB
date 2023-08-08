#include <stdio.h>

using namespace std;

struct Job
{
 int id;
 int dead;
 int profit;
 };

 bool compare(Job a,Job b)
 {
  return a.profit>b.profit;
  vector<int>JobScheduling(Job arr [],int n)
   sort(arr,arr+n,compare);
   int maxline=0,j=0;
   for (int i=0,i<n,i++)
   {
    if(arr[i].dead>maxline)
    {
    maxline=arr[i].dead;
    }
    }
    int i=0;
    int a[maxline];
    memset(a,-1,sizeof(a));
    while(j!=maxline&&i<n)
    if(a[arr[i].dead-1]==-1)
    {
    a[arr[i].id;
    j++;
    }
    else{
    FOR(int k=arr[i].dead-1;k>=0;k--)
    {
    if(a[k]==-1)
    {
    a[k]=arr[i].id;
    j++;
    break;
    }
    }
    }
    i++;
    }
    vector<int>schedule;
    for(i=0;i<maxline;i++)
    {
    if(a[i]==-1)
    {
    continue;
    }
    else{
    schedule.push_back(a[i]);
    }
    }
    return schedule;
    }
    int main()
    {
    job arr[]={{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}};
    vector<int>schedule=JobScheduling(arr,5);
    cout<<"order of scheduled jobs for maximum profit:";
    for(int i=0,i<schedule.size();i++)
    {
    cout<<schedule[i]<<"";
    }
    }                    }



















