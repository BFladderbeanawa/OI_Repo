#include<bits/stdc++.h>
using namespace std;
int n,m;
char G[1005][1005];
vector<char> T;
pair <int,int> s;
pair <int,int> e;
pair <int,int> P[1005][1005];
bool vis[1005][1005];
int dx[4]={0,0,1,-1},
    dy[4]={1,-1,0,0};
int dis;
void position(pair<int,int> t,pair<int,int> p)
{
    if(p.first==t.first&&p.second+1==t.second)
    {
        T.push_back('R');
    }
    if(p.first==t.first&&p.second-1==t.second)
    {
        T.push_back('L');
    }
    if(p.first+1==t.first&&p.second==t.second)
    {
        T.push_back('D');
    }
    if(p.first-1==t.first&&p.second==t.second)
    {
        T.push_back('U');
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>G[i][j];
            if(G[i][j]=='A')
            {
                s={i,j};
            }
            if(G[i][j]=='B')
            {
                e={i,j};
            }
        }
    }
    queue <pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second]=1;
    while(!q.empty()){
        pair <int,int> top=q.front();
        q.pop();
        if(top==e){
            cout<<"YES"<<endl;
            pair <int, int> temp=P[top.first][top.second];
            position(e,temp);
            while(temp!=s)
            {
                dis++;
                position(temp,P[temp.first][temp.second]);
                temp=P[temp.first][temp.second];
            }
            cout<<dis+1<<endl;
            for(int i=T.size()-1;i>=0;i--)
            {
                cout<<T[i];
            }
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            pair <int,int> next= make_pair(top.first+dx[i],top.second+dy[i]);
            if(vis[next.first][next.second]||G[next.first][next.second]=='#'||next.first<0||next.first>=n||next.second<0||next.second>=m){
                continue;
            }
            else{
                q.push(next);
                vis[next.first][next.second]=1;
                P[next.first][next.second]=top;
            }
        }
    }
    cout<<"NO"<<endl;
}