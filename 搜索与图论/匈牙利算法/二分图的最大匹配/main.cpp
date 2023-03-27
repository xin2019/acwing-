#include<iostream>
#include<cstring>
using namespace std;
const int N=510,M=2e5+10;
int h[N],e[M],ne[M],idx;
int n1,n2,m,a,b;
bool st[N];
int match[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool findMatch(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(!match[j]||findMatch(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    while(m--){
        cin>>a>>b;
        add(a,b);
    }
    int res=0;
    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof st);
        if(findMatch(i))
            res++;
    }
    cout<<res<<endl;
    return 0;
}
