#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int N,ans=0;
int temp_res[MAXN],mark[MAXN],res[MAXN];
vector<int> pos[MAXN];
signed main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        pos[i].clear();
    }
    for(int i=1;i<=N;i++){
        int label;
        cin>>label;
        pos[label].push_back(i);
    }
    for(int label=1;label<=N;label++){
        vector<int> curPos=pos[label];
        if(curPos.empty()) continue;
        if(curPos.size()>500){
            int marker=-1;
            for(int i=1;i<=N;i++){
                mark[i]=marker;
            }
            for(int pos:curPos){
                mark[pos]=pos;
            }
            for(int i=N-1;i>0;i--){
                if(mark[i]==marker){
                    mark[i]=mark[i+1];
                }
            }
            for(int i=1;i<=N;i++){
                int next=mark[1];
                int cnt=0;
                while(true){
                    next+=i+1;
                    cnt++;
                    if(next>N||mark[next]==marker){
                        break;
                    }
                    next=mark[next];
                }
                res[i]+=cnt;
            }
        }
        else{
            int tot=curPos.size();
            temp_res[0]+=curPos.size();
            while(tot>1){
                int l=1,r=N;
                int min_dist=N;
                int min_group=1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    int cur_group=1,last_pos=0;
                    for(int j=1;j<curPos.size();j++){
                        if(curPos[j]-curPos[last_pos]>mid){
                            cur_group++;
                            last_pos=j;
                        }
                    }
                    if(cur_group>=tot){
                        l=mid+1;
                    }else{
                        min_group=cur_group;
                        min_dist=mid;
                        r=mid-1;
                    }
                }
                temp_res[min_dist]-=tot;
                temp_res[min_dist]+=min_group;
                tot=min_group;
            }
        }
    }
    for(int i=1;i<=N;i++){
        temp_res[i]+=temp_res[i-1];
        cout<<res[i]+temp_res[i]<<endl;
    }
}