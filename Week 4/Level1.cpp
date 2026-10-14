#include <iostream>
#include <vector>
using namespace std;

// Binary Search algo ->works only for sorted array
// TC -> O(logn)
// Sc -> O(1)

int binarySearch(vector<int> &arr, int target)
{
    // target > arr[mid] ans right mei
    // target < arr[mid] ans left mei

    int size = arr.size();
    int start = 0, end = size - 1;
    while (start <= end)
    {
        // int mid = (s+e)/2; //can give integer flow
        // use
        int mid = start + (end - start) / 2;
        if (target == arr[mid])
            return mid;             // return targetElement index
        else if (target > arr[mid]) // if array is in ascending use this if in descending use  target<arr[mid]
        {
            // right mei jao
            start = mid + 1;
        }
        else
        {
            // left mei jao
            end = mid - 1;
        }
    }

    return -1; // target not exist
}

int firstOccurence(vector<int> &nums, int target)
{
    int size = nums.size();
    int s = 0, e = size - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target == nums[mid])
        {
            ans = mid;
            // it can be ans or ans is in left
            e = mid - 1;
        }
        else if (target > nums[mid])
        {
            // right mei jao
            s = mid + 1;
        }
        else
        {
            // left mei jao
            e = mid - 1;
        }
    }
    return ans;
}
int lastOccurence(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (target == nums[m])
        {
            ans = m;
            s = m + 1; // for last occurence right mei jao
        }
        else if (target > nums[m])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

// Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.
int findMissingElementInASortedArray(vector<int> &nums)
{
    // array size se N find kiya [1,N] now we will find missing
    // i/p -> [1,2,3,4,5,7,8] o/p-> [6]
    // arr[m]-1==1 left mei hai currently ans right mei

    int n = nums.size();
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] - m == 1)
        {
            s = m + 1;
        }
        else
        {
            // right mei hai may be ans pr so store
            ans = nums[m] - 1;
            e = m - 1;
        }
    }
    if (ans == -1)
    {
        return n + 1;
    }
    return ans;
}

int maxElementIndex(vector<int> &arr)
{
    int maxElementIdx = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[maxElementIdx])
        {
            maxElementIdx = i;
        }
    }
    return maxElementIdx;
    // TC -> O(n)
}
int maxIndexUsingBinarySearch(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    int ans = -1;
    while (s < e)
    { // s<=e infinite loop bcoz we are doing e=mid
        int m = s + (e - s) / 2;
        if (arr[m] < arr[m + 1])
        {
            // we are currently in left of mountain which is increasing
            // so to find ans we need to go to right
            s = m + 1;
        }
        else if (arr[m] > arr[m + 1])
        {
            // we are in right,we might be on ans or ans in right
            ans = m;
            e = m; // no mid-1 to preserve ans
        }
    }
    return ans;
}
int peakIndexInMountainArray(vector<int> &arr)
{

    // int ans = maxElementIndex(arr);
    int ans = maxIndexUsingBinarySearch(arr);
    return ans;
}



int main()
{
    vector<int> arr = {12, 15, 18, 20, 25, 90};
    vector<int> arr1 = {90, 78, 43, 10, -5, -10};
    int target = -5;
    int targetIdx = binarySearch(arr1, target);
    // if (targetIdx != -1)
    // {
    //     cout << "Element " << target << " found at index " << targetIdx << endl;
    // }
    // else
    // {
    //     cout << "Element not exist";
    // }
    vector<int> arr2 = {1, 2, 3, 4, 5, 7, 8};
    cout << findMissingElementInASortedArray(arr2);
}