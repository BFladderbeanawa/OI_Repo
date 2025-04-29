#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,m;
int deg[MAXN];
vector<int> v[MAXN];
vector<int> G[MAXN];
bool check(int x){
    memset(G,sizeof(G),0);
    memset(deg,sizeof(deg),0);
    for(int i=1;i<=x;i++){
        for(int j=0;j<v[i].size()-1;j++){
            G[v[i][j]].push_back(v[i][j+1]);
            deg[v[i][j+1]]++;
        }
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
        for(int i:G[top]){
            deg[i]--;
            if(!deg[i]){
                q.push(i);
            }
        }
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            tot++;
        }
    }
    if(tot<n){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int mi;
        cin>>mi;
        for(int j=0;j<mi;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    int ans;
    for(ans=r;ans<=l;ans++){
        if(check(ans)){
            break;
        }
    }
    memset(G,sizeof(G),0);
    memset(deg,sizeof(deg),0);
    for(int i=1;i<=ans;i++){
        for(int j=0;j<v[i].size()-1;j++){ 
            G[v[i][j]].push_back(v[i][j+1]);
            deg[v[i][j+1]]++;
        }
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.top();
        q.pop();
        cout<<top<<" ";
        for(int i:G[top]){
            deg[i]--;
            if(!deg[i]){
                q.push(i);
            }
        }
    }
}