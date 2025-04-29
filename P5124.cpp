#include <iostream>
#include <cstdio>
using namespace std;

int a[1001000] , ans[1001000];

int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	for(int i = 1;i <= n;i ++){
		int maxn = 0; 
		for(int j = i;j < min(i+k,n+1);j ++){ 
			maxn = max( maxn , a[j] );
			ans[j] = max( ans[j] , ans[i-1] + maxn * (j-i+1) );
		}
	}
	cout << ans[n] << endl; 
	return 0;
}