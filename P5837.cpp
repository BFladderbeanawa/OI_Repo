#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int INF=0x7f7f7f7f;
int n,m;
int c,f[MAXN];
struct node{
    int to,c,f;
    bool operator<(const node& a)const{
        return c>a.c;
    }
};
vector<node> G[MAXN];
int dis[MAXN];
bool vis[MAXN];
int dijkstra(int limit){
    priority_queue<node> q;
    memset(vis,false,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    dis[1]=0;
    q.push(node{1,0,limit});
    while(!q.empty()){
        int top=q.top().to;
        q.pop();
        if(vis[top]){
            continue;
        }
        vis[top]=true;
        for(node i:G[top]){
            if(i.f>=limit&&dis[i.to]>dis[top]+i.c){
                dis[i.to]=dis[top]+i.c;
                q.push(node{i.to,dis[i.to],limit});
            }
        }
    }
    return dis[n];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b>>c>>f[i];
        G[a].push_back(node{b,c,f[i]});
        G[b].push_back(node{a,c,f[i]});
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(ans,f[i]*int(1e6)/dijkstra(f[i]));
    }
    cout<<ans<<endl;
}