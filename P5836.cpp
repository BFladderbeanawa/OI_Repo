#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int> G[10005];
string s;
bool vis[100005],flag=false;
void dfs(int start,int f,char c)
{
    if(vis[start])
    {
        return;
    }
    vis[start]=true;
    if(s[start]==c)
    {
        flag=true;
    }
    for(int i:G[start])
    {
        dfs(i,f,c);
    }
}
int main()
{
    cin>>N>>M;
    cin>>s;
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<M;i++)
    {
        flag=false;
        memset(vis,false,sizeof(vis));
        int a,b;
        char c;
        cin>>a>>b>>c;
        dfs(a,b,c);
        cout<<flag;
    }
}