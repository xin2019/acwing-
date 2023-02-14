#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int m,n,l,r,temp;
    long long S[100010];
    int a[100010];
    while(cin>>n>>m){
        memset(S,0,sizeof(int)*n);
        memset(a,0,sizeof(int)*n);
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            a[i]=temp;
        }
        for(int i=1;i<=n;i++)
            S[i]=S[i-1]+a[i];
        while(m--){
            cin>>l>>r;
            cout<<S[r]-S[l-1]<<endl;
        }
    }
    return 0;
}
