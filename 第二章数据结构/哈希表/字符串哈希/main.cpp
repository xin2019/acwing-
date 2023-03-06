#include<iostream>
using namespace std;
const int N=1e5+10;
const int M=131;
typedef unsigned long long ULL;
ULL p[N],h[N];
char str[N];
ULL getHash(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int n,m;
int main(){
    cin>>n>>m>>str+1;
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*M;
        h[i]=h[i-1]*M+str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(getHash(l1,r1)==getHash(l2,r2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
