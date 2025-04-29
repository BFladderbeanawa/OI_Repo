#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e5+10;
vector <int> seq;
int N,T,cnt,dp[MAXN];
signed main()
{
    cin>>N>>T;
    seq.push_back(-1);
    for(int i=0;i<N;i++)
    {
        int p,v;
        cin>>p>>v;
        seq.push_back(p+v*T);
    }
    for(int i=1;i<=N;i++)
    {
        int l=1,r=cnt,ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(dp[mid]<seq[i]) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(ans==0) ans=++cnt;
        dp[ans]=seq[i];
    }
    cout<<cnt;
}