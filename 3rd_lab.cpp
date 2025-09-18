#include <bits/stdc++.h>
using namespace std;
class Knapsack{
    public:
        char c;
        int tk;
        int kg;
};
void countingSort(int a[], int sz){
    int maxVal = a[0];
    for(int i = 1; i<sz; i++){
        if(a[i] > maxVal){
            maxVal = a[i];
        }
    }
    int c[maxVal + 1] = {0};
    for(int i = 0; i<sz; i++){
        c[a[i]]++;
    }
    for(int i = 1; i<=maxVal; i++){
        c[i] = c[i] + c[i-1];
    }
    int b[sz];
    for(int i = sz-1; i>=0; i--){
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for(int i = 0; i<sz; i++){
        a[i] = b[i];
    }
    // Print array
    for(int i = 0; i<sz; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void coinChoosing(int taka){
    int a[9] = {1000,500,100,50,20,10,5,2,1};
    int count = 0;
    for(int i = 0; i<9; i++){
        if(taka >= a[i]){
            int note = taka / a[i];
            count += note;
            taka = taka % a[i];
        } 
    }
    cout << "Note count: " << count << endl;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    countingSort(a,n);
    int taka;
    cin >> taka;
    coinChoosing(taka);
    
    int num,maxWeight;
    cin >> num >> maxWeight;
    Knapsack item[num];
    for(int i = 0; i<num; i++){
        cin >> item[i].c >> item[i].tk >> item[i].kg;
    }
    for(int i = 0; i<num; i++){
        cout << item[i].c << " " << item[i].tk << " " << item[i].kg << endl;
    }
    return 0;
}