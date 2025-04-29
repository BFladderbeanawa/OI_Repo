#include<bits/stdc++.h>
using namespace std;
int n,t;
int val[105][105],ans=1e9;
int dx[]={-3,-2,-2,-1,-1,0,0,1,1,2,2,3,0,0,1,-1},
    dy[]={0,-1,1,2,-2,3,-3,2,-2,1,-1,0,1,-1,0,0};
vector<pair<int,int>> G[105*105];
int dist[20010];
bool vis[20010];
int get(int x,int y){
    return (x-1)*n+y;
}
int main(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>val[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<16;k++){
                int xx=i+dx[k],yy=j+dy[k];
                if(xx>0&&xx<=n&&yy>0&&yy<=n){
                    G[get(i,j)].push_back(make_pair(get(xx,yy),val[xx][yy]+3*t));
                }
            }
        }
    }
    priority_queue<pair<int,int>>q;
    memset(dist,0x3f,sizeof(dist));
    q.push(make_pair(0,get(1,1)));
    dist[(get(1,1))]=0;
    while(!q.empty()){
        int top=q.top().second;
        q.pop();
        if(vis[top]) continue;
        vis[top]=1;
        for(pair<int,int> i:G[top]){
            if(dist[i.first]>dist[top]+i.second){
                dist[i.first]=dist[top]+i.second;
                q.push(make_pair(-dist[i.first],i.first));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(2*n-i-j<3){
                ans=min(ans,dist[get(i,j)]+(2*n-i-j)*t);
            }
        }
    }
    cout<<ans;
}