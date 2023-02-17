#include<iostream>
#include<string.h>
using namespace std;
const int N=105;
int a[N],s[N];
int main(){
    int n;
    while(cin>>n){
        memset(a,0,N*sizeof(int));
        memset(a,0,N*sizeof(int));
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            a[i]=temp;
        }
        int res=1;
        for(int i=0,j=0;i<n;i++){
            s[a[i]]++;
            while(j<i&&s[a[i]]>1){
                s[a[j]]--;
                j++;
            }
            res=max(res,i-j+1);
        }
        cout<<res<<endl;
    }
    return 0;
}
