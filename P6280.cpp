#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e4+10;
int dp[N][N];
bool isprime[N];
int prime[N],cnt=0;
void getprime(int x)
{
    isprime[1]=1;
    for(int i=2;i<=x;i++)
    {
        if(!isprime[i])
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*prime[j]<=x;j++)
        {
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    getprime(n);
    //cout<<cnt<<endl;
    //dp[i][j]=n∑k=prime[i] dp[i-1][j-k];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            dp[i][j]=dp[i][j-1];
            for(int k=prime[j];k<=i;k*=prime[j])
            {
                dp[i][j]+=(dp[i-k][j-1]*k)%m;
                //cout<<prime[j]<<" ";
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
        (ans+=dp[i][cnt])%=m;
    }
    cout<<ans+1;
}