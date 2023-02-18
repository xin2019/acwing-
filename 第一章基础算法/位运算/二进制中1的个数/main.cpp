#include <iostream>
const int N=1e6+10;
using namespace std;
int a[N];
int lowbit(int x){
    return x&-x;
}
int main()
{
    int n,temp;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>temp;
            a[i]=temp;
        }
        for(int i=0;i<n;i++){
            temp=a[i];
            int res=0;
            while(temp){
                    res+=1;
                temp-=lowbit(temp);

            }
            cout<<res<<' ';
        }
        cout<<endl;
    }
    return 0;
}
