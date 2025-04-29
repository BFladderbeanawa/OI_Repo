#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,loc;
vector <int> k;
int main(){
    cin>>n;
    k.push_back(-1);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x>=k[k.size()-1])
        {
            k.push_back(x);
        }
        else{
            loc=upper_bound(k.begin(),k.end(),x)-k.begin();
            k[loc]=x;
        }
    }
    cout<<k.size()-1;
}