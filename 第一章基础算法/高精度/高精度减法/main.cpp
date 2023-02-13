#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& C){
    for(int i=C.size()-1;i>=0;i--){
        cout<<C[i];
    }
    cout<<endl;
}
int compare(vector<int>& A,vector<int>& B){

    if(A.size()!=B.size()){
        return A.size()-B.size();
    }else{
        for(int i=A.size()-1;i>=0;i--){
            if(A[i]!=B[i])
                return A[i]-B[i];
        }
        return 0;
    }
}

vector<int> sub(vector<int>& A,vector<int>& B){
    vector<int> C;
    int k=0;
    for(int i=0;i<A.size();i++){
        k=A[i]-k;
        if(i<B.size())
            k-=B[i];
        C.push_back((k+10)%10);
        if(k<0)
            k=1;
        else
            k=0;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

int main(){
    string a,b;
    vector<int> A,B,C;
    while(cin>>a>>b){
        A.clear();B.clear();
        for(int i=a.size()-1;i>=0;i--)
            A.push_back(a[i]-'0');
        for(int i=b.size()-1;i>=0;i--)
            B.push_back(b[i]-'0');
        int num=compare(A,B);
        cout<<"num=>"<<num<<endl;
        if(num>=0){
            C=sub(A,B);
            print(C);
        }else{
            cout<<"-";
            C=sub(B,A);
            print(C);
        }
    }
    return 0;
}
