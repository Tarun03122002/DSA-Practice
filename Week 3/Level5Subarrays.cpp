#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void print2dArray(vector<vector<int>> &arr)
{
    for (const auto &it : arr)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printSubArrays(vector<int> &arr)
{
    int size = arr.size();
    vector<vector<int>> subArrays;
    for (int i = 0; i < size; i++)
    {
        vector<int> subArray;
        for (int j = i; j < size; j++)
        {
            subArray.push_back(arr[j]);
            subArrays.push_back(subArray);
        }
    }
    cout << "Printing Sub arrays :" << endl;
    print2dArray(subArrays);
}

int maxSubArray(vector<int> &nums)
{
    // int maxSum = INT_MIN;
    // // BRUTE FORCE TC -> O(n)^3
    // for(int i=0;i<nums.size();i++){
    //     for(int j=i;j<nums.size();j++){
    //         int sum = 0;
    //         for(int k=i;k<=j;k++){
    //             sum+=nums[k];
    //         }
    //         maxSum = max(sum,maxSum);
    //     }
    // }
    // return maxSum;

    // int size = nums.size();
    // int maxSum = INT_MIN;
    // for(int i=0;i<size;i++){
    //     int sum = 0;//adding  sum of previous subarray
    //     for(int j=i;j<size;j++){
    //         sum+=nums[j];
    //         maxSum = max(sum,maxSum);
    //     }
    // }
    // return maxSum;
    // above also gives tle
    // TC -> o(n)^2

    // kadane's algo
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > maxSum)
        {
            maxSum = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}
int main()
{

    vector<int> arr = {3, 4, -1, 8, 2};

    printSubArrays(arr);
    return 0;
}
