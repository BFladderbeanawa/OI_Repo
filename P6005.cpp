#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int w[1005];
vector<int> g[1005];
int dp[1005][1005];
int main()
{
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int len=g[j].size();
            for(int k=0;k<len;k++)
            {
                int u=g[j][k];
                if(dp[i-1][u]!=-1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][u]+w[j]);
                }
            }
        }
        ans=max(ans,dp[i][1]-c*i*i);
    }
    cout<<ans<<endl;
}