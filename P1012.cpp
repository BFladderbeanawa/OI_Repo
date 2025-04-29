#include<bits/stdc++.h>
using namespace std;
int n;
string arr[25];
bool cmp(string a, string b)
{
    if(a.length()>b.length())
    {
        for(int i=b.length();i<a.length();i++)
        {
            b+=b[i-1];
        }
    }
    else
    {
        for(int i=a.length();i<b.length();i++)
        {
            a+=a[i-1];
        }
    }
    // cout<<a<<" "<<b;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>b[i])
        {
            return true;
        }
        if(a[i]<b[i])
        {
            return false;
        }
    }
    return false;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, cmp);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    // cout<<cmp("7","846");
}