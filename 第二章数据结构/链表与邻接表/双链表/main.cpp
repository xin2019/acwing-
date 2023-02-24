#include<iostream>
using namespace std;
const int N=1e4+10;
int val[N],r[N],l[N];
int idx;
void init(){
    l[1]=0;
    r[0]=1;
    idx=2;
}
//在k后面插入元素
void addK(int k,int x){
    val[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx++;
}
//删除第k个元素
void removeK(int k){
    l[r[k]]=l[k];
    r[l[k]]=r[k];
}
int main(){
    ios::sync_with_stdio(false);
    int m,x,k;
    init();
    cin>>m;
    while(m--){

        string op;
        cin>>op;
        if(op=="L"){
            cin>>x;
            addK(0,x);
        }else if(op=="R"){
            cin>>x;
            addK(l[1],x);
        }else if(op=="D"){
            cin>>k;
            removeK(k+1);
        }else if(op=="IL"){
            cin>>k>>x;
            addK(l[k+1],x);
        }else{
            cin>>k>>x;
            addK(k+1,x);
        }

    }
    for(int i=r[0];i!=1;i=r[i]){
        cout<<val[i]<<' ';
    }
    cout<<endl;
    return 0;
}
