#include<bits/stdc++.h>
using namespace std;
int N,Q;
vector<pair<int,int>> g[5010];
bool vis[5010];
int ans=0;
void dfs(int x,int v)
{
    if(vis[x])
    {
        return;
    }
    vis[x]=true;
    ans++;
    for(auto i:g[x])
    {
        if(i.second>=v)
        {
            dfs(i.first,v);
        }
    }
}
int main()
{
    cin>>N>>Q;
    for(int i=0;i<N-1;i++)
    {
        int p,q,r;
        cin>>p>>q>>r;
        g[p].push_back({q,r});
        g[q].push_back({p,r});
    }
    for(int i=0;i<Q;i++)
    {
        int k,v;
        ans=0;
        memset(vis,0,sizeof(vis));
        cin>>k>>v;
        dfs(v,k);
        cout<<ans-1<<endl;
    }
}
