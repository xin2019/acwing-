#include<iostream>
#include<cstring>
using namespace std;
const int M=2e5+10,N=510;
int g[N][N],dist[N];
int n,m,a,c,b;
bool st[N];
const int INF=0x3f3f3f3f;
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t]))
                t=j;
        }
        st[t]=true;
        if(i&&dist[t]==INF)
            return INF;
        if(i)
            res+=dist[t];
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    memset(g,0x3f,sizeof g);
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==INF)
        cout<<"impossible"<<endl;
    else
        cout<<t<<endl;
    return 0;
}
