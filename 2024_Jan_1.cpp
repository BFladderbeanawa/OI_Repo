#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],sum[N],f[N],b[N];
int n,m,c;
void check(){
    bool tt=1;
    for (int i=1;i<=n;i++) {
        b[i]=max(b[i-1],a[i]);
        if (a[i]>c) tt=0;
        if (b[i-1]<a[i]&&sum[i]>0) tt=0;
        if (b[i-1]>=a[i]&&f[i]) tt=0;
    }
    if (!tt){
        cout<<-1<<endl;
    } else {
        for (int i=1;i<n;i++) cout<<a[i]<<" ";
        cout<<a[n]<<endl;
    }
}
void solve(){
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        f[y]=1;
        sum[x+1]++; sum[y]--;
    }
    for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
    int mx=1;
    int pre=0;
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            if (f[i]) a[i]=mx+1;
            else a[i]=1;
            if (sum[i]==0) pre=i;
        }
        if (sum[i]>0&&a[i]>mx){
            a[pre]=a[i];
        }
        mx=max(mx,a[i]);
    }
    check();
}
void redo(){
    memset(sum,0,sizeof(sum));
    memset(f,0,sizeof(f));
}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
        redo();
    }
    return 0;
}
