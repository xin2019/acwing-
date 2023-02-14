#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N];
int b[N];
long long S[N];
void insert(int l,int r,int c){
    b[l]+=c;
    b[r+1]-=c;
}
int main(){
    int m,n,l,r,c,temp;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            a[i]=temp;
        }
        //构造查分数组b[n]
        for(int i=1;i<=n;i++){
            insert(i,i,a[i]);
        }
        while(m--){
            cin>>l>>r>>c;
            insert(l,r,c);
        }
        for(int i=1;i<=n;i++){
            S[i]=S[i-1]+b[i];
        }
        for(int i=1;i<=n;i++)
            cout<<S[i]<<" ";
        cout<<endl;
    }
    return 0;
}
