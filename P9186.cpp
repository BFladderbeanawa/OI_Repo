#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1.5e5+10;
int a[N],n,sum,s[N],b[N];
map<int,int> P;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        sum+=i*b[i];
        s[i]=s[i-1]+b[i];
        P[b[i]]=i;
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int x,y;
        cin>>x>>y;
        int pos=upper_bound(b+1,b+n+1,y)-b;
        int ans=sum;
        ans-=a[x]*P[a[x]];
        ans-=s[n]-s[P[a[x]]];
        ans+=y*(pos-(pos>P[a[x]]));
        ans+=s[n]-s[pos-1];
        if(pos<=P[a[x]])
        {
            ans-=b[P[a[x]]];
        }
        cout<<ans<<endl;
    }
}