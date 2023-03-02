#include<iostream>
using namespace std;
const int N=1e5+10;
int h[N];
int len;
int n,m;
/*
    小顶堆
*/
//上移操作
void up(int i){
    while(i/2&&h[i/2]>h[i]){
        swap(h[i/2],h[i]);
        i/=2;
    }
}
//下移
void down(int u){
    int t=u;
    if(u*2<=len&&h[u*2]<h[t])
        t=u*2;
    if(u*2+1<=len&&h[u*2+1]<h[t])
        t=u*2+1;
    if(t!=u){
        swap(h[u],h[t]);
        down(t);
    }
}
//插入一个数
void insertItem(int val){
    h[++len]=val;
    up(len);
}
//求集合中的最小值
int getMin(){
    return h[1];
}
//删除最小值
void removeMin(){
    swap(h[1],h[len--]);
    down(1);
}
//删除任意一个元素
void removeItem(int k){
    h[k]=h[len--];
    down(k);up(k);//这两个只会执行其中一个
}
//修改任意一个元素
void alterItem(int k,int val){
    h[k]=val;
    down(k);up(k);//这两个只会执行其中一个
}
int main(){

    cin>>n>>m;
    len=n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=n/2;i;--i){
        down(i);
    }
    while(m--){
        cout<<h[1]<<' ';
        h[1]=h[len--];
        down(1);
    }
    cout<<endl;
    return 0;
}
