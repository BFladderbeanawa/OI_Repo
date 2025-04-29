#include<bits/stdc++.h>
using namespace std;
int N,K;
char a[105][15];
bool vis[105][15];
int cnt;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void dfs(int x,int y,char s)
{
    //cout<<"1";
    vis[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=0&&xx<N&&yy>=0&&yy<10&&a[xx][yy]==s&&!vis[xx][yy])
        {
            dfs(xx,yy,s);
        }
    }
}
void fall()
{
    for(int i=N-1; i>=0; i--)
    {
		for(int j=0; j<10; j++)
        {
			if(a[i][j]=='0') {
				int k=i;
				while(a[k][j]=='0'&&k>=0) {
					k--;
				}
				if(k!=i&&k>=0&&a[k][j]!='0') {
					a[i][j]=a[k][j];
                    // cout<<a[i][j]<<" "<< a[k][j]<<endl;
					a[k][j]='0';
				}
			}
		}
	}
}
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++) {
		for(int j=0; j<10; j++) {
			cin>>a[i][j];
		}
	}
    bool flag =true;
    while(flag)
    {
        flag=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(a[i][j]!='0')
                {
                    cnt=0;
                    memset(vis,false,sizeof(vis));
                    dfs(i,j,a[i][j]);
                    // cout<<cnt<<"!"<<endl;
                    if(cnt>=K)
                    {
                        flag=true;
                        for(int ii=0;ii<N;ii++)
                        {
                            for(int jj=0;jj<10;jj++)
                            {
                                if(vis[ii][jj])
                                {
                                    a[ii][jj]='0';
                                }
                            }
                        }
                        
                    }
                    
                }
            }
        }
        if(flag)
        {
            fall();
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}