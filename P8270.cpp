#include<bits/stdc++.h>
using namespace std;
string s,t;
const int N=1e5+10;
int q,s1[26],t1[26];
bool dp[1<<20];
int main()
{
    cin>>s>>t;
    cin>>q;
    //预处理 1位
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<s.length();j++)
            if(i+'a'==s[j]) s1[i]++;
        for(int j=0;j<t.length();j++)
            if(i+'a'==t[j]) t1[i]++;
        dp[1<<i]=(s1[i]==t1[i]);
    }
    //预处理 2位
    for(int i=0;i<18;i++)
    {
        for(int j=i+1;j<18;j++)
        {
            string temp1,temp2;
            for(int k=0;k<s.length();k++)
                if(s[k]==i+'a'||s[k]==j+'a')
                    temp1+=s[k];
            for(int k=0;k<t.length();k++)
                if(t[k]==i+'a'||t[k]==j+'a')
                    temp2+=t[k];
            dp[1<<i+1<<j]=(temp1==temp2);
        }
    }
    //dp
    for(int i=1;i<=(1<<18);i++)
    {
        dp[]
    }
}