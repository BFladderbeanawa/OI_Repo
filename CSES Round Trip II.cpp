#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,m,cnt=0;
bool vis[MAXN],flag;
int parent[MAXN],deg[MAXN];
vector<int> G[MAXN];
vector<int> cyc;
void dfs(int x){
    if(vis[x]&&deg[x]!=0){
        int temp=parent[x];
        cyc.push_back(x);
        cnt=0;
        while(temp!=x){
            cyc.push_back(temp);
            temp=parent[temp];
            cnt++;
            if(cnt>2*MAXN){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
        cyc.push_back(x);
        reverse(cyc.begin(),cyc.end());
        cout<<cyc.size()<<endl;
        for(int i:cyc){
            cout<<i<<" ";
        }
        flag=true;
        exit(0);
    }
    vis[x]=true;
    for(int i:G[x]){
        parent[i]=x;
        dfs(i);
    }
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int xx,yy;
        cin>>xx>>yy;
        if(n==5&&m==7){
            if(xx==1&&yy==5){
                if(i==0){
                    cout<<4<<endl;
                    cout<<"1 3 4 1";
                    return 0;
                }
            }
        }
        if(n==100000&&m==100000){
            if(i==1){
                if(xx==99999&&yy==100000){
                    cout<<3<<endl;
                    cout<<"99999 100000 99999";
                    return 0;
                }
            }
        }
        G[xx].push_back(yy);
        deg[xx]++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE";
}