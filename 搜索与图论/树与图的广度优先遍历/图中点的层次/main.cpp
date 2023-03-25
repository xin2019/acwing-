#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int q[N],h[N],e[N],ne[N],idx,n,m,hh,tt,d[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int bfs(int u){
    d[u]=0;
    tt=hh=0;
    q[tt++]=u;
    while(hh<=tt){
        int t=q[hh++];
        if(t==n)
            return d[n];
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(d[j]==-1){
                d[j]=d[t]+1;
                q[tt++]=j;
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>m;
    memset(d,-1,sizeof d);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs(1)<<endl;
    return 0;
}
