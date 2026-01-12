#include<iostream>
#include <vector>
using namespace std;

bool issorted(vector<int> &arr){
    int n = arr.size();
    int count = 0;

    for (int i=0; i<n; i++){
        if (arr[i]>arr[i+1]){
            count ++;
        }
        if (count>1)
           return false;
    }
    return true;
}

int main(){
    vector<int> arry  ={9,4,6,7,8,};
    cout<<issorted(arry) <<endl;
    return 0;
}