#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int mod=1e9+7;
int n,dp[N][N];
char g[N][N];
int ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    if(g[1][1]=='*'){cout<<0;return 0;}
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        	if(i==1&&j==1) continue;
            if(g[i][j]=='.')
			{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
			}
        }
    }
    cout<<dp[n][n];
}
