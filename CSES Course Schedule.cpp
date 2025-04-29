#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,m;
int deg_in[MAXN];
vector<int> G[MAXN];
vector<int> ans;
queue<int> q;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int xx,yy;
        cin>>xx>>yy;
        G[xx].push_back(yy);
        deg_in[yy]++;
    }
    for(int i=1;i<=n;i++){
        if(deg_in[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:G[top]){
            deg_in[i]--;
            if(deg_in[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    if(ans.size()==n){
        for(int i:ans){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}