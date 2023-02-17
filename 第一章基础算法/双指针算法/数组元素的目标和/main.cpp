#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main(){
    int n,m,x,i,j,temp;
    while(cin>>n>>m>>x){
        for(i=0;i<n;i++){
           cin>>temp;
           a[i]=temp;
        }
        for(i=0;i<m;i++){
            cin>>temp;
            b[i]=temp;
        }
        for(i=0,j=m-1;i<n;i++){
            while(j>=0&&a[i]+b[j]>x)
                j--;
            if(a[i]+b[j]==x){
                cout<<i<<' '<<j<<endl;
                break;
            }
        }
        if(j<0){
            cout<<"²»´æÔÚ½â"<<endl;
        }
    }
    return 0;
}
