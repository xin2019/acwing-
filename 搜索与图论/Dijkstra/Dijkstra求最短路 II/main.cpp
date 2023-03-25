#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;

int h[N],w[N],e[N],ne[N],idx,dist[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
  e[idx]=b;
  w[idx]=c;
  ne[idx]=h[a];
  h[a]=idx++;
}
int heap_dijstra(){
  memset(dist,0x3f,sizeof dist);
  dist[1]=0;
  priority_queue<PII,vector<PII>,greater<PII> > heap;
  heap.push({0,1});
  while(heap.size()){
    PII t=heap.top();
    heap.pop();
    int ver=t.second,distance=t.first;
    if(st[ver]) continue;
    if(ver==n) break;
    st[ver]=true;
    for(int i=h[ver];~i;i=ne[i]){
        int j=e[i];
        if(st[j]==false&&dist[j]>distance+w[i]){
            dist[j]=distance+w[i];
            heap.push({dist[j],j});
        }

    }
  }
  if(dist[n]==0x3f3f3f3f)
    return -1;
  return dist[n];
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<heap_dijstra()<<endl;
    return 0;
}
