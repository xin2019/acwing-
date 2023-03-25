#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10,M=2*N;
int n,ans=N;
int h[N],ne[M],e[M],idx;
bool state[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u){
    state[u]=true;
    int sum=1,res=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=ne[i];
        if(!state[j]){
            int s=dfs(j);
            res=max(res,s);
            sum+=s;
        }
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}
int main(){
    memset(h,-1,sizeof h);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
