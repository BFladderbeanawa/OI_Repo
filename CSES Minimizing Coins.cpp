#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,x,c[105],dp[N];
signed main()
{
    for(int i=0;i<=N;i++)
    {
        dp[i]=(int)(1e9+10);
    }
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        dp[c[i]]=1;
    }
    for(int i=1;i<=x;i++)
    {
        // if(dp[i]==1)
        // {
        //     continue;
        // }
        //else{
            for(int j=1;j<=n;j++)
            {
                if(c[j]<i) dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        //}
    }
    if(dp[x]==(int)(1e9+10))
    {
        cout<<-1;
    }
    else{
        cout<<dp[x];
    }
}