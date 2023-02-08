#include <iostream>
#include<vector>
using namespace std;

int Partition(vector<int>& nums, int low ,int high){
    int pivot = nums[low];
    while(low < high){
        while(low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while(low < high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low]=pivot;
    return low;
}

int QuickSort(vector<int>& nums ,int low ,int high){
    if(low < high){
        int index=Partition(nums ,low ,high);
        QuickSort(nums, low ,index-1);
        QuickSort(nums ,index+1, high);
    }
}




int main()
{
    int n,temp,k;
    vector<int> nums;
    while(cin>>n>>k){
        for(int i=0 ; i < n; i++){
            cin>>temp;
            nums.push_back(temp);
        }
        QuickSort(nums, 0 ,n-1);
       cout<<nums[k-1]<<endl;
    }

    return 0;
}
