#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
map <int,int> dp;
int n,a[MAXN],ans=0,temp=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
        if(dp[a[i]]>ans)
        {
            ans=dp[a[i]];
            temp=a[i];
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==temp-ans+1)
        {
            cout<<i<<" ";
            ans--;
        }
    }
}