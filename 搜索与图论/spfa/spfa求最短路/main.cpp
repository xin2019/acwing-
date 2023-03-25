#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10;
int h[N],dist[N],idx,ne[N],e[N],w[N];
int n,m,a,c,b;
bool st[N];
void add(int a,int b,int c){
    w[idx]=c;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    st[1]=true;
    queue<int> que;
    que.push(1);
    while(que.size()){
        int t = que.front();
        que.pop();
        for(int i = h[t]; ~i ;i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    que.push(j);
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i ++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t=spfa();
    if(t == -1)
        cout<<"impossible"<<endl;
    else
        cout<<t<<endl;
    return 0;
}
