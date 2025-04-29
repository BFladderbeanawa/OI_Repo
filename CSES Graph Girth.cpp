#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
vector<int> G[2505];
int ans,minn=2147483647;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        vector<int> dist(n+1,1e9);
        q.push(i);
        dist[i]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(int j:G[top]){
                if(dist[j]==1e9){
                    dist[j]=dist[top]+1;
                    q.push(j);
                }
                else if(dist[j]>=dist[top]){
                    minn=min(dist[top]+1+dist[j],minn);
                }
            }
        }
    }
    if(minn==2147483647){
        cout<<-1;
    }
    else{
        cout<<minn;
    }
}