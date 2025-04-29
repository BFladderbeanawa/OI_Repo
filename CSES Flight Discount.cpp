#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,m;
vector<pair<int,int>> G1[MAXN],G2[MAXN];
bool vis[MAXN];
int d1[MAXN],d2[MAXN],deg[MAXN],weight[MAXN];
pair<pair<int,int>,int> e[MAXN];
void dijkstra(vector<pair<int,int>> G[],int dist[],int start){
    priority_queue<int> q;
    memset(vis,false,sizeof(vis));
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int top=q.top();
        q.pop();
        if(vis[top]) continue;
        vis[top]=1;
        for(pair<int,int> i:G[top]){
            dist[i.first]=min(dist[i.first],dist[top]+i.second);
            deg[i.first]--;
            if(!deg[i.first]){
                q.push(i.first);
            }
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G1[u].push_back(make_pair(v,w));
        G2[v].push_back(make_pair(u,w));
        deg[v]++;
        e[i]=make_pair(make_pair(u,v),w);
    }
    memset(d1,0x7f7f7f7f,sizeof(d1));
    memset(d2,0x7f7f7f7f,sizeof(d2));
    dijkstra(G1,d1,1);
    dijkstra(G2,d2,n);
    int minn=1e9;
    for(int i=1;i<=n;i++){
        cout<<d1[i]<<" "<<d2[i]<<" "<<weight[i]<<endl;
    }
    for(int i=1;i<=m;i++){
        minn=min(d1[e[i].first.first]+d2[e[i].first.second]+e[i].second/2,minn);
    }
    cout<<minn;
}