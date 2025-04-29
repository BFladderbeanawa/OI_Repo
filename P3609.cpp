#include<bits/stdc++.h>
using namespace std;
int N,K;
const int MAXN=1e5+10;
bool h[MAXN],s[MAXN],p[MAXN];
int dp[MAXN][25][3];
int main()
{
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        char t;
        cin>>t;
        if(t=='H')
        {
            p[i]=1;
        }
        if(t=='S')
        {
            h[i]=1;
        }
        if(t=='P')
        {
            s[i]=1;
        }
    }
    dp[1][0][0]=h[1];
    dp[1][0][1]=s[1];
    dp[1][0][2]=p[1];
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=K;j++)
        {
            if(j==0){
                dp[i][j][0]=max(dp[i-1][j][0]+h[i],dp[i][j][0]);
                dp[i][j][1]=max(dp[i-1][j][1]+s[i],dp[i][j][1]);
                dp[i][j][2]=max(dp[i-1][j][2]+p[i],dp[i][j][2]);
            }
            else{
                dp[i][j][0]=max(dp[i-1][j-1][1]+h[i],max(dp[i-1][j-1][2]+h[i],max(dp[i-1][j][0]+h[i],dp[i][j][0])));
                dp[i][j][1]=max(dp[i-1][j-1][0]+s[i],max(dp[i-1][j-1][2]+s[i],max(dp[i-1][j][1]+s[i],dp[i][j][1])));
                dp[i][j][2]=max(dp[i-1][j-1][1]+p[i],max(dp[i-1][j-1][0]+p[i],max(dp[i-1][j][2]+p[i],dp[i][j][2])));
            }
                
        }
    }
    int ans=0;
    for(int i=0;i<=K;i++)
    {
        ans=max(ans,max(dp[N][i][0],max(dp[N][i][1],dp[N][i][2])));
    }
    cout<<ans<<endl;
    // for(int i=1;i<=N;i++)
    // {
    //     cout<<p[i]<<" "<<h[i]<<" "<<s[i]<<endl;
    // }

}