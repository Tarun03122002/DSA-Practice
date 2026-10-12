#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &a)
{
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

void negativeToLeftPositiveToRightWith1Pointer(vector<int> &a)
{
    int size = a.size();
    int negativeElementIndex = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            swap(a[i], a[negativeElementIndex]);
            negativeElementIndex++;
        }
    }
}

void negativeToLeftPositiveToRightUsingDutchNationalFlag(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        if (arr[left] < 0)
        {
            left++;
        }
        else if (arr[right] > 0)
        {
            right--;
        }
        else
        {
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }
}

void sortColors(vector<int> &nums) // babbar bhaiya
{
    int left = 0, right = nums.size() - 1;
    for (int index = 0; index <= right;)
    {
        if (nums[index] == 0)
        {
            swap(nums[left], nums[index]);
            index++, left++;
        }
        else if (nums[index] == 2)
        {
            swap(nums[index], nums[right]);
            right--;
        }
        else
        {
            index++;
        }
    }
}

void sortColorsUsingDutchNationalFlagAlgo(vector<int> &arr)
{ // striver
    // algo  0 to low-1 ->0's
    // low to mid-1 -> 1's
    // mid to high -> unsorted
    // high+1 to n(sizeOfArray)-1 -> 2's

    // i/p -> 0 1 1 0 1 2 1 2 0 0 0 size=11

    //   0 1 2
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
void reverse(vector<int> &arr, int start, int end)
{
    int left = start, right = end - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++, right--;
    }
}
void rotate(vector<int> &nums, int k)
{

    // Approach 1

    // int size = nums.size();
    // if (k > size) {
    //     k = k % size;
    // }
    // vector<int> temp;
    // for (int i = size - k; i < size; i++) {
    //     temp.push_back(nums[i]);
    // }
    // for (int i = size - 1; i >= k; i--) {
    //     nums[i] = nums[i - k];
    // }
    // for (int i = 0; i < k; i++) {
    //     nums[i] = temp[i];
    // }

    // Approach 2 -> Modulus
    // vector<int>ans{nums};//copy nums array
    // int n = ans.size();
    // for(int i=0;i<n;i++){
    //     int newIndex = (k+i)%n;
    //     nums[newIndex]=ans[i];
    // }

    // approach 3-> Reversal Method
    // step 1 reverse 0,size-1
    // step 2 reverse 0,k-1
    // step 3 reverse k,size-1
    int n = nums.size();
    if (k > n)
    {
        k = k % n;
    }
    reverse(nums, 0, n);
    reverse(nums, 0, k);
    reverse(nums, k, n);
}
int missingNumber(vector<int> &nums)
{
    // Approach 1
    // int n= nums.size();
    // for(int i =0;i<=n;i++){
    //     int j;
    //     for(j=0;j<nums.size();j++){
    //         if(i== nums[j]){
    //             break;
    //         }
    //     }
    //     if(j==nums.size()){
    //         return i;
    //     }
    // }
    // return -1;

    // approach 2
    int n = nums.size();
    int totalSum = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    return totalSum - sum;
}
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{

    int minRowNo = INT_MAX;
    int maxRowWithOnes = INT_MIN;
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxRowWithOnes)
        {
            maxRowWithOnes = count;
            minRowNo = i;
        }
    }
    if (minRowNo == INT_MAX && maxRowWithOnes == INT_MIN)
        return {0, 0};
    return {minRowNo, maxRowWithOnes};
}

void transpose(vector<vector<int>> &arr)
{
    // upper triangle
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr[i].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // [1,2,3].   [1,4,7]
    // [4,5,6] -> [2,5,8](transpose)
    // [7,8,9].    [3,6,9]
}

void reverseEachRow(vector<vector<int>> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}
void rotate(vector<vector<int>> &matrix)
{
    // transpose + reverse each row
    transpose(matrix);
    reverseEachRow(matrix);
}
vector<int> rearrangeArray(vector<int> &nums)
{
    int length = nums.size();
    vector<int> ans(length);
    int positiveIndex = 0, negativeIndex = 1;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] > 0)
        {
            ans[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
        else
        {
            ans[negativeIndex] = nums[i];
            negativeIndex += 2;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr{7, 5, -9, 10, -8, -2, 2};
    // negativeToLeftPositiveToRightWith1Pointer(arr);
    negativeToLeftPositiveToRightUsingDutchNationalFlag(arr);
    printArray(arr);
    // -2 5 -9 10 -8 7 2
    // -2 -8 -9 10 5 7 2
}