#include<iostream>

using namespace std;


void printArrayRowWise(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printArrayColumnWise(int arr[][5],int row,int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool linearSearchin2dArray(int arr[3][4],int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(target == arr[i][j]){
                return true;
            }
        }
    }
    return false;
}

int maxElementIn2dArray(int arr[][4],int row,int col){
    int maxElement = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] > maxElement){
                maxElement = arr[i][j];
            }
        }
    }
    return maxElement;
}

int minElementIn2dArray(int arr[][4],int row,int col){
    int minElement = INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // if(arr[i][j] < minElement){
            //     minElement =  arr[i][j];
            // }
            minElement = min(arr[i][j],minElement);
        }
    }
    return minElement;
}

void printSumRowWise(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        int sum =0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<"Sum of Row "<<i+1<<": "<<sum<<endl;
    }
    cout<<endl;

}

void printSumColWise(int arr[][4],int row,int col){
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<"Sum of Column "<<i+1<<" : "<<sum<<endl;
    }
    cout<<endl;
}

void diagonalSumPrint(int arr[][4],int size){
    // constraint row and col are same
    int sum=0;
    for(int r=0 ;r<size;r++){
        sum+=arr[r][r];
    }
    cout<<"Diagnoal sum "<<sum<<endl;
}

int reverseDiagonalSumPrint(int arr[][4],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i][size-1-i];
    }
    return sum;
}

void transposeOfMatrix(int arr[][4],int size){
    // Lower triangle processed
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<i;j++){
    //         swap(arr[i][j],arr[j][i]);
    //     }
    // }

    // upper triangle processed
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            // swap
            // int temp = arr[i][j];
            // arr[i][j]=arr[j][i];
            // arr[j][i]=temp;

            // swap other logic w/o 3rd variable
            arr[i][j]=arr[i][j]+arr[j][i];
            arr[j][i]=arr[i][j]-arr[j][i];
            arr[i][j]=arr[i][j]-arr[j][i];

        }
    }
}
int main(){
    int row=4,col=5;
    int arr[4][5];
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // printArrayRowWise(arr,row,col);
    // printArrayColumnWise(arr,row,col);
    int arr2[3][4]= { {1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12}                    
                     };
    int target =111;
    if(linearSearchin2dArray(arr2,3,4,target)){
        cout<<"Element Found";
    }else{
        cout<<"Element does not exist";
    }
    cout<<endl;
    cout<<maxElementIn2dArray(arr2,3,4)<<endl;
    cout<<minElementIn2dArray(arr2,3,4)<<endl;
    printSumRowWise(arr2,3,4);
    printSumColWise(arr2,3,4);

    int arr3[4][4] = {{1,2,3,5},
                       {5,6,7,8},
                       {9,10,11,12},
                       {13,14,15,16}};
   diagonalSumPrint(arr3,4);
   cout<<"Reverse Diagonal sum "<<reverseDiagonalSumPrint(arr3,4)<<endl;

    transposeOfMatrix(arr3,4);
    printArrayRowWise(arr3,4,4);
}