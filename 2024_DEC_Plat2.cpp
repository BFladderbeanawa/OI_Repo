#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MOD=1e9+7;
int n;
int lo[MAXN][2],no[MAXN][2];
char color[MAXN];
long long dp[MAXN];
long long prefixSum[MAXN][2];
int calculateRangeSum(int pos,int leftLen,int rightLen){
    long long result=prefixSum[pos-leftLen*2][pos%2];
    if(pos-(rightLen+1)*2>=0){
        result-=prefixSum[pos-(rightLen+1)*2][pos%2];
    }
    return (result+MOD)%MOD;
}
int main(){
    cin>>n;
    string input;
    cin>>input;
    for(int i=1;i<=n;i++){
        color[i]=input[i-1];
    }
    for(int i=1;i<=n;i++){
        lo[i][0]=(color[i]=='R')?i:lo[i-1][0];
        lo[i][1]=(color[i]=='B')?i:lo[i-1][1];
    }
    no[n+1][0]=no[n+1][1]=n+1;
    for(int i=n;i>=1;i--){
        no[i][0]=(color[i]=='R')?i:no[i+1][0];
        no[i][1]=(color[i]=='B')?i:no[i+1][1];
    }
    dp[0]=prefixSum[0][0]=1;
    for(int i=1;i<=n;i++){
        if(color[i]=='X'){
            dp[i]=dp[i-1];
        }
        if(color[i]!='R'){
            int len=1;
            while(len*2<=i){
                if(lo[i][0]>=i-len+1){
                    break;
                }
                if(lo[i-len][1]>=i-len*2+1){
                    len=i-no[i-len*2+1][1]+1;
                    continue;
                }
                int maxLen=min((i-lo[i-len*2][1])/2,i-max(lo[i-len][0],lo[i-len][1]));
                dp[i]=(dp[i]+calculateRangeSum(i,len,maxLen))%MOD;
                len=maxLen+1;
            }
        }
        for(int j=0;j<=1;j++){
            prefixSum[i][j]=(prefixSum[i-1][j]+((i%2==j)?dp[i]:0))%MOD;
        }
    }
    cout<<dp[n];
}