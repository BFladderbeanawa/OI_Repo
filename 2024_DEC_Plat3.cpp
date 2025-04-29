#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Job{
    int id,StartTime,EndTime,Duration;
};
bool cmp(Job &a,Job &b){
    if(a.EndTime!=b.EndTime)
        return a.EndTime<b.EndTime;
    if(a.StartTime!=b.StartTime)
        return a.StartTime<b.StartTime;
    if(a.id != b.id)
        return a.id<b.id;
    return a.Duration<b.Duration;
}
void solve(){
    int n;
    cin>>n;
    vector<Job> jobs(n);
    for(int i=0;i<n;i++){
        int s,d;
        cin>>s>>d;
        jobs[i]={i,s,s+d,d};
    }
    sort(jobs.begin(),jobs.end(),cmp);
    priority_queue<int>SelectedJob;
    int Cur_Time=0;
    int ans=0;
    for(Job i:jobs){
        SelectedJob.push(i.StartTime);
        Cur_Time+=i.Duration;
        ans++;
        if(Cur_Time>i.EndTime){
            Cur_Time-=i.Duration;
            ans--;
            SelectedJob.pop();
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}