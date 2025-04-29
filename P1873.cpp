#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e6+10;
int n,m,maxn;
int a[INF];

signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    // cout<<maxn;
    int l=0,r=maxn,mid=0;
    while(l<r-1){
        mid=(l+r)/2;
        // bool flag=false;
        int sum=0;
        for(int i=0;i<n;i++){
            if(a[i]-mid>0)
            {
                sum+=a[i]-mid;
            }
        }
        // cout<<sum<<" ";
        if(sum>=m){
            l=mid;
        }
        else if(sum<m){
            r=mid;
        }
    }
    cout<<l;
    return 0;
}