#include <bits/stdc++.h>
using namespace std;


long long coin[105];
int dp[105][1000005];
int main(){
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++){
                cin>>coin[i];
        }
        
        dp[0][0]=1;
        int mod = 1e9+7;
        for(int i =1;i<=n;i++){//coin,use i speices coins to compose j money
                for(int j= 0;j<=x;j++){//money
                        dp[i][j]=dp[i-1][j];
                        if(j-coin[i-1]>=0){
                                (dp[i][j]+=dp[i][j-coin[i-1]])%=mod;
                        }
                }
        }
        // for(int i=0;i<=n;i++){
        //         for(int j=0;j<=x;j++){
        //                 cout<<dp[i][j]<<" ";
        //         }
        //         cout<<endl;
        // }
        cout<<dp[n][x]<<endl;

}
