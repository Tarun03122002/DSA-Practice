#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findPivotIndex(vector<int> &arr)
{
    // Approach 1->Every Index ->left sum and right sum and compare
    // for(int i=0;i<arr.size();i++){
    //     int lSum=0,rSum=0;
    //     for(int j=0;j<i;j++){
    //         lSum+=arr[j];
    //     }
    //     for(int j=i+1;j<arr.size();j++){
    //         rSum+=arr[j];
    //     }
    //     if(lSum == rSum){
    //         return i;
    //     }
    // }
    // return 0;
    // tc -> O(n^2) sc-> 0(1)

    // Approach 2->Optimal ->Prefix sum
    int n = arr.size();
    vector<int> lSum(n, 0);
    vector<int> rSum(n, 0);
    for (int i = 1; i < n; i++)
    {
        lSum[i] = lSum[i - 1] + arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rSum[i] = rSum[i + 1] + arr[i + 1];
    }
    //     0  1  8  11 17 23
    //    27 20  17 11 6  0
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (lSum[i] == rSum[i])
        {
            ans = i;
        }
    }
    return ans;
}

// find duplicate -> i/p-> [1,3,3,2,4] o/p-> 3 2nd [3,3,3] o/p -> [3]
// here arr[i] contains n+1 integers n is not size but n+1 = size of araray
// 5 = n+1  so n=4 so nums[i] belongs to [1,n] i.e [1,4]
int findDuplicate(vector<int> &nums)
{
    int length = nums.size();

    // Approach 1->Brute Force gives TLE
    // for(int i=0;i<length;i++){
    //     for(int j=i+1;j<length;j++){
    //         if(nums[i]==nums[j]){
    //             return nums[i];
    //         }
    //     }
    // }
    // return -1;
    // tc-> O(n^2)

    // Approach 2-> Sort & compare arr[i] and arr[i-1]
    // sort(nums.begin(),nums.end());
    // int ans = -1;
    // for(int i=1;i<nums.size();i++){
    //     if(nums[i] == nums[i-1]){
    //         ans = nums[i];
    //         break;
    //     }
    // }
    // return ans;

    // APPROACH 3 ->(Negative Marking Method)we know arr[i] contains [1,n]
    // so we use array element as an index ,if array element is negative it means we already visited,so that element  will be our answer
    for (int i = 0; i < length; i++)
    {
        int elementAsIndex = abs(nums[i]);
        if (nums[elementAsIndex] < 0)
        {
            return elementAsIndex;
        }
        nums[elementAsIndex] *= -1;
    }
    return -1;
    // after Dry Run i/p-> [1,3,4,2,2]
    // 1 -3 -4 -2 -2 return 4 in case of index 4 arr[2]

    // i->p [3,3,3,3,3]
    // 3 3 3 -3 3 -> here return 3 at index 1 arr[1]<0
}

