#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,q,temp,x,l,r,mid;
    vector<int> nums;
    while(cin>>n>>q){
        for(int i=0;i<n;i++){
            cin>>temp;
            nums.push_back(temp);
        }
        while(q--){
            cin>>x;
            //Çó×ó±ßµã
            l=0;r=n-1;
            if(l<r){
                while(l<r){
                    mid=l+r>>1;
                    if(x<=nums[mid])
                        r=mid;
                    else
                        l=mid+1;
                }
                if(nums[l]!=x)
                    cout<<"-1 -1"<<endl;
                else{
                    cout<<l<<" ";
                    l=0;r=n-1;
                    while(l<r){
                        mid=l+r+1>>1;
                        if(x>=nums[mid])
                            l=mid;
                        else
                            r=mid-1;
                    }
                    cout<<r<<endl;
                }
            }
        }
    }
    return 0;
}
