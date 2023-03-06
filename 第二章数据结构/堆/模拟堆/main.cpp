#include<iostream>
using namespace std;
const int N=1e5+10;
int h[N],hp[N],ph[N];
int heapSize;
void swap_heap(int i,int j){
    swap(ph[hp[i]],ph[hp[j]]);

    swap(hp[i],hp[j]);
    swap(h[i],h[j]);
}
void up(int i){
    while(i/2&&h[i/2]>h[i]){
        swap_heap(i/2,i);
        i/=2;
    }
}
void down(int i){
    int t=i;
    if(i*2<=heapSize&&h[i*2]<h[t])
        t=i*2;
    if(i*2+1<=heapSize&&h[i*2+1]<h[t])
        t=i*2+1;
    if(t!=i){
        swap_heap(t,i);
        down(t);
    }
}
//插入一个数
void insertItem(int x){
    h[++heapSize]=x;
    up(heapSize);
}
//获得最小值
int getMin(){
    return h[1];
}
//删除最小值
void removeMin(){
    h[1]=h[heapSize--];
    down(1);
}
//删除第k个插入的数
void removeK(int k){
    int i=hp[k];
    hp[i]=hp[heapSize--];
    down(i);
    up(i);
}
//修改第k个数
void alterK(int k,int x){
    int i=hp[k];
    h[i]=x;
    up(i);
    down(i);
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        string op;
        int k,x;
        cin>>op;
        if(op=="I"){
            cin>>x;
            insertItem(x);
        }else if(op=="PM"){
            cout<<getMin()<<endl;
        }else if(op=="DM"){
            removeMin();
        }else if(op=="D"){
            cin>>k;
            removeK(k);
        }else{
            cin>>k>>x;
            alterK(k,x);
        }
    }
    return 0;
}
