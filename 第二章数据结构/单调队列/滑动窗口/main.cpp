#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],dque[N];
int q_front,q_tail;
void init(){
    q_front=0;
    q_tail=-1;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    init();
    //ว๓ื๎ะก
    for(int i=0;i<n;i++){
        if(q_front<=q_tail&&i-k+1>dque[q_front])
            q_front++;
        while(q_front<=q_tail&&a[dque[q_tail]]>=a[i])
            q_tail--;
        dque[++q_tail]=i;
        if(i>=k-1)
            cout<<a[dque[q_front]]<<' ';
    }
    cout<<endl;
    init();
    for(int i=0;i<n;i++){
        if(q_front<=q_tail&&i-k+1>dque[q_front])
            q_front++;
        while(q_front<=q_tail&&a[dque[q_tail]]<=a[i])
            q_tail--;
        dque[++q_tail]=i;
        if(i>=k-1)
            cout<<a[dque[q_front]]<<' ';
    }
    cout<<endl;
    return 0;
}
