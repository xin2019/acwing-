#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m,heapSize;
int h[N];
//小顶堆
void down(int u){
    int t=u;
    if(u*2<=heapSize&&h[u*2]<h[t])
        t=u*2;
    if(u*2+1<=heapSize&&h[u*2+1]<h[t])
        t=u*2+1;
    if(u!=t)
    {

        swap(h[u],h[t]);
        down(t);
    }
}
int main(){
    cin>>n>>m;
    heapSize=n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=n/2;i;i--)
        down(i);
    while(m--){
        cout<<h[1]<<' ';
        h[1]=h[heapSize--];
        down(1);
    }
    cout<<endl;
    return 0;
}
