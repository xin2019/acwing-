#include<iostream>
#include<cstring>
using namespace std;
const int N=510,M=1e4+10;
int dist[N],backup[N];
int n,m,k;
struct Edge{
    int a,b,w;
}edges[M];
int bellman_ford(int k){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++){
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2)
        return -1;
    return dist[n];
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    int t=bellman_ford(k);
    if(t==-1)
        cout<<"impossible"<<endl;
    else
        cout<<t<<endl;
    return 0;
}
