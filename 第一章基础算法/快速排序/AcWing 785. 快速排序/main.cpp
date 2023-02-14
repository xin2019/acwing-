#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;


int Partition(vector<int>& nums,int low,int high){
    int pivot=nums[low];
    while(low<high){
        while(low<high&&pivot<=nums[high]) high--;
        nums[low]=nums[high];
        while(low<high&&pivot>=nums[low]) low++;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    return low;
}
int QuickSort(vector<int>& nums , int low ,int high){
    if(low<high){
        int index=Partition(nums,low,high);
        QuickSort(nums,low,index-1);
        QuickSort(nums,index+1,high);
    }
}


int main()
{
    int n,temp;
    vector<int> a;
    while(cin>>n){
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            a.push_back(temp);
        }
        QuickSort(a,0,n-1);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
    return 0;
}
