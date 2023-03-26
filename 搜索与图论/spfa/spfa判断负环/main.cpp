#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=2100,M=1e4+10;
int w[M],ne[M],e[M],idx,h[N],cnt[N],dist[N];
int n,m,a,b,c;
bool st[N];
void add(int a,int b,int c){
    w[idx]=c;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool spfa(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        que.push(i);
        st[i]=true;
    }
    while(que.size()){
        int t=que.front();
        que.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n)
                    return true;
                if(!st[j]){
                    st[j]=true;
                    que.push(j);
                }
            }
        }
    }
    return false;
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    if(spfa())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
