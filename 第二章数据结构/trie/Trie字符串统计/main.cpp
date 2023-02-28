#include<iostream>
using namespace std;
const int N=1e5+10;
int idx,cnt[N],son[N][26];
char str[N];
void Insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])
            son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])
            return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    char ch;
    cin>>n;
    while(n--){
        cin>>ch;
        if(ch=='I'){
            cin>>str;
            Insert(str);
        }else{
            cin>>str;
            cout<<query(str)<<endl;
        }
    }
    return 0;
}
