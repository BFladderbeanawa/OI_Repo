#include<bits/stdc++.h>
using namespace std;
int N;
char graph[30][30][3];
char board[5][5];
int bi,bj;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool vis[30][30];
int ans;
int cnt=0;
bool board_control(int x,int y)
{
    if(board[graph[x][y][1]-'0'][graph[x][y][2]-'0']!='0')
    {
        board[graph[x][y][1]-'0'][graph[x][y][2]-'0']=graph[x][y][0];
    }
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(board[i][j]=='M'&&board[i][j+1]=='O'&&board[i][j+2]=='O')
            {
                return true;
            }
            else if(board[i][j]=='M'&&board[i+1][j]=='O'&&board[i+2][j]=='O')
            {
                return true;
            }
            else if(board[i][j]=='M'&&board[i+1][j+1]=='O'&&board[i+2][j+2]=='O')
            {
                return true;
            }
            else if(board[i][j]=='O'&&board[i][j+1]=='O'&&board[i][j+2]=='M')
            {
                return true;
            }
            else if(board[i][j]=='O'&&board[i+1][j]=='O'&&board[i+2][j]=='M')
            {
                return true;
            }
            else if(board[i][j]=='O'&&board[i+1][j+1]=='O'&&board[i+2][j+2]=='M')
            {
                return true;
            }
            else{
                return false;
            }
        }
    }
}
void dfs(int x,int y)
{
    if(x<=0||x>N||y<=0||y>N||vis[x][y]||graph[x][y][0]=='#')
    {
        return;
    }
    vis[x][y]=true;
    if(graph[x][y][0]=='M'||graph[x][y][0]=='O')
    {
        if(board_control(x,y))
        {
            ans++;
        }
    }
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        dfs(xx,yy);
    }
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>graph[i][j][0]>>graph[i][j][1]>>graph[i][j][2];
            if(graph[i][j][0]=='B')
            {
                bi=i;
                bj=j;
            }
        }
    }
    memset(board,'0',sizeof(board));
    dfs(bi,bj);
    cout<<ans;
}