#include<bits/stdc++.h>
using namespace std;
int N,ans=0;
bool mm[3000][3000];
const int dx[]={0,0,1,-1,0},dy[]={1,-1,0,0,0};
void dfs(int x,int y)
{
    int flag=0,tempx,tempy;
    if(!mm[x][y]) return;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(mm[xx][yy])
        {
            flag++;
        }
        else
        {
            tempx=xx,tempy=yy;
        }
    }
    if(flag!=3)
    {
        return;
    }
    else
    {
        mm[tempx][tempy]=true;
        ans++;
        for(int j=0;j<4;j++)
        {
            dfs(tempx+dx[j],tempy+dy[j]);
        }
    }

}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        x+=1000,y+=1000;
        if(mm[x][y]) ans--;
        mm[x][y]=true;
        for(int j=0;j<5;j++)
        {
            int xx=x+dx[j];
            int yy=y+dy[j];
            dfs(xx,yy);
        }
        cout<<ans<<endl;
    }
}