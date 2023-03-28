#include<bits/stdc++.h>
using namespace std;
int cnt;

void merge(vector<int> &v, int s, int mid, int e)
{
    vector<int> temp;
    
    int cnt1 = 0;
    int i = s, j = mid+1;
    while(i<=mid and j<=e)
    {
        if(v[i]<=v[j]) {temp.push_back(v[i]); i++;}
        else { cnt += (mid-i)+1; temp.push_back(v[j]); j++;} //+1 because we have to include mid element as well 
    }
    
    while(i<=mid) {temp.push_back(v[i]); i++;}
    while(j<=e) {temp.push_back(v[j]); j++;}
    
    for(int i=s;i<=e;i++)
    {
        v[i] = temp[i-s];
    }
    
}

void merge_sort(vector<int> &v, int s, int e)
{
    if(s>=e) return;
    
    int mid = (s+e)/2;
    
    merge_sort(v, s, mid);
    merge_sort(v, mid+1, e);
    
    merge(v, s, mid, e);
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    merge_sort(v, 0, n-1);
    
    cout<<"count "<< cnt<<endl;
    for(auto &x:v) cout<<x<<" ";
    
    return 0;
}
