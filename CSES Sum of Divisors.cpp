#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt=0,l=1,r=1;
const int TWO_MOD_INV = 500000004;
const int MOD = 1e9+7;
signed main()
{
    cin>>n;
    while(l<=n){
        int q;
        q=n/l;
        r=n/q;
        cnt+=q*((((r-l+1)%MOD)*((r+l)%MOD)%MOD)*TWO_MOD_INV%MOD)%MOD;
        l=r+1;
        cnt=cnt%MOD;
    }
    cout<<cnt;
}