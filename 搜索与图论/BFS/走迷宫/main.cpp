#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
typedef pair<int,int> PII;
PII prev[N][N],t,que[N*N];//prevÊä³öÂ·¾¶£¬µ¹Ðò
int tt,hh,n,m;
int g[N][N];
int d[N][N];
void dfs(){
    memset(d,-1,sizeof d);
    d[0][0]=0;
    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
    hh=tt=0;
    que[tt++]={0,0};
    while(hh<=tt){
        t=que[hh++];
        for(int i=0;i<4;i++){
            int a=t.first+dx[i];
            int b=t.second+dy[i];
            if(a>=0&&a<n&&b>=0&&b<m&&!g[a][b]&&d[a][b]==-1){
                d[a][b]=d[t.first][t.second]+1;
                prev[a][b]=t;
                que[tt++]={a,b};
            }
        }
    }
    int a=n-1,b=m-1;
    while(a||b){
        cout<<a<<' '<<b<<endl;
        t=prev[a][b];
        a=t.first,b=t.second;
    }
    cout<<d[n-1][m-1]<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    dfs();
    return 0;
}
