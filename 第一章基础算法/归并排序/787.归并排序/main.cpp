#include <iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int>& nums,int low ,int mid ,int high){
    vector<int> b;
    for(int i=0;i<nums.size();i++)
        b.push_back(nums[i]);
    int i,j,index;
    for(i=0,j=mid,index=0;i<mid&&j<high;){
        if(b[i]<b[j])
            nums[index++]=b[i++];
        else
            nums[index++]=b[j++];
    }
    while(i<mid)
        nums[index++]=b[i++];
    while(j<high)
        nums[index++]=b[j++];
}
void Merge(vector<int>& nums,int low,int high){
    if(low<high){
        int mid=low+high>>1;
        Merge(nums,low,mid);
        Merge(nums,mid+1,high);
        MergeSort(nums,low,mid,high);
    }
}
int main()
{
    int n,temp;
    vector<int> nums;
    while(cin>>n){
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            nums.push_back(temp);
        }
        Merge(nums,0,n-1);
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}
