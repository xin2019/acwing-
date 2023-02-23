#include<iostream>
using namespace std;
const int N=1e6+10;
int val[N],ne[N];
int head,idx;
void init(){
    head=-1;
    idx=0;
}
void addToHead(int x){
    val[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void addK(int k,int x){
    val[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void removeK(int k){
    ne[k]=ne[ne[k]];
}
int main(){
    int m,k,x;
    char op;
    while(cin>>m){

        init();
        while(m--){
            cin>>op;
            switch(op){
        case 'H':
            cin>>x;
            addToHead(x);
            break;
        case 'D':
            cin>>k;
            if(!k) head=ne[head];
            else removeK(k-1);
            break;
        default:
            cin>>k>>x;
            addK(k-1,x);
            }
        }
        for(int i=head;i!=-1;i=ne[i])
            cout<<val[i]<<' ';
        cout<<endl;
    }
    return 0;
}
