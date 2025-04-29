#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n;
struct node{
    int x,y;
}N[MAXN];
map<int,vector<int>> G[2];
int main(){
    cin>>n;
    for(int i=0;i<n+2;i++){
        cin>>N[i].x>>N[i].y;
        G[0][N[i].x].push_back(i);
        G[1][N[i].y].push_back(i);
    }//数据预处理
    queue<pair<int,bool>> q;//首位代表编号，bool代表方向
    vector<int> dis(MAXN,1e9+5);//转折次数
    q.push(make_pair(0,true));
    q.push(make_pair(0,false));//两个方向都要起始讨论
    dis[0]=0;
    while(!q.empty()){
        pair<int,bool> top=q.front();
        q.pop();
        int dir;//决定方向，注意与预处理时G[0/1]匹配
        if(!top.second)
            dir=N[top.first].x;
        else
            dir=N[top.first].y;
        for(int i:G[top.second][dir]){
            if(dis[i]==1e9+5){
                q.push(make_pair(i,!top.second));//到点必转向
                dis[i]=dis[top.first]+1;//更新dis
            }
        }
    }
    if(dis[1]==1e9+5)
        cout<<-1;
    else
        cout<<dis[1]-1;
}