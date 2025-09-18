#include <iostream>
using namespace std;
void countingSort(int a[], int n){
    int maxValue = a[0];
    int output[n];
    // Find the maximum value
    for(int i = 1; i < n; i++){
        if(a[i] > maxValue){
            maxValue = a[i];
        }
    }
    // All value are initialized by 0
    int count[maxValue + 1] = {0};
    // Count occurrences
    for(int i = 0; i < n; i++){
        count[a[i]]++;
    }
    // Cumulative count
    for(int i = 1; i <= maxValue; i++){
        count[i] += count[i - 1];
    }
    // Build the output array
    for(int i = n-1; i >= 0; i--){
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    // Copy back to original array
    for(int i = 0; i < n; i++){
        a[i] = output[i];
    }
    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    countingSort(arr, n);
    return 0;
}