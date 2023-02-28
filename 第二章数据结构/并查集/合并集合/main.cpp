#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N];
int findRoot(int x){
    if(x!=p[x])
        p[x]=findRoot(p[x]);
    return p[x];
}
void mergeRoot(int a,int b){
    p[findRoot(a)]=findRoot(b);
}
int main(){
    int n,m;
    int a,b;
    cin>>n>>m;
    char ch;
    for(int i=1;i<=n;i++)
        p[i]=i;
    while(m--){
        cin>>ch;
        if(ch=='M'){
            cin>>a>>b;
            mergeRoot(a,b);
        }else{
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            if(a==b)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
