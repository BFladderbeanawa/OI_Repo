#include<bits/stdc++.h>
using namespace std;
int n,H[110],h[110],dp[110][1010],sum[1010];
const int INF=1000;
const int mod=1e9+7;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>H[i];
    }
    if(n%2==0)
    {
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=H[i];j++)
            {
                for(int k=j;k<=H[i];k++)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][k-j])%mod;
                }
            }
        }
        cout<<dp[n][0]<<endl;
    }
    else
    {
        int lim=INF,ans=0;
        for(int i=1;i<=n;i+=2)
        {
            lim=max(lim,H[i]);
        }
        for(int k=0;k<=lim;k++)
        {
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int i=1;i<=n;i++)
            {
                sum[0]=dp[i-1][0];
                for(int j=1;j<=1000;j++)
                {
                    sum[j]=(sum[j-1]+dp[i-1][j])%mod;
                }
                for(int j=(i%2==0?0:k);j<=H[i];j++)
                {
                    dp[i][j]=sum[H[i]-j];
                }
            }
            ans=(ans+dp[n][k])%mod;
        }
        cout<<ans<<endl;
    }
}