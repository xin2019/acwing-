#include <iostream>

using namespace std;
const int N=1e5+10;
int ta,fr;
int qu[N];
void init(){
    ta=-1;
    fr=0;
}
void push(int x){
    qu[++ta]=x;
}
void pop()
{
    ++fr;
}
bool isEmpty(){
    return fr>ta;
}
int query(){
    if(fr<=ta)
    return qu[fr];
    return INT_MAX;
}
int main()
{
    int n,x;
    cin>>n;
    init();
    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            cin>>x;
            push(x);
        }else if(s=="empty"){
            cout<<(isEmpty()==true?"YES":"NO")<<endl;
        }else if(s=="pop"){
            pop();
        }else{
            cout<<query()<<endl;
        }
    }
    return 0;
}
