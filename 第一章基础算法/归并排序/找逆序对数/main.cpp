#include <iostream>
#include<vector>
using namespace std;


//我的解法-暴力解法，T(n)=O(n2)
int violence(vector<int>& nums){
    int count=0;
    for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i])
                    count++;
            }
    }
    return count;
}

int main()
{
    int n,temp,count;
    vector<int> nums;
    while(cin>>n){
        count=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            nums.push_back(temp);
        }
        count=violence(nums);
        cout<<count<<endl;
    }
    return 0;
}
