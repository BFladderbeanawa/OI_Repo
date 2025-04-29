#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,p[N],s[N];
int dp[N],q[N],ans;
vector <int> g[N];
void dfs(int x,int y)
{
    if(s[x]==1&&x!=1)
    {
        dp[x]=1;
    }
    for(int i:g[x])
    {
        if(i!=y)
        {
            dfs(i,x);
            dp[x]+=dp[i];
        }
    }
    ans+=min(dp[x],q[x]);
    dp[x]-=min(dp[x],q[x]);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        s[x]++;
        s[y]++;
    }
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==1)
        {
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        q[p[i]]++;
    }
    dfs(1,0);
    cout<<ans;
}