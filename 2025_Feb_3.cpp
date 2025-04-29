#include<bits/stdc++.h>
using namespace std;
int n,m;
int mask[1<<16],dp[1<<16];
void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        mask[1<<x|1<<y]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mask[1<<i|1<<j]++;
        }
    }
}
void state(){
    input();
    for(int i=(1<<n)-1;i>=0;i--){
        for(int j=i&(i-1);j;j=(j-1)&i){
            mask[i]+=mask[j];
        }
    }
}
void dynamic_programming(){
    state();
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<(1<<n);i++){
        int cnt=__builtin_popcount(i);
        dp[i]=cnt*(cnt-1)/2-mask[i];
        for(int j=i&(i-1);j;j=(j-1)&i){
            if(dp[j]>=1e9||dp[i^j]>=1e9)continue;
            dp[i]=min(dp[i],dp[j]+dp[i^j]+mask[i]-mask[j]-mask[i^j]);
        }
    }
}
int main(){
    dynamic_programming();
    cout<<dp[(1<<n)-1]<<endl;
}