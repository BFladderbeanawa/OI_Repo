#include<bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
const char s[] = {'N', 'S', 'W', 'E'};
bool vis[2005][2005];
int x=1000,y=1000,a[2005][2005];
int n,num=1,xt=0,yt=0,ans=0,f[2005][2005];
int main()
{
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(a,-1,sizeof(a));
    vis[1000][1000]=1;
    a[1000][1000]=1;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        for(int j=0;j<4;j++)
        {
            if(c==s[j])
            {
                x+=dx[j],y+=dy[j];
                break;
            }
        }
        if(!vis[x][y]==0)
        {
            a[x][y]=++num;
        }
        int last = a[xt][yt], now = a[x][y];
		if(!f[last][now] && vis[x][y]) ++ans;
		f[last][now] = f[now][last] = 1;
		xt=x,yt = y; vis[x][y] = 1;
    }
    cout<<ans;
}