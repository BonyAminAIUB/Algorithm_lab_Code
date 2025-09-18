#include <bits/stdc++.h>
using namespace std;
void Fibonacchi(){
    int val;
    cin >> val;
    if(val <= 1){
        cout << val << " th Fibonacchi value is: " << val << endl; 
    }
    else{
        int fibo_0 = 0;
        int fibo_1 = 1;
        int fibo_n;
        for(int i = 2; i<val; i++){
            fibo_n = fibo_0 + fibo_1;
            fibo_0 = fibo_1;
            fibo_1 = fibo_n;
        }
        cout << val << " th Fibonacchi value is: " << fibo_n << endl;
    }
}
void LCS(){
    string s1,s2;
    cin >> s1 >> s2;

    int size_s1 = s1.size();
    int size_s2 = s2.size();
    int arr[size_s1 + 1][size_s2 + 1];

    for(int i = 0; i<=size_s1; i++){
        for(int j = 0; j<=size_s2; j++){
            if(i == 0 || j == 0){
                arr[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    cout << "Length of the LCS is: " <<arr[size_s1][size_s2] << endl;
}
int main(){
   
    Fibonacchi();
    Fibonacchi();

    LCS();
    LCS();

    return 0;
}