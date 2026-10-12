#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printArray(int[], int);
void sort0s1s(int[], int);
void rightShiftBy1Pos(int[], int);
void rightShiftByKPosition(int[], int, int);
void LeftShiftBy1Pos(int[], int);
void LeftShiftByNPosition(int[],int,int);
int main()
{
    int arr[7] = {1, 0, 1, 1, 0, 1, 0};
    int size = 7;
    // sort0s1s(arr, size);
    int arr1[5] = {4, 8, 1, 2, 5};
    // rightShiftBy1Pos(arr1,5);

    // right shift by N position
    // rightShiftByKPosition(arr1, 5, 3);

    // LeftShiftBy1Pos(arr1,5);

    //leftShiftByNposition
    LeftShiftByNPosition(arr1,5,3);

    printArray(arr1, 5);
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

void sort0s1s(int arr[], int size)
{

    // approach 1-> counting
    // int countZeroes=0,countOnes=0;
    // for(int i=0;i<size;i++){
    //     if(arr[i] == 0){
    //         countZeroes++;
    //     }else if(arr[i] ==1){
    //         countOnes++;
    //     }
    // }
    // cout<<"Count of 0's :"<<countZeroes<<endl;
    // int index =0;
    // while(countZeroes--){
    //     arr[index++]=0;
    // }
    // while(countOnes--){
    //     arr[index++]=1;
    // }

    // approach 2 Two pointer here for this problem Dutch National Flag
    int left = 0, right = size - 1;
    while (left < right)
    {
        if (arr[left] == 0)
            left++;
        else if (arr[right] == 1)
            right--;
        else
            swap(arr[left++], arr[right--]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void rightShiftBy1Pos(int arr[], int size)
{
    // i/p -> 4,8,1,2,5
    // o/p -> 5 4 8 1 2

    int temp = arr[size - 1];
    for (int index = size - 1; index > 0; index--)
    {
        arr[index] = arr[index - 1];
    }
    arr[0] = temp;
}

void rightShiftByKPosition(int arr[], int size, int K)
{
    // approach 1
    //  while (K--)
    //  {
    //      /* code */
    //      rightShiftBy1Pos(arr,size);
    //  }

    // approach 2
    // i/p -> 4,8,1,2,5
    // k = 3
    // o/p -> 1 2 5 4 8

    // i/p -> 4,8,1,2,5
    // k = 2
    // o/p -> 2 5 4 8 1
    // store element from n- k to size-1 in temp
    int temp[K],tempIndex=0;
    for (int i = size - K; i < size; i++,tempIndex++)
    {
        temp[tempIndex] = arr[i];
        cout << temp[tempIndex] << " ";
    }
    cout << endl;
    // copy from [size-1 to K]
    for (int i = size - 1; i >= K; i--)
    {
        arr[i] = arr[i - K];
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < K; i++)
    {
        arr[i] = temp[i];
        cout << temp[i] << " ";
    }
    cout << endl;
}

void LeftShiftBy1Pos(int arr[], int size)
{
    // i/p -> [1,2,5,6,7]
    // o/p -> [2,5,6,7,1]

    // i/p -> [4,8,1,2,5]
    // o-p -> [8,1,2,5,4];
    int temp = arr[0];
    for(int i=1;i<size;i++){
        arr[i-1]=arr[i];
    }
    arr[size-1]=temp;
}
void LeftShiftByNPosition(int arr[],int n,int k){
    //approach 1
    // while(k--){
    //     LeftShiftBy1Pos(arr,n);
    // }

    // approach 2
    // i/p -> [4,8,1,2,5]
    // k= 3
    //o/p -> [2,5,4,8,1]
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    int arrIndex=0;
    for(int i=k;i<n;i++){
        arrIndex= i-k;
        arr[arrIndex]=arr[i];
    }
    for(int i=arrIndex+1,tempIndex=0;i<n;i++){
        arr[i] = temp[tempIndex++];
    }
}