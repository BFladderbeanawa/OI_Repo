#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10,mod=1e9+7;
int n,m;
int dp[MAXN],deg[MAXN];
vector<int> G1[MAXN],G2[MAXN],topo;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        G1[a].push_back(b);
        G2[b].push_back(a);
        deg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        topo.push_back(top);
        for(int i:G1[top]){
            deg[i]--;
            if(!deg[i]){
                q.push(i);
            }
        }
    }
    dp[1]=1;
    for(int i=1;i<n;i++){
        for(int j:G2[topo[i]]){
            dp[topo[i]]=(dp[topo[i]]+dp[j])%mod;
        }
    }
    cout<<dp[n];
}