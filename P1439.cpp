#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,List1[N],List2[N],dp[N][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>List1[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>List2[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(List1[i]==List2[j])
            {
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][n];
}