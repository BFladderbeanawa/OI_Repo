#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct cow{
    int w,a;
}c[N];
int n,m,k;
int cnt=0;
vector <cow> slot;
bool cmp(cow a,cow b)
{
    return a.w>b.w;
}
signed main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>c[i].w>>c[i].a;
    }
    sort(c,c+n,cmp);
    slot.push_back((cow){(int)1e18,m});
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<slot.size();j++){
            if(slot[j].w-k>=c[i].w)
            {
                if(c[i].a<slot[j].a)
                {
                    slot[j].a-=c[i].a;
                    slot.push_back(c[i]);
                    cnt+=c[i].a;
                    break;
                }
                else if(c[i].a==slot[j].a)
                {
                    slot.push_back(c[i]);
                    cnt+=c[i].a;
                    slot.erase(slot.begin()+j);
                    break;
                }
                else{
                    slot.push_back((cow){c[i].w,slot[j].a});
                    cnt+=slot[j].a;
                    c[i].a-=slot[j].a;
                    slot.erase(slot.begin()+j);
                    j--;
                }
            }
            else break;
        }
    }
    cout<<cnt;
}