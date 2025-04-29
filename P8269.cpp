#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,v[N],a[N],rd[N],ans,minn=1e18+10;
bool vis[N];
queue <int> q;
void topo()
{
    for(int i=1;i<=n;i++)
    {
        if(!rd[i]) q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ans+=v[x];
        rd[a[x]]--;
        vis[x]=true;
        if(!rd[a[x]])q.push(a[x]);
    }
    return;
}
void dfs(int x)
{
    vis[x]=true;
    minn=min(minn,v[x]);
    if(vis[a[x]])return;
    dfs(a[x]);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>v[i];
        rd[a[i]]++;
    }
    topo();
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])ans+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        dfs(i);
        ans-=minn;
        minn=1e18+10;
    }
    cout<<ans;
}