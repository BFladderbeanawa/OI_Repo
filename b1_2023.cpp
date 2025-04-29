#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,M;
ll a[200005],b[200005],eatable;
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<M;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<M;i++)
    {
        ll eaten=0;
        for(int j=0;j<N;j++)
        {
            eatable=min(b[i],a[j]);
            a[j]+=max((eatable-eaten),0ll);
            eaten=max(eatable,eaten);
            if(eaten>=b[i])
            {
                break;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<endl;
    }
}