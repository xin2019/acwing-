#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main(){
    int n,m,temp;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            a[i]=temp;
        }
        for(int i=0;i<m;i++){
            cin>>temp;
            b[i]=temp;
        }
        int i,j;
        for(i=0,j=0;j<m;j++){
            if(a[i]==b[j]){
                i++;
            }
            if(i==n){
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(i!=n){
            cout<<"No"<<endl;
        }

    }
    return 0;
}
