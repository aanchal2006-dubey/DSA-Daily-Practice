/* There are N books, each ith book has A[i] number of pages.

You have to allocate th M number of students so that the maximum number of pages allocated to a student is minimum. 

    - Each book  should be allocated to a student.
    - Each student has to be allocated at least one book.
    - Allotment should be in contiguous order.
    
Calculate and return that numinum possible number. Return -1 if a valid assignment is not possible.

Input: arr[] = [2, 1, 3, 4], N = 4, M = 2
Output: 6*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllotedPages){
    int studentsRequired = 1;
    int currentPages = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > maxAllotedPages){
            return false; // If a single book has more pages than maxAllotedPages, it's not possible to allocate
        }
        if(currentPages + arr[i] > maxAllotedPages){
            studentsRequired++; // Need another student
            currentPages = arr[i]; // Start counting pages for the new student
        } else {
            currentPages += arr[i]; // Add pages to the current student's allocation
        }
    }
    return studentsRequired <= m; // Check if the number of students required is less than or equal to m
}

int allocateBooks(vector<int> &arr, int n, int m){
    if(m > n){
        return -1; // More students than books, not possible to allocate
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i]; // Calculate total pages
    }

    int low = 0, high = sum, result = -1;

    while(low <= high){
        int mid = low + (high - low) / 2; // Midpoint of the current range

        if(isPossible(arr, n, m, mid)){
            result = mid; // Update result to the current mid value
            high = mid - 1; // Try to find a smaller maximum by reducing the high
        } else {
            low = mid + 1; // Increase low to try a larger maximum
        }
    }
    return result;
}

int main(){
    vector<int> arr = {2, 1, 3, 4};
    int n = arr.size();
    int m = 2;

    int result = allocateBooks(arr, n, m);
    cout << "Minimum possible maximum pages allocated to a student: " << result << endl;

    return 0;
}