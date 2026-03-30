/* Maximum Row Sum in 2D Array.

Input: arr[][] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
Output: 24
Explanation: The sum of the first row is 1 + 2 + 3 = 6, the sum of the second row is 4 + 5 + 6 = 15, and the sum of the third row is 7 + 8 + 9 = 24. The maximum row sum is 24.
*/

#include<iostream>
using namespace std;

int getMsxSum(int arr[][3], int rows, int cols){
    int maxRowSum = 0;

    for(int i=0; i<rows; i++){
        int rowSumI = 0;
        for(int j=0; j<cols; j++){
            rowSumI += arr[i][j];
        }
        maxRowSum = max(maxRowSum, rowSumI);
    }
    return maxRowSum;
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    int maxRowSum = getMsxSum(arr, rows, cols);
    cout << "Maximum Row Sum: " << maxRowSum << endl;

    return 0;
}