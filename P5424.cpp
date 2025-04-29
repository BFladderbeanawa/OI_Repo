#include<bits/stdc++.h>
using namespace std;
int n,m,a[410][410],dp[405][405],s[410];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][i];
        s[i]=a[i][i]+s[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            a[i][j]=max(a[i][j-1],a[j][j]);
        }
    }
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i+1&&j<=i;j++)
        {
            for(int k=0;k<i;k++)
            {
                dp[i][j]=min(dp[i][j],dp[k][j-1]+a[k+1][i]*(i-k)-s[i]+s[k]);
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        dp[n][m+1]=min(dp[n][m+1],dp[n][i]);
    }
    cout<<dp[n][m+1];
}