#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,r[105],dp[205][205],mx[205][205];
signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    //cout<<"!1"<<endl;
    int result=INT_MAX;
    for(int i=0;i<n;i++)
    {
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0][n]=0;
        for(int j=1;j<=m;j++)
        {
            //cout<<"!2"<<endl;
            for(int k=0;k<n;k++)
            {
                int val=0;
                for(int l=k+1;l<=n;l++)
                {
                    val += r[l - 1] * (l - k - 1);
                    dp[j][k]=min(dp[j][k],val+dp[j-1][l]);
                }
            }
        }
        result = min(result, dp[m][0]);
        rotate(r, r + 1, r + n);
    }
        
    cout<<result;
}