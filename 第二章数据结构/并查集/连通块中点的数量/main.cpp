#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],cnt[N];//p[n]��¼���ڵ㣬cnt[n]��¼��nΪ������ͨ���ĸ���
int findRoot(int x){
    if(x != p[x])
        p[x] = findRoot(p[x]);
    return p[x];
}
void mergeRoot(int a,int b){
    //��������䲻�ܵߵ�������ߵ����ȸı���a�ĸ��ڵ㣬��ʱcnt[a]=cnt[b]������ִ��cnt������ʱ���൱��ֱ�ӳ���2��
    cnt[findRoot(b)]+=cnt[findRoot(a)];
    p[findRoot(a)]=findRoot(b);
}
int main(){
    int m,n;
    string s;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cnt[i]=1;
        p[i]=i;
    }
    while(m--){
        cin>>s;
        if(s=="C"){
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b){
                mergeRoot(a,b);
            }
        }else if(s=="Q1"){
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            cout<<(a==b?"Yes":"No")<<endl;
        }else{
            cin>>a;
            cout<<cnt[findRoot(a)]<<endl;
        }
    }
    return 0;
}
