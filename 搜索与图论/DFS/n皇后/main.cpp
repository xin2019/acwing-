#include<iostream>
using namespace std;
const int N=20;
int dg[N],udg[N],col[N];
char g[N][N];
int n;
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++)
            cout<<g[i]<<endl;
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(!col[i]&&!dg[u+i]&&!udg[i-u+n]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[i-u+n]=1;
            dfs(u+1);
            col[i]=dg[u+i]=udg[i-u+n]=0;
            g[u][i]='.';
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0);
    return 0;
}
