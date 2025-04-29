#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int n,x,c[105],dp[N];
signed main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        dp[c[i]]=1;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>c[j])dp[i]+=dp[i-c[j]];
        }
        dp[i]=dp[i]%mod;
    }
    cout<<dp[x];
    
}
// :/wq