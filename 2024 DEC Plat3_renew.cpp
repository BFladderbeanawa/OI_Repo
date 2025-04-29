#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Job{
    int s,d;
};
bool cmp(Job &a, Job &b){
    return(a.s+a.d<b.s+b.d)||(a.s+a.d==b.s+b.d&&a.s<b.d);
}
vector<int> segT;
int segTSize;
void buildSegT(int n){
    segTSize=n;
    segT.assign(4*n,0);
}
int qR(int node, int start, int end, int l, int r){
    if(r<start||l>end){
        return 0;
    }
    if(l<=start && end<=r){
        return segT[node];
    }
    int mid=(start+end)>>1;
    int lc=2*node+1;
    int rc=2*node+2;
    return max(qR(lc,start,mid,l,r),qR(rc,mid+1,end,l,r));
}
void updR(int node,int start,int end,int l,int r,int value){
    if(r<start||l>end){
        return;
    }
    if(l<=start&&end<=r){
        segT[node]=value;
        return;
    }
    int mid=(start+end)>>1;
    int lc=2*node+1;
    int rc=2*node+2;
    updR(lc,start,mid,l,r,value);
    updR(rc,mid+1,end,l,r,value);
    segT[node]=max(segT[lc],segT[rc]);
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<Job> J(N);
        set<int> times;
        for(int i=0;i<N;i++){
            cin>>J[i].s>>J[i].d;
            times.insert(J[i].s);
            times.insert(J[i].s+J[i].d);
        }
        vector<int> tArr(times.begin(), times.end());
        sort(J.begin(),J.end(),cmp);
        buildSegT(tArr.size());
        int ans=0;
        for(Job &job: J){
            int sIdx=lower_bound(tArr.begin(),tArr.end(),job.s)-tArr.begin();
            int eIdx=lower_bound(tArr.begin(),tArr.end(),(job.s+job.d))-tArr.begin()-1;
            if(qR(0,0,segTSize-1,sIdx,eIdx)==0){
                updR(0,0,segTSize-1,sIdx,eIdx,1);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}