#include<iostream>
using namespace std;
const int N=1010;
int a[N][N];
long long S[N][N];
int main(){
    int n,m,q,x1,y1,x2,y2,temp;
    while(cin>>n>>m>>q){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>temp;
                a[i][j]=temp;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
            }
        }
        while(q--){
            cin>>x1>>y1>>x2>>y2;
            cout<<S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1]<<endl;
        }
    }
    return 0;
}
