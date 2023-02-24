#include <iostream>

using namespace std;
const int N=1e5+10;
int st[N];
int top;
void init(){
    top=-1;
}
void push(int x){
    st[++top]=x;
}
void pop(){
    if(top!=-1)
        top--;
}
bool isEmpty(){
    return top==-1;
}
int query(){
    return st[top];
}
int main()
{
    int m,x;
    init();
    cin>>m;
    while(m--){
        string op;
        cin>>op;
        if(op=="push"){
            cin>>x;
            push(x);
        }else if(op=="pop"){
            pop();
        }else if(op=="query"){
            x=query();
            cout<<x<<endl;
        }else{
            bool res=isEmpty();
            cout<<(res==true?"YES":"NO")<<endl;
        }
    }
    return 0;
}
