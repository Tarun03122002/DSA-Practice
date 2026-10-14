#include <iostream>
#include <vector>
using namespace std;

int findPivotElementIndex(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] > nums[n - 1])
        {
            // means we are in line 1 ->left of mountain
            // it can be ans or ans is in right
            ans = m;
            s = m + 1;
        }
        else
        {
            // we are in line 2-> right of mountain
            // ans is in left so move to left
            e = m - 1;
        }
    }
    return ans;
}
int binarySearch(vector<int> &nums, int target, int start, int end)
{
    int s = start, e = end;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (target == nums[m])
        {
            return m;
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
    return -1;
}
int search(vector<int> &nums, int target)
{
    int pivotIndex = findPivotElementIndex(nums, target);
    if (pivotIndex == -1)
    {
        // means no rotation ->then search in entire array
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    int ans = -1;
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        ans = binarySearch(nums, target, 0, pivotIndex);
    }
    else if (target >= nums[pivotIndex + 1] &&
             target <= nums[nums.size() - 1])
    {
        ans = binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
    }
    return ans;
    // Tc -> O(logn)
}

// int bruteForce(int x){
//     int ans = 0;
//     for(int i=1;i<=x;i++){
//         if(i>INT_MAX/i){
//             return ans;
//         }
//         int square = i*i;
//         if(square<=x){
//             ans=i;
//         }
//     }
//     return ans;
// }

int squareUsingBinarySearch(int x)
{
    int s = 0, e = x;
    int ans = 0;
    while (s <= e)
    {
        long long m = s + (e - s) / 2;
        long long square = m * m;
        if (square == x)
        {
            return m;
        }
        else if (square > x)
        {
            // left mei jao
            e = m - 1;
        }
        else
        {
            ans = m;
            s = m + 1;
        }
    }
    return ans;
}
int mySqrt(int x)
{
    // int ans = bruteForce(x);
    int ans = squareUsingBinarySearch(x);
    return ans;
}
double sqRootPrecision(int n)
{
    double sqrt = squareUsingBinarySearch(n);

    int precision = 3; // after decimal 3 digits
    double step = 0.1;
    for (int i = 1; i <= precision; i++)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            cout << i << " " << sqrt << endl;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // in memmory 2d is represnted in 1d array using col*i+j
    int rows = matrix.size();
    int cols = matrix[0].size();
    int s = 0, e = rows * cols - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        int rowIndex = m / cols;
        int colIndex = m % cols;
        if (target == matrix[rowIndex][colIndex])
        {
            return true;
        }
        else if (target > matrix[rowIndex][colIndex])
        {
            // right mei jao
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return false;
}
int main()
{
    cout << sqRootPrecision(5);
}