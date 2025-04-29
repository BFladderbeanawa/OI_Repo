#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],b[N],cnt[N],sumn,temp[N],pos1[N],pos2[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        pos1[a[i]]=i;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        cnt[b[i]]++;
        pos2[b[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(pos1[i]&&pos2[i])
        {
            temp[(pos1[i]-pos2[i]+k)%k]++;
            //cout<<pos1[i]<<" "<<pos2[i]<<endl;
        }
    }
    for(int i=0;i<n;i++)
    {
        //cout<<temp[i]<<" ";
        sumn=max(sumn,temp[i]);
    }
    reverse(b+1,b+k+1);
    memset(temp,0,sizeof(temp));
    memset(pos1,0,sizeof(pos1));
    memset(pos2,0,sizeof(pos2));
    for(int i=1;i<=k;i++)
    {
        pos1[a[i]]=i;
    }
    for(int i=1;i<=k;i++)
    {
        pos2[b[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(pos1[i]&&pos2[i])
        {
            temp[(pos1[i]-pos2[i]+k)%k]++;
            //cout<<pos1[i]<<" "<<pos2[i]<<endl;
        }
    }
    for(int i=0;i<n;i++)
    {
        //cout<<temp[i]<<" ";
        sumn=max(sumn,temp[i]);
    }
    //cout<<sumn<<endl;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==0)
        {
            sumn++;
        }
    }
    cout<<sumn;
}