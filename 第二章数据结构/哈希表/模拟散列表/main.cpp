#include <iostream>
#include<cstring>
using namespace std;
const int N=100003;

//拉链法
int idx,e[N],ne[N],h[N];

void insertX(int x){
    int k=(x%N+N)%N;
   // int head=h[k];
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool findX(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==x)
            return true;
    }
    return false;
}

//开放地址法
const int null =0x3f3f3f3f;

void insertX2(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null){
        k++;
        if(k==N)
            k=0;
    }
    h[k]=x;
}
bool findX2(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null){
        if(h[k]==x)
            return true;
        k++;
    }
    return false;
}

int main1()
{
    int n,x;
    memset(h,-1,sizeof(h));
    cin>>n;
    char op;
    while(n--){
        cin>>op>>x;
        if(op=='I'){
            insertX(x);
        }else{
            cout<<(findX(x)==true?"Yes":"No")<<endl;
        }
    }
    return 0;
}

int main(){

    int n;
    memset(h,0x3f,sizeof(h));
    cin>>n;
    while(n--){
        char op;
        int x;
        cin>>op>>x;
        if(op=='I')
        {
            insertX2(x);
        }else{
            cout<<(findX2(x)==true?"Yes":"No")<<endl;
        }
    }
    return 0;
}
