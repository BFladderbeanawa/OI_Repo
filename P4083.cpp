#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,d,dis[MAXN*2];
bool vis[MAXN];
struct PIE{
    int BR,ER,id;
};
PIE B[MAXN],E[MAXN];
vector<int> G[MAXN*2];
queue<int> q;
bool cmpB(PIE x,PIE y){
    return x.ER<y.ER;
}
bool cmpE(PIE x,PIE y){
    return x.BR<y.BR;
}
signed main(){
    cin>>n>>d;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++){
        cin>>B[i].BR>>B[i].ER;
        B[i].id=i;
        if(B[i].ER==0){
            q.push(i);
            vis[i]=true;
            dis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>E[i].BR>>E[i].ER;
        E[i].id=i;
        if(E[i].BR==0){
            q.push(i+n);
            vis[i+n]=true;
            dis[i+n]=1;
        }
    }
    sort(B+1,B+n+1,cmpB);
    sort(E+1,E+n+1,cmpE);
    for(int i=1;i<=n;i++){
        int idx=lower_bound(E+1, E+n+1, B[i].BR-d, [](const PIE& e, const int val){ return e.BR < val; }) - E;
        for(int j=idx;j<=n;j++){
            if(B[i].BR<E[j].BR){
                break;
            }
            G[B[i].id].push_back(E[j].id+n);
        }
    }
    for(int i=1;i<=n;i++){
        int idx=lower_bound(B+1, B+n+1, E[i].ER-d, [](const PIE& b, const int val){ return b.ER < val; }) - B;
        for(int j=idx;j<=n;j++){
            if(E[i].ER<B[j].ER){
                break;
            }
            G[E[i].id+n].push_back(B[j].id);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:G[top]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                dis[i]=dis[top]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<endl;
    }
}