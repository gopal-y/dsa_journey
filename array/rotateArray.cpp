#include "header.h"

int main(){
    int n;
    cin >> n;
    int arr[n];
    REP(i, n)
    {
        cin >> arr[i];
    }
    int l = 1;
    while (l < n)
    {
        int temp = arr[l];
        arr[l]=arr[l+1];
        arr[l + 1] = arr[l];
        
       
        l++;
    }
    REP(i,n){
        cout << arr[i] << " ";
    }
    cout << "\n";
}