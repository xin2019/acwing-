#include<iostream>
#include<cstring>
using namespace std;
const int N=100003;
const int null=0x3f3f3f3f;
int h[N],idx,e[N],ne[N];

//拉链法
void insertLink(int x){
    int k=(x%N+N)%N;
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool findLinkX(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==x)
            return true;
    }
    return false;
}
int main1(){
    int n;
    cin>>n;
    memset(h,-1,sizeof(h));
    while(n--){
        char op;
        int x;
        cin>>op>>x;
        if(op=='I'){
            insertLink(x);
        }else{
            cout<<(findLinkX(x)?"Yes":"No")<<endl;
        }
    }
    return 0;
}
//开放定址法
int findK(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null&&h[k]!=x){
        k++;
        if(k==N)
            k=0;
    }
    return k;
}
int main(){
    int n;
    cin>>n;
    memset(h,0x3f,sizeof(h));
    while(n--){
        char op;
        int x;
        cin>>op>>x;
        if(op=='I'){
            h[findK(x)]=x;
        }else{
            cout<<(h[findK(x)]==null?"No":"Yes")<<endl;
        }
    }
    return 0;
}
