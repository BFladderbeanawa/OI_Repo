#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
set<int> ans;
int n,x[105],sum,dp[105][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        sum+=x[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(x[i]<=j)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-x[i]]+x[i]);
            }
            if(dp[i][j]) ans.insert(dp[i][j]);
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans)
    {
        cout<<i<<" ";
    }
}