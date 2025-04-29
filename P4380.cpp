#include<bits/stdc++.h>
using namespace std;
int g[255][255];
int N;
bool vis[255][255];
int start;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int cnt=0,ans1,ans2;
void dfs1(int x,int y)
{
    if(vis[x][y]||x<0||x>N||y<0||y>N||g[x][y]!=start)
    {
        return;
    }
    vis[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        dfs1(xx,yy);
    }
}
void dfs2(int x,int y,int start1,int start2)
{
    if(vis[x][y]||x<0||x>N||y<0||y>N)
    {
        return;
    }
    if(g[x][y]!=start1&&g[x][y]!=start2)
    {
        return;
    }
    vis[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        dfs2(xx,yy,start1,start2);
    }
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>g[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!vis[i][j])
            {
                dfs1(i,j);
                start=g[i][j];
                ans1=max(ans1,cnt);
                cnt=0;
            }
        }
    }
    cout<<ans1<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(!vis[i][j]&&i+dx[k]>=0&&i+dx[k]<N&&j+dy[k]>=0&&j+dy[k]<N&&g[i][j]!=g[i+dx[k]][j+dy[k]])
                {
                    cnt=0;
                    memset(vis,false,sizeof(vis));
                    dfs2(i,j,g[i][j],g[i+dx[k]][j+dy[k]]);
                    ans2=max(cnt,ans2);
                }
            }
        }
    }
    cout<<ans2;
}