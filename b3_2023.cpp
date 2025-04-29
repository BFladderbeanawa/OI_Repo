#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,sign,cnt=0;
struct plants
{
    ll h,a,t;
}p[200005];
ll f[200005];
void solve()
{
    ll ans=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>p[i].h;
    }
    for(int i=0;i<N;i++)
    {
        cin>>p[i].a;
    }
    for(int i=0;i<N;i++)
    {
        cin>>p[i].t;
        f[p[i].t]=i;
    }
    for(int i=0;i<N-1;i++)
    {
        if(p[f[i]].a>p[f[i+1]].a&&p[f[i]].h<=p[f[i+1]].h)
        {
            ans=max(ans,(ll)ceil((p[f[i+1]].h-p[f[i]].h+1)*1.0/(p[f[i]].a-p[f[i+1]].a)));
        }
    }
    for(int i=0;i<N;i++)
    {
        p[i].h+=ans*p[i].a;
    }
    for(int i=0;i<N-1;i++)
    {
        if(p[f[i]].h<=p[f[i+1]].h)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        solve();
    }
}