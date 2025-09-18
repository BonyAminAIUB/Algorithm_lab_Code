#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int sz){
    for(int i = 1; i<sz; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key; 
    }
}
void selection_sort(int arr[], int sz){
    for(int i = 0; i<sz-1; i++){
        int min_index = i;
        for(int j = i+1; j<sz; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            swap(arr[min_index] , arr[i]);
        }
    }
}
void bubble_sort(int arr[], int sz){
    int flag = 0;
    for(int i = 1; i<sz; i++){
        for(int j = 0; j<sz-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j+1], arr[j]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
void print_array(int arr[], int sz){
    for(int i = 0; i<sz; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int sz;
    //cout << "Enter array size: ";
    cin >> sz;
    int arr[sz];
    for(int i = 0; i<sz; i++){
        cin >> arr[i];
    }

    insertion_sort(arr,sz);
    print_array(arr,sz);

    selection_sort(arr,sz);
    print_array(arr,sz);

    bubble_sort(arr,sz);
    print_array(arr,sz);

    return 0;
}