#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c[30][30],dp[N];
char s[N];
int sum[30][N];
int mn[30];
int main (){
	
	int n,m,k;
    cin>>n>>m>>k;
	scanf("%s",s+1);
	for (int i=0;i<m;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>c[i][j];
        }
    }
		
	for (int l=0;l<m;l++)
    {
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (i!=j&&j!=l&&i!=l)
                {
                    c[i][j]=min(c[i][j],c[i][l]+c[l][j]);
                }
					
            }
        }
    }
    //floyd	
	for (int i=0;i<m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            sum[i][j]=c[s[j]-'a'][i]+sum[i][j-1];
        }
    }
    //前缀和
	memset (mn,0x3f,sizeof(mn));
	memset (dp,0x3f,sizeof(dp));
    dp[0]=0;
	for (int i=k;i<=n;i++)
    {
        for (int j=0;j<m;j++)
        {
            mn[j]=min(mn[j]+c[s[i]-'a'][j],dp[i-k]+sum[j][i]-sum[j][i-k]);
            dp[i]=min(dp[i],mn[j]);
        }
    }
	cout<<dp[n];
	return 0;
}