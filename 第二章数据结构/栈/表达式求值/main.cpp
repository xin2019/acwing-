#include<iostream>
using namespace std;
const int N=1e5+10;
int st[N];//用于存储后缀表达式求值的整数值的栈
char op[N];//用于存放中缀转后缀表达式时候的操作符的栈
int st_top,op_top;
void init(){
    st_top=-1;
    op_top=-1;
}
//将中缀表达式转为后缀表达式
string toSuffix(string& s){
    string suffix;
    char ch;
    for(int i=0;i<s.size();i++){
        ch=s[i];
        if(ch>='0'&&ch<='9'){
            suffix.push_back(ch);
        }else if(ch=='+'||ch=='-'){
            while(op_top>-1&&(op[op_top]=='+'||op[op_top]=='-'||op[op_top]=='*'||op[op_top]=='/'))
                suffix.push_back(op[op_top--]);
            op[++op_top]=ch;
        }else if(ch=='*'||ch=='/'){
            while(op_top>-1&&(op[op_top]=='*'||op[op_top]=='/'))
                suffix.push_back(op[op_top--]);
            op[++op_top]=ch;
        }else if(ch=='('){
            op[++op_top]=ch;
        }else{
            while(op_top>-1&&op[op_top]!='('){
                suffix.push_back(op[op_top--]);
            }
            op_top--;
        }
    }
    while(op_top>-1){
        suffix.push_back(op[op_top--]);
    }

    return suffix;
}
//后缀表达式求值
int caculate(string& s){
    int sum=0;
    int a,b;
    char ch;
    for(int i=0;i<s.size();i++){
        ch=s[i];
        if(!(ch>='0'&&ch<='9')){
            switch(ch){
        case '+':
            b=st[st_top--];
            a=st[st_top--];
            sum=a+b;
            st[++st_top]=sum;
            break;
        case '-':
            b=st[st_top--];
            a=st[st_top--];
            sum=a-b;
            st[++st_top]=sum;
            break;
        case '*':
            b=st[st_top--];
            a=st[st_top--];
            sum=a*b;
            st[++st_top]=sum;
            break;
        case '/':
            b=st[st_top--];
            a=st[st_top--];
            sum=a/b;
            st[++st_top]=sum;
            break;
            }
        }else{
            st[++st_top]=ch-'0';
        }
    }
    return st[st_top];
}
int main(){
    string s,suffix;
    init();
    cin>>s;
    suffix=toSuffix(s);
    cout<<caculate(suffix)<<endl;
    return 0;
}
