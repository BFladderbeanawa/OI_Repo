#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,m,c;
int s[MAXN],deg[MAXN];
vector<pair<int,int>> G[MAXN];
int main(){
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
        cin>>s[i];
	}
    for(int i=0;i<c;i++){
        int a,b,w;
        cin>>a>>b>>w;
        G[a].push_back(make_pair(b,w));
        deg[b]++;
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
        for(pair<int,int> i:G[top]){
            deg[i.first]--;
            s[i.first]=max(s[i.first],s[top]+i.second);
            if(!deg[i.first]){
                q.push(i.first);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i]<<endl;
    }
}