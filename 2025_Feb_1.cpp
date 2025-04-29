#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+10;
const int INF=1e18;

int N;
int ans=0;
int dp1[MAXN][2],dp2[MAXN][2];
int a[MAXN],c[MAXN],vis[MAXN],deg[MAXN];
int cost=INF;

void dp(int x,bool first){
    int u=x;
    int v=a[x];
    while(v!=x){
        dp2[v][1]=dp1[v][1]+min(dp2[u][0],dp2[u][1]);
        dp2[v][0]=dp1[v][0]+dp2[u][1];
        if(first) vis[v]=1;
        u=v;
        v=a[u];
    }
    if(first) cost=min(dp2[u][0],dp2[u][1]);
    else cost=min(cost,dp2[u][1]);
}

void dfs(int x){
    vis[x]=1;
    int u=x;
    int v=a[u];
    if(a[u]==x){
        ans+=min(dp1[u][0],dp1[u][1]);
        return;
    }
    
    cost=INF;
    dp2[u][0]=INF;
    dp2[u][1]=dp1[x][1];
    dp(x,true);  
    
    dp2[x][0]=dp1[x][0];  
    dp2[x][1]=dp1[x][1];
    dp(x,false); 
    
    ans+=cost;
}

signed main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i], deg[a[i]]++;
    for(int i=1;i<=N;i++) cin>>c[i];
    
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(a[i]!=i) dp1[i][1]=c[i];
        dp1[i][0]=0;
        if(deg[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int top=q.front();
        q.pop();
        int x=a[top];
        dp1[x][1]+=min(dp1[top][0],dp1[top][1]);
        vis[top]=1;
        dp1[x][0]+=dp1[top][1];
        deg[x]--;
        if(deg[x]==0) q.push(x);
    }
    
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}