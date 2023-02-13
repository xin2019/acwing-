#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& C){
    for(int i=C.size()-1;i>=0;i--)
        cout<<C[i];
    cout<<endl;
}
vector<int> mul(vector<int>& A,int b){
    vector<int> C;
    int k=0;
    for(int i=0;i<A.size();i++){
        k=A[i]*b+k;
        C.push_back(k%10);
        k/=10;
    }
    if(k)
        C.push_back(k);

    return C;
}
int main(){
    string a;
    int b;
    vector<int> A,C;
    while(cin>>a>>b){
        A.clear();
        for(int i=a.size()-1;i>=0;i--)
            A.push_back(a[i]-'0');
        C=mul(A,b);
        print(C);
    }
    return 0;
}
