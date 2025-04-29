#include<bits/stdc++.h>
using namespace std;
int X,Y,K,M,ans=0x3f3f3f3f;
bool vis[105][105];
void dfs(int xn,int yn,int kn)
{
    if(vis[xn][yn]==1||kn-1>K)
    {
        return;
    }
    ans=min(ans,abs(M-(xn+yn)));
    vis[xn][yn]=1;
    dfs(X,yn,kn+1);
    dfs(xn,Y,kn+1);
    dfs(0,yn,kn+1);
    dfs(xn,0,kn+1);
    if(X-xn<=yn)
    {
        dfs(X,yn-(X-xn),kn+1);
    }
    else{
        dfs(xn+yn,0,kn+1);
    }
    if(Y-yn<=xn)
    {
        dfs(xn-(Y-yn),Y,kn+1);
    }
    else{
        dfs(0,xn+yn,kn+1);
    }
    vis[xn][yn]=0;
}
int main()
{
    cin>>X>>Y>>K>>M;
    dfs(0,0,1);
    cout<<ans;
}