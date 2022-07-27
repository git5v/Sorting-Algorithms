// Best and worst case time complexity is O(nlogn)
// Space complexity is O(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int s, int e,int mid)
{
 int i=s,j=mid+1,k=s;
 
 int temp[s+e+1];
 
 while(i<=mid and j<=e)
 {
     
     if(a[i]<a[j]) temp[k++]=a[i++];
     else temp[k++] = a[j++];
     
 }
 
 while(i<=mid) temp[k++]=a[i++];
 while(j<=e) temp[k++]=a[j++];
 
 for(int i=s;i<=e;i++)
 {
     a[i]=temp[i];
 }
 
}

void mergresort(int a[],int s, int e)
{
    if(s==e) return;
    
    int mid = (s+e)>>1;
    mergresort(a,s,mid);
    mergresort(a,mid+1,e);
    
    merge(a,s,e,mid);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"Before sort\n";
    for(int i=0;i<n;i++)
     {
         cout<<a[i]<<" ";
     }   
     
    mergresort(a,0,n-1);
    
    cout<<"\nAfter sort\n";
    for(int i=0;i<n;i++)
     {
         cout<<a[i]<<" ";
     }
    
   return 0;
}
