#include<iostream>
using namespace std;
const int N=10;
int n;
int state[N],path[N];
void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++){
            cout<<path[i]<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!state[i]){
            state[i]=1;
            path[u]=i;
            dfs(u+1);
            state[i]=0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}
