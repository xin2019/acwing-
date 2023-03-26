#include<iostream>
#include<cstring>
using namespace std;
const int N=210;
const int M=2e4+10;
int n,m,k,a,c,b;
int dist[N][N];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j)
                dist[i][j]=0;
            else
                dist[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    floyd();
    for(int i=0;i<k;i++){
        cin>>a>>b;
        if(dist[a][b] > 0x3f3f3f3f/2)
            cout<<"impossible"<<endl;
        else
            cout<<dist[a][b]<<endl;
    }
    return 0;
}
