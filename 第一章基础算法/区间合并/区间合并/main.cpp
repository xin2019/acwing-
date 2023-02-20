#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> PII;
vector<PII> segs;
void merge(vector<PII>& segs){
    int st=-1e9,ed=-1e9;
    vector<PII> res;
    for(int i=0;i<segs.size();i++){
        if(ed<segs[i].first){
            if(st!=-1e9)
            res.push_back({st,ed});
            st=segs[i].first;
            ed=segs[i].second;
        }
        else{
            ed=max(ed,segs[i].second);
        }
    }
    if(st!=-1e9)
    res.push_back({st,ed});
    segs=res;
}
int main(){
    int n,l,r;
    while(cin>>n){
        segs.clear();
        for(int i=0;i<n;i++){
            cin>>l>>r;
            segs.push_back({l,r});
        }
        merge(segs);
        cout<<segs.size()<<endl;
    }
    return 0;
}
