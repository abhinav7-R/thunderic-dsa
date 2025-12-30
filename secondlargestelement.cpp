#include<iostream>
using namespace std;

int second_largest(int arr[], int n){
    if(n<2) return -1;

    int largest= INT_MIN ;
    int seclarg = INT_MIN ;

    for (int i=0; i<n; i++){
        if(arr[i]>largest){
            seclarg = largest;
            largest = arr[i];
        }
        else if (arr[i]<largest && arr[i]>seclarg){
            seclarg= arr[i];
        }
    }
    return seclarg;
}

int secondSmallest(int arr[], int n) {
    if (n < 2) return -1;

    int small = INT_MAX;
    int second_small = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } 
        else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small; 
}


int main(){

    int arry[10] = {23, 45, 76, 34, 99, 99, 95, 95, 34, 90};
    int n = 10;

    int result = second_largest(arry, n);
    cout<< " second largest number is :"<< result <<endl ;

    int result2 = secondSmallest(arry,n);
    cout<< "second smallest element is:"<< result2 << endl ;

    return 0;
}