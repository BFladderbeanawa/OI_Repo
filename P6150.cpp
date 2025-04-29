#include<bits/stdc++.h>
using namespace std;
int N,clocks[2505],cocks[2505];
vector<int> g[2505];
void clock_add(int x){clocks[x]=(clocks[x]+1)%12;}
void dfs(int x,int father)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]!=father)
        {
            dfs(g[x][i],x);
            clocks[x]=(clocks[x]+12-clocks[g[x][i]])%12;
        }
    }
}
int main()
{
    int ans=0;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>cocks[i];
    }
    for(int i=1;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
		memcpy(clocks,cocks,sizeof(clocks));
        dfs(i,0);
        if(clocks[i]==1||clocks[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
}