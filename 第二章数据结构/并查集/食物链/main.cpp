#include<iostream>
using namespace std;
const int N=2e5;
int p[N];
int n,k,d,x,y,res;
//��x[n],x[n+n],x[n+n+n]�ֱ�Ϊͬ���򣬲�ʳ��������
int findRoot(int x){
    if(p[x]!=x)
        p[x]=findRoot(p[x]);
    return p[x];
}
void mergeRoot(int x,int y){
    p[findRoot(x)]=findRoot(y);
}
int main(){
    res=0;
    cin>>n>>k;
    for(int i=1;i<=3*n;i++)
        p[i]=i;
    while(k--){
        cin>>d>>x>>y;
        if(x>n||y>n)
            res++;
        else{
            if(d==1){
                if(findRoot(x+n)==findRoot(y)||findRoot(x+n+n)==findRoot(y))
                    res++;
                else{
                    mergeRoot(x,y);
                    mergeRoot(x+n,y+n);
                    mergeRoot(x+n+n,y+n+n);
                }
            }else{
                if(findRoot(x)==findRoot(y)||findRoot(y+n)==findRoot(x))
                    res++;
                else{
                    mergeRoot(x+n,y);//x�Ĳ�ʳ���yͬ��
                    mergeRoot(y+n+n,x);//y���������xͬ��
                    mergeRoot(x+n+n,y+n);//������Ŀ�� x��������y�Ĳ�ʳ��ͬ��
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
