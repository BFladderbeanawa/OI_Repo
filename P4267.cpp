#include<bits/stdc++.h>
using namespace std;
int n,dp[110][110][110],g[110][110],a[110];
const int INF=0x3f3f3f3f;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,INF,sizeof(dp));
	memset(g,INF,sizeof(g));
	dp[0][0][0]=0,g[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(!k)dp[i][j][k]=g[i-1][j-1]+(a[i]!=0),g[i][j]=min(g[i][j],dp[i][j][k]);
				else dp[i][j][k]=dp[i-1][j][k-1]+(a[i]!=k),g[i][j]=min(g[i][j],dp[i][j][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<g[n][i]<<endl;
	}
}
