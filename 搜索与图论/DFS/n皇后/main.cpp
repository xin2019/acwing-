#include<iostream>
using namespace std;
const int N=20;
char g[N][N];
int col[N],dg[N],udg[N];
int n;
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++)
            cout<<g[i]<<endl;
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(!col[i]&&!dg[i+u]&&!udg[i-u+n]){
            g[u][i]='Q';
            col[i]=dg[i+u]=udg[i-u+n]=1;
            dfs(u+1);
            g[i][i]='.';
            col[i]=dg[i+u]=udg[i-u+n]=0;
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
