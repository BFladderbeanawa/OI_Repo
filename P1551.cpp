#include<bits/stdc++.h>
using namespace std;
int father[5005];
int find(int k){if(father[k]==k)return k;return father[k]=find(father[k]);}
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<5005;i++)
    {
        father[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        father[find(y)]=find(x);
    }
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        if(find(x)==find(y))
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}