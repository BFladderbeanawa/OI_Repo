#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,c;
bool a[N][25];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n;
    vector<int> bin;
    vector<int> dist(1<<c,c);
    vector<int> stor_pct(1<<((c+1)-1));
    for(int i=0;i<(1<<(c+1)/2);++i)
    {
        stor_pct[i]=__builtin_popcount(i);
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int mask=0;
        for(int j=0;j<c;j++)
        {
            mask^=(s[j]-'G')<<j;
        }
        for(int j=0;j<(1<<(c/2));j++)
        {
            dist[mask^j]=min(dist[mask^j],stor_pct[j]);
        }
        bin.push_back(mask);
    }
    for(int x:bin)
    {
        x=(1<<c)-1-x;
        int ret=c;
        for (int i=0;i<(1<<(c-c/2));i++)
        {
            ret=min(ret,dist[x^(i<<(c/2))]+stor_pct[i]);
        }
        cout<<c-ret<<endl;
    }
}