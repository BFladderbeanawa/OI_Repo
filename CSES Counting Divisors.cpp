#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,cnt=0;
        cin>>a;
        for(int j=1;j<=sqrt(a);j++)
        {
            if(a%j==0)
            {
                cnt++;
                if(a/j!=j)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}