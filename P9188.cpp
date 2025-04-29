#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=3e5+5;
int dp[N],f[7],ans=0;
signed main()
{
    cin>>s;
    int n=s.size();
    s="*"+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='b')
        {
            f[1]=i;
        }
        if(s[i]=='e')
        {
            f[6]=f[5],f[2]=f[1];
        }
        if(s[i]=='s')
        {
            f[4]=f[3],f[3]=f[2];
        }
        if(s[i]=='i')
        {
            f[5]=f[4];
        }
        dp[i]=dp[f[6]-1]+f[6];
    }
    for(int i=1;i<=n;i++)
    {
        ans+=dp[i];
    }
    cout<<ans;
}
//bessie