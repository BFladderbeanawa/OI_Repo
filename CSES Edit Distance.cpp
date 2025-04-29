#include<bits/stdc++.h>
using namespace std;
string n,m;
int C[26],ans=0;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n.size();i++)
	{
		C[n[i]-'A']++;
	}
	for(int i=0;i<m.size();i++)
	{
		C[m[i]-'A']++;
	}
	for(int i=0;i<26;i++)
	{
		if(C[i]==1) ans++;
	}
	ans=ans/2+ans%2;
	cout<<ans;
}