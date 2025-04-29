#include<bits/stdc++.h>
#define int long long
using namespace std;
int N;
int cnt=0,minn=INT_MAX,ans;
bool a[300005];
signed main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        char c;
        cin>>c;
        a[i]=(c=='1');
    }
    for(int i=1;i<=N+1;i++)
    {
        if(a[i]==1)
        {
            cnt++;
        }
        if(a[i]==0&&a[i-1]==1)
        {
            if(cnt==N)
            {
                minn=min(minn,(cnt-1));
            }
            else if(a[1]==1||a[N]==1){
                minn=min(minn,cnt-1);
            }
            else
            {
                minn=min(minn,(cnt-1)/2);
            }
            cnt=0;
        }
    }
    //cout<<minn<<endl;
    cnt=0;
    for(int i=1;i<=N+1;i++)
    {
        if(a[i]==1)
        {
            cnt++;
        }
        if(a[i]==0&&a[i-1]==1)
        {
            ans+=ceil(cnt*1.0/(2*minn+1));
            cnt=0;
        }
    }
    cout<<ans;
}
