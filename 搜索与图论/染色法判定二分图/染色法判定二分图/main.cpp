#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int h[N],e[2*N],ne[2*N],idx;
int n,m,a,b,c;
int color[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool dfs(int u,int c){
    color[u]=c;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!color[j]){
            if(!dfs(j,3-c))
                return false;
        }else if(color[j]==c)
            return false;
    }
    return true;
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag=false;
                break;
            }
        }
    }
    cout<<(flag?"Yes":"No")<<endl;
    return 0;
}
