#include<bits/stdc++.h>
using namespace std;
int N,child[10005],days;
int main()
{
    cin>>N;
    for(int i=1;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        child[a]++;
        child[b]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(i!=1)child[i]--;
        int num=1;
        while(num<=child[i])
        {
            num*=2;
            days++;
            //cout<<days<<" ";
        }
        days+=child[i];
    }
    cout<<days;
}