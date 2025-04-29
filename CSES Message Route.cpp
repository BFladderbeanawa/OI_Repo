#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<int> G[MAXN];
vector<int> pas;
queue<int> q;
bool vis[MAXN];
int path[MAXN];
int n,m,cnt;
int temp;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int tx,ty;
        cin>>tx>>ty;
        G[tx].push_back(ty);
        G[ty].push_back(tx);
    }
    
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        // cnt++;
        for(int j:G[cur]){
            if(!vis[j])
            {
                q.push(j);
                path[j]=cur;
                vis[j]=true;
                if(j==n){
                    // cout<<cnt-1<<endl;
                    temp=path[j];
                    while(temp!=1)
                    {
                        pas.push_back(temp);
                        temp=path[temp];
                    }
                    cout<<pas.size()+2<<endl;
                    cout<<1<<" ";
                    reverse(pas.begin(),pas.end());
                    for(int i:pas){
                        cout<<i<<" ";
                    }
                    cout<<n;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
}