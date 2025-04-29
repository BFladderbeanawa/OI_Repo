#include<bits/stdc++.h>
using namespace std;
int n;
double dis=0;
vector <pair<int, int>> G;
vector <int> Per;
int main()
{
    cin>>n;
    G.push_back(make_pair(0,0));
    for(int i=0;i<n;i++)
    {
        Per.push_back(i+1);
        int x,y;
        cin>>x>>y;
        dis+=sqrt((x-G[i].first)*(x-G[i].first)+(y-G[i].second)*(y-G[i].second));
        G.push_back(make_pair(x,y));
    }
    // cout<<dis;
    // for(int i=0;i<G.size();i++)
    // {
    //     cout<<G[i].first<<" "<<G[i].second;
    // }
    while(next_permutation(Per.begin(),Per.end()))
    {
        int total=sqrt((0-G[Per[0]].first)*(0-G[Per[0]].first)+(0-G[Per[0]].second)*(0-G[Per[0]].second));
        for(int i=1;i<n;i++){
            cout<<Per[i]<<" ";
            total+=sqrt((G[Per[i-1]].first-G[Per[i]].first)*(G[Per[i-1]].first-G[Per[i]].first)+(G[Per[i-1]].second-G[Per[i]].second)*(G[Per[i-1]].second-G[Per[i]].second));
        }
        dis=min(dis,total);
        cout<<endl;
    }
    cout<<dis;
}