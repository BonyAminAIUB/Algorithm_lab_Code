#include <bits/stdc++.h>
using namespace std;
void linearSearch(int arr[], int sz, int val){
    int index = -1;
    for(int i = 0; i<sz; i++){
        if(arr[i] == val){
            index = i;
            break;
        }
    }
    if(index < 0){
        cout << "Not found" << endl;
    }
    else{
        cout << "Found in index: " << index << endl;
    }
}
void binarySearch(int arr[], int sz, int val){
    int left = 0;
    int right = sz-1;
    int index = -1;
    while(left<=right){
        int mid = (left + right)/2;
        if(val == arr[mid]){
            index = mid;
            break;
        }
        else if(val < arr[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(index < 0){
        cout << "Not found" << endl;
    }
    else{
        cout << "Found in index: " << index << endl;
    }
}
void merge(int arr[], int left, int right, int mid){
    int i = left;
    int j = mid + 1;
    int k = 0; 
    int c[right - left + 1];
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            c[k++] = arr[i++];
        }
        else{
            c[k++] = arr[j++];
        }
    }
    while(i <= mid){
        c[k++] = arr[i++];
    }
    while(j <= right){
        c[k++] = arr[j++];
    }
    for(i = left; i<= right; i++){
        arr[i] = c[i - left];
    }
}
void mergeSort(int arr[], int left, int right){
    int mid = (left + right)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }
}
int main(){
    int sz,val;
    cin >> sz >> val;
    int arr[sz];
    for(int i = 0; i<sz; i++){
        cin >> arr[i];
    }
    
    linearSearch(arr,sz,val);

    mergeSort(arr, 0, sz-1);
    cout << "Sorted array is: ";
    for(int i = 0; i<sz; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    binarySearch(arr,sz,val);

    return 0;
}