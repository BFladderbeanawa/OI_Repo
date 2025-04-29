#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,k;
vector<int> G[MAXN];
int P[MAXN],cnt,ans=0;
bool flag[MAXN];
void dfs(int x, int fa){
    P[++cnt]=x;
    if(G[x].size()==1){
        flag[P[cnt/2+1]]=1;
        cnt--;
        return;
    }
    for(int i:G[x]){
        if(i!=fa)
            dfs(i,x);
    }
    cnt--;
}
void dfs2(int x, int fa){
    if(flag[x]){
        ans++;
        return;
    }
    for(int i:G[x]){
        if(i!=fa)
            dfs2(i,x);
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int xx,yy;
        cin>>xx>>yy;
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    dfs(k,0);
    dfs2(k,0);
    cout<<ans;
}