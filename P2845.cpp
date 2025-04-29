#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x[10001],y[10001],top;
}node[105][105];
int N,M,ans,ans1;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool vis[101][101]={0};
bool mark[101][101]={0};
int x,y,a,b;
void dfs(int x, int y)
{
    for(int i=1;i<=node[x][y].top;i++)
    {
        mark[node[x][y].x[i]][node[x][y].y[i]]=true;
    }
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=N&&yy>=1&&yy<=N&&mark[xx][yy]&&!vis[xx][yy])
        {
            vis[xx][yy]=true;
            dfs(xx,yy);
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>x>>y>>a>>b;
        node[x][y].x[++node[x][y].top]=a,node[x][y].y[node[x][y].top]=b;
    }
    mark[1][1]=true;
    vis[1][1]=true;
    dfs(1,1);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(mark[i][j])
            {
                ans++;
            }
        }
    }
    //cout<<ans;
    while(ans!=ans1)
    {
        ans1=ans;
        memset(vis,0,sizeof(vis));
        dfs(1,1);
        ans=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(mark[i][j])
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}