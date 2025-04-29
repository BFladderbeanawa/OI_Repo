#include<bits/stdc++.h>
using namespace std;
int N,B,f[255],s[255],d[255],dp[255];
int main()
{
    cin>>N>>B;
    memset(dp,0x3f3f3f,sizeof(dp));
    for(int i=0;i<N;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<B;i++)
    {
        cin>>s[i]>>d[i];
    }
    dp[0]=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=dp[j];k<B;k++)
            {
                if(j+d[k]>=i&&s[j]>=f[i]&&s[k]>=f[j])
                {
                    dp[i]=min(dp[i],k);
                }
            }
        }
    }
    cout<<dp[N-1];
}