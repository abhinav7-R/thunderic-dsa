#include<iostream>
#include<vector>
using namespace std;

int majority(vector<int> &array){
    int count =0;
    int major = 0 ;
    for(int i=0; i<array.size(); i++){
        if(count == 0)  major = array[i];
        if (array[i]== major){
            count ++;
        }
        else count -- ;
    }
    return major ;


}
int main (){
    vector <int> v {2,4,2,6,2,7,2,2,7};
    int result = majority(v);
    cout << result << endl ;
    return 0;
}