// https://www.geeksforgeeks.org/dsa/find-missing-elements-from-an-array/
// i/p->[1,3,3,3,5] o/p->[2,4] nums[i] contains[1,n] here n is size of array so we have to check elementAsIndex-1 to prevent out of bound
void findMissingElementFromArrayWithDuplicates(vector<int> &nums)
{

    // Approach 1->
    // for (int i = 1; i <= nums.size(); i++){
    //     int j=0;
    //     for(;j<nums.size();j++){
    //         if(i == nums[j]){
    //             break;
    //         }
    //     }
    //     if(j==nums.size()){
    //         // that i is missing
    //         cout<<i<<" ";
    //     }

    // }

    // approach 2 negative marking method
    for (int i = 0; i < nums.size(); i++)
    {
        int elementAsIndex = abs(nums[i]);
        nums[elementAsIndex - 1] = nums[elementAsIndex - 1] > 0 ? -nums[elementAsIndex - 1] : nums[elementAsIndex - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            cout << i + 1 << " ";
    }
}

int firstRepeated(vector<int> &arr)
{
    // code here

    //  sort and compare current and previous array should start from 1 -> this will not work as sorting will destroy index order which we need in output

    // approach 1 -> brute force
    // for(int i=0;i<arr.size();i++){ //tle
    //     for(int j=i+1;j<arr.size();j++){
    //         if(arr[i]==arr[j]){
    //             return i+1;
    //         }
    //     }
    // }
    // return -1;

    // approach 2
    unordered_map<int, int> elementAndCount;
    for (auto it : arr)
    {
        elementAndCount[it]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (elementAndCount[arr[i]] > 1)
        {
            return i + 1;
        }
    }
    return -1;
}
void printRowWise2d(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void printColumnWise(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int maxColSize = INT_MIN;
    for (auto &row : matrix)
    {
        maxColSize = max(maxColSize, (int)row.size());
    }
    int cols = maxColSize;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i < matrix[j].size()) // needs to check if row size is different for each row
            {
                cout << matrix[j][i] << " ";
            }
        }
        cout << endl;
    }
}
void printMatrixInWaveForm(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = INT_MIN;
    for (auto &row : matrix)
    {
        cols = max((int)row.size(), cols);
    }
    for (int i = 0; i < cols; i++)
    {
        // print column wise
        if (i & 1)
        {
            // print bottom to top
            for (int j = rows - 1; j >= 0; j--)
            {
                if (i < matrix[j].size())
                    cout << matrix[j][i] << " ";
            }
        }
        else
        {
            // print top to bottom
            for (int j = 0; j < rows; j++)
            {
                if (i < matrix[j].size())
                    cout << matrix[j][i] << " ";
            }
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int totalRows = matrix.size();
    int totalCols = matrix[0].size();
    int count = 0, totalElements = totalRows * totalCols;
    int startingRow = 0, endingRow = totalRows - 1, startingCol = 0,
        endingCol = totalCols - 1;
    vector<int> ans;

    while (count != totalElements)
    {
        for (int j = startingCol; j <= endingCol && count != totalElements; j++)
        {
            ans.push_back(matrix[startingRow][j]);
            count++;
        }
        startingRow++;

        for (int i = startingRow; i <= endingRow && count != totalElements;
             i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for (int j = endingCol; j >= startingCol && count != totalElements;
             j--)
        {
            ans.push_back(matrix[endingRow][j]);
            count++;
        }
        endingRow--;

        for (int i = endingRow; i >= startingRow && count != totalElements;
             i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}
vector<int> addArrays(vector<int> &arr1, vector<int> &arr2)
{
    // code here
    vector<int> ans;
    int size1 = arr1.size();
    int size2 = arr2.size();
    int i = size1 - 1, j = size2 - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = arr1[i] + arr2[j] + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        ans.push_back(lastDigit);
        i--, j--;
    }
    // if arr2 is exhausted but arr1 has element so add it assuming arr2 has 0
    while (i >= 0)
    {
        int sum = arr1[i] + 0 + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        ans.push_back(lastDigit);
        i--;
    }
    while (j >= 0)
    {
        int sum = arr2[j] + 0 + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        ans.push_back(lastDigit);
        j--;
    }
    if (carry)
    {
        ans.push_back(carry);
        carry /= 10;
    }
    // now ans is in reverse store so do reverse
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> factorial(int n)
{
    // code here
    vector<int> ans(1, 1);
    int carry = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int fact = ans[j] * i + carry;
            int lastDigit = fact % 10;
            ans[j] = lastDigit;

            carry = fact / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int removeDuplicates(vector<int> &nums)
{
    int uniqueElementIndexTracker = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[uniqueElementIndexTracker] != nums[i])
        {
            uniqueElementIndexTracker++;
            nums[uniqueElementIndexTracker] = nums[i];
        }
    }
    return uniqueElementIndexTracker + 1;
    // u=1 i=1  0 1 1 1 1 2 2 3 3 4
    // i=2      i=5 u=2 0 1 2 1 1 2 2 3 3 4
    // i=6 i=7.   u=4   0 1 2 3 4 2 2 3 3 4
}
int main()
{
    vector<int> arr{1, 7, 3, 6, 5, 6};
    // cout << findPivotIndex(arr);
    vector<int> arr2{1, 3, 3, 3, 5};
    // findMissingElementFromArrayWithDuplicates(arr2);
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16},
                               {17, 18, 19, 20}};
    // printRowWise2d(mat);
    // printColumnWise(mat);
    printMatrixInWaveForm(mat);
}