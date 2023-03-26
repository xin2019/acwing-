#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=2e5+10,INF=0x3f3f3f3f;
int n,m,a,b,w;
int p[N];
struct Edge{
    int a,b,w;
    bool operator< (const Edge& W)const{
        return w<W.w;
    }
}edges[M];
int findRoot(int a){
    if(p[a]!=a)
        p[a]=findRoot(p[a]);
    return p[a];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    sort(edges,edges+m);
    for(int i=1;i<=n;i++)
        p[i]=i;
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edges[i].a;
        int b=edges[i].b;
        int w=edges[i].w;
        a=findRoot(a);
        b=findRoot(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1)
        cout<<"impossible"<<endl;
    else
        cout<<res<<endl;
    return 0;
}
