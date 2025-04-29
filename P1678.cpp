#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10;
int m,n,sum;
int a[INF],b[INF];
void binary_search(int a[],int m,int x)
{
    int l=0,r=m+1,mid=0;
    while(l<r-1)
    {
        mid=(l+r)/2;
        if(a[mid]>x)
        {
            r=mid;
        }
        else{
            l=mid;
        }
    }
    sum+=min(abs(x-a[l]),abs(x-a[r]));
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a,a+m);
    for(int i=0;i<n;i++)
    {
        binary_search(a,m,b[i]);
    }
    cout<<sum;
}