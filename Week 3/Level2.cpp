#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main()
{
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // brute Force
    // vector<int> ans;
    // int size = nums.size();
    // for(int i=0;i<size;i++){
    //     for(int j=i+1;j<size;j++){
    //         int sum = nums[i]+nums[j];
    //         if(sum==target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }
    // return {-1,-1};

    // This approach is to check target not for index return as after
    // sorting we can't maintain indexes
    // // approach 2 sorting
    // vector<int> ans;
    // int size = nums.size();
    // sort(nums.begin(),nums.end());
    // int left=0,right=size-1;
    // while(left<right){
    //     int sum = nums[left]+nums[right];
    //     if(sum < target){
    //         left++;
    //     }else if(sum > target){
    //         right --;
    //     }else{
    //         //sum == target
    //         ans.push_back(left);
    //         ans.push_back(right);
    //         return ans;

    //     }
    // }
    // return {-1,-1};

    // approach 3 cum 2 using unordered map
    unordered_map<int, int> elementIndexMp;
    vector<int> ans;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int moreNeeded = target - nums[i];

        if (elementIndexMp.find(moreNeeded) != elementIndexMp.end())
        {
            return {elementIndexMp[moreNeeded], i};
        }
        elementIndexMp[nums[i]] = i;
    }
    return {-1, -1};
}

vector<vector<int>> threeSum(vector<int> &nums)
{

    // brute force -> It gives TLE
    // TC -> n^3
    // int size = nums.size();
    // vector<vector<int>> ans2d;
    // for (int i = 0; i < size; i++) {
    //     for (int j = i + 1; j < size; j++) {
    //         for (int k = j + 1; k < size; k++) {
    //             int sum = nums[i] + nums[j] + nums[k];
    //             if (sum == 0) {
    //                 vector<int> ans1d;
    //                 ans1d.push_back(nums[i]);
    //                 ans1d.push_back(nums[j]);
    //                 ans1d.push_back(nums[k]);
    //                 ans2d.push_back(ans1d);
    //             }
    //         }
    //     }
    // }

    // vector<vector<int>> result;
    // for (auto row : ans2d) {
    //     sort(row.begin(), row.end());

    //     bool duplicate = false;
    //     for (auto existing : result) {
    //         if (row == existing) {
    //             duplicate = true;
    //         }
    //     }
    //     if (!duplicate) {
    //         result.push_back(row);
    //     }
    // }
    // return result;

    // approach 2 sorting & 2 pointer (incomplete)
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int index = 0; index < size - 2; index++)
    {
        int left = index + 1, right = size - 1;
        while (left < right)
        {
            int sum = nums[index] + nums[left] + nums[right];
            if (sum == 0)
            {
                vector<int> arr1d = {nums[index], nums[left], nums[right]};
                ans.push_back(arr1d);
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return ans;

}