#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Printing array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int size)
{
    // Run Loop Till n/2
    // for (int i = 0; i < size / 2; i++)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[size - 1 - i];
    //     arr[size - 1 - i] = temp;
    // }

    // using 2 pointer
    int left = 0, right = size - 1;
    while (left < right)
    {
        swap(arr[left++], arr[right--]);
    }
    cout << "After Reverse :" << endl;
    printArray(arr, size);
}

void printExtreme(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left] << " ";
        }
        else
        {
            cout << arr[left] << " ";
            cout << arr[right] << " ";
        }
        left++, right--;

    }
}
int main()
{
    int arr[3] = {2, 3, 4};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of arr is " << size1;

    int size;
    cout << "Enter size of array :";
    cin >> size;
    int arr1[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }
    cout << endl;
    // printArray(arr1, size);
    // reverseArray(arr1,size);
    printExtreme(arr1, size);
}