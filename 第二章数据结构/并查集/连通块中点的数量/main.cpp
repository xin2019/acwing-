#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],cnt[N];//p[n]记录父节点，cnt[n]记录以n为根的联通集的个数
int findRoot(int x){
    if(x != p[x])
        p[x] = findRoot(p[x]);
    return p[x];
}
void mergeRoot(int a,int b){
    //这两个语句不能颠倒，如果颠倒则先改变了a的根节点，此时cnt[a]=cnt[b]，那再执行cnt加语句的时候，相当于直接成以2倍
    cnt[findRoot(b)]+=cnt[findRoot(a)];
    p[findRoot(a)]=findRoot(b);
}
int main(){
    int m,n;
    string s;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cnt[i]=1;
        p[i]=i;
    }
    while(m--){
        cin>>s;
        if(s=="C"){
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b){
                mergeRoot(a,b);
            }
        }else if(s=="Q1"){
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            cout<<(a==b?"Yes":"No")<<endl;
        }else{
            cin>>a;
            cout<<cnt[findRoot(a)]<<endl;
        }
    }
    return 0;
}
