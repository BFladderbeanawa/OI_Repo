#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e4+5;
int B,E,P;
int n,m;
int disB[MAXN],disE[MAXN],disP[MAXN];
int minn=1e9;
bool vis[MAXN];
vector<int>G[MAXN];
void bfs(int x,int dis[]){
    queue<int> q;
    q.push(x);
    vis[x]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:G[top]){
            if(i&&!vis[i]){
                q.push(i);
                vis[i]=true;
                dis[i]=dis[top]+1;
            }
        }
    }
}
int main(){
    cin>>B>>E>>P>>n>>m;
    for(int i=0;i<m;i++){
        int xx,yy;
        cin>>xx>>yy;
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    memset(vis,0,sizeof(vis));
    bfs(1,disB);
    memset(vis,0,sizeof(vis));
    bfs(2,disE);
    memset(vis,0,sizeof(vis));
    bfs(n,disP);
    for(int i=1;i<=n;i++){
        minn=min(minn,B*disB[i]+E*disE[i]+P*disP[i]);
    }
    cout<<minn;
}