#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int>& C){
    for(int i=C.size()-1;i>=0;i--)
        cout<<C[i];
    cout<<endl;
}

vector<int> div(vector<int>& A,int b,int& r){
    vector<int> C;
    r=0;
    for(int i=0;i<A.size();i++){
        r=r*10+A[i];
        C.push_back(r/b);
        r=r%b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

int main(){
    int b,r;
    string a;
    vector<int> A,C;
    while(cin>>a>>b){
        A.clear();
        for(int i=0;i<a.size();i++)
            A.push_back(a[i]-'0');
        C=div(A,b,r);
        print(C);
        cout<<r<<endl;
    }
    return 0;
}
