#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int>& A,vector<int>& B){
    vector<int> C;
    int k=0;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size())
            k+=A[i];
        if(i<B.size())
            k+=B[i];
        C.push_back(k%10);
        k/=10;
    }
    return C;
}

void print(vector<int>& C){
    for(int i=C.size()-1;i>=0;i--)
        cout<<C[i];
    cout<<endl;
}
int main(){
    string a,b;
    vector<int> A,B;
    vector<int> C;
    while(cin>>a>>b){
        for(int i=a.size()-1;i>=0;i--)
            A.push_back(a[i]-'0');
        for(int i=b.size()-1;i>=0;i--)
            B.push_back(b[i]-'0');
        C=add(A,B);
        print(C);
    }
    return 0;
}
