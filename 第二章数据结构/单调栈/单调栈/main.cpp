#include<iostream>
using namespace std;
const int N=1e5+10;
int st[N],que[N];
int q_front,q_tail,top;
//使用队列方法的初始化
void init_que(){
    q_front=0;
    q_tail=-1;
}
//使用单调栈方法的初始化
void init_stack(){
    top=-1;
}
//队列的基本操作,队尾插入
void push_que(int x){
    que[++q_tail]=x;
}
void pop_que(){
    ++q_front;
}
int query_que(){
    if(q_front<=q_tail)
        return que[q_front];
    return INT_MAX;
}
bool empty_que(){
    return q_front>q_tail;
}
//栈的基本操作
void push_stack(int x){
    st[++top]=x;
}
void pop_stack(){
    if(top>-1)
        --top;
}
int query_stack(){
    return st[top];
}
bool empty_stack(){
    return top==-1;
}
//使用队列的方式
int main_que(){
    int n,temp;
    init_que();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(!empty_que()){
            if(q_front<=q_tail&&temp<query_que()){
                pop_que();
                cout<<"-1 ";
                push_que(temp);
            }else{
                cout<<query_que()<<' ';
            }
        }else{
            cout<<"-1 ";
            push_que(temp);
        }
    }
    cout<<endl;
    return 0;
}
//使用单调栈方式
int main(){
    int n,temp;
    cin>>n;
    init_stack();
    for(int i=0;i<n;i++){
        cin>>temp;
        while(top>-1&&temp<=st[top]) top--;
        if(top!=-1)
            cout<<st[top]<<' ';
        else
            cout<<"-1 ";
        st[++top]=temp;
    }
    return 0;
}
