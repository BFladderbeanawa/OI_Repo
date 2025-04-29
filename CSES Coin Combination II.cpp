#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int n,x,dp[1000005][105],c[105];
signed main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        dp[c[i]][i]=1;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]+=dp[i][j-1];
            if(c[j]<i) dp[i][j]+=dp[i-c[j]][j];
            dp[i][j]%=mod;
        }
    }
    // for(int i=1;i<=x;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
        
    cout<<dp[x][n];
}