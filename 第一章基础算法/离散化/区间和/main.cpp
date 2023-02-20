#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=3e5+10;
int val[N],s[N];
typedef pair<int,int> PII;
vector<int> point;
vector<PII> add,query;
int findX(vector<int>& point,int x){
    int l=0,r=point.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(x<=point[mid])
            r=mid;
        else
            l=mid+1;
    }
    return l+1;
}
vector<int>::iterator myUnique(vector<int>& point){
    int j=0;
    for(int i=0;i<point.size();i++){
        if(!i||point[i]!=point[i-1])
            point[j++]=point[i];
    }
    return j+point.begin();
}
int main(){
    int n,m,l,r,x,c;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>x>>c;
            add.push_back({x,c});
            point.push_back(x);
        }
        for(int i=0;i<m;i++){
            cin>>l>>r;
            query.push_back({l,r});
            point.push_back(l);
            point.push_back(r);
        }
        sort(point.begin(),point.end());
        point.erase(myUnique(point),point.end());
        for(int i=0;i<add.size();i++){
            x=findX(point,add[i].first);
            val[x]+=add[i].second;
        }
        for(int i=1;i<=point.size();i++){
            s[i]=s[i-1]+val[i];
        }
        for(int i=0;i<query.size();i++){
            l=findX(point,query[i].first);
            r=findX(point,query[i].second);
            cout<<s[r]-s[l-1]<<endl;
        }
    }
    return 0;
}
