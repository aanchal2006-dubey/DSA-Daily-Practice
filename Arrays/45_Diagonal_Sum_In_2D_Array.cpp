/* Diagonal Sum in 2D Array.

Input: arr[n][n] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}
Output: 34
Explanation: Primary diagonal elements are 1, 6, 11, 16. Secondary diagonal elements are 4, 7, 10, 13. Sum = 1+6+11+16 + 4+7+10+13 = 34. 

Input: arr[n][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
Output: 25
Explanation: Primary diagonal elements are 1, 5, 9. Secondary diagonal elements are 3, 5, 7. Sum = 1+5+9 + 3+5+7 = 30 and 5 is counted twice, so the final sum is 25. 
*/

#include<iostream>
using namespace std;

int diagonalSum(int arr[100][100], int n) {
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        // Add primary diagonal element
        sum += arr[i][i];
        
        // Add secondary diagonal element
        if (i != n - 1 - i) { // Avoid double counting the center element in odd-sized matrices
            sum += arr[i][n - 1 - i];
        }
    }
    
    return sum;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;
    
    int arr[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    int result = diagonalSum(arr, n);
    cout << "The sum of the primary and secondary diagonals is: " << result << endl;
    
    return 0;
}