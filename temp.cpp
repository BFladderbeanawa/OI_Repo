#include<bits/stdc++.h>
using namespace std;
struct foo{
    int a,b;
}f[10];
bool cmp(foo x, foo y){
    return x.b<y.b;
}
int main(){
    f[1]={9,1},f[2]={10,0};
    sort(f+1,f+3,cmp);
    cout<<f[1].b;
}