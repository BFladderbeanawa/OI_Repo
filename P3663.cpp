#include<cstdio>
int c[110][110],q[210][2];
bool f[110][110],b[110][110];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int bfs(int ii,int jj)
{
    int q1=0,q2=1,sum=0;
    b[ii][jj]=1;
    q[0][0]=ii;
    q[0][1]=jj;
    while(q1!=q2)
    {
        int x=q[q1][0],y=q[q1][1];
        if(++q1==210)q1=0;
        sum+=f[x][y];
        for(int i=0;i<=3;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(!(c[x][y]&1<<i)&&!b[xx][yy])
            {
                b[xx][yy]=1;
                q[q2][0]=xx;
                q[q2][1]=yy;
                if(++q2==210)q2=0;
            }
        }
    }
    return sum;
}
int main()
{
    int n,k,r,x1,x2,y1,y2,ans=0;
    scanf("%d%d%d",&n,&k,&r);
    for(int i=1;i<=n;i++)
    {
        c[i][1]|=4;
        c[i][n]|=1;
        c[1][i]|=8;
        c[n][i]|=2;
    }
    for(int i=1;i<=r;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=0;i<=3;i++)
            if(dx[i]+x1==x2&&dy[i]+y1==y2)
            {
                c[x1][y1]|=1<<i;
                c[x2][y2]|=1<<(i+2&3);
            }
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&x1,&y1);
        f[x1][y1]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!b[i][j])
            {
                int t=bfs(i,j);
                ans+=t*(k-t);
            }
    printf("%d\n",ans>>1);
}