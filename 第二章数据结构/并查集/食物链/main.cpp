#include<iostream>
using namespace std;
const int N=2e5;
int p[N];
int n,k,d,x,y,res;
//记x[n],x[n+n],x[n+n+n]分别为同类域，捕食域和天敌域
int findRoot(int x){
    if(p[x]!=x)
        p[x]=findRoot(p[x]);
    return p[x];
}
void mergeRoot(int x,int y){
    p[findRoot(x)]=findRoot(y);
}
int main(){
    res=0;
    cin>>n>>k;
    for(int i=1;i<=3*n;i++)
        p[i]=i;
    while(k--){
        cin>>d>>x>>y;
        if(x>n||y>n)
            res++;
        else{
            if(d==1){
                if(findRoot(x+n)==findRoot(y)||findRoot(x+n+n)==findRoot(y))
                    res++;
                else{
                    mergeRoot(x,y);
                    mergeRoot(x+n,y+n);
                    mergeRoot(x+n+n,y+n+n);
                }
            }else{
                if(findRoot(x)==findRoot(y)||findRoot(y+n)==findRoot(x))
                    res++;
                else{
                    mergeRoot(x+n,y);//x的捕食域和y同类
                    mergeRoot(y+n+n,x);//y的天敌域与x同类
                    mergeRoot(x+n+n,y+n);//依据题目得 x的天敌域和y的捕食域同类
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
