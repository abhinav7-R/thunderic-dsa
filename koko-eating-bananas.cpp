#include<iostream>
#include<vector>
using namespace std;



int calculateHours(vector<int>& piles, int speed){
    int totalHours = 0;
    
    for(int bananas : piles){
        totalHours += ceil((double)bananas / speed);
    }
    return totalHours;
    }

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int hours = calculateHours(piles, mid);
        if(hours <= h) {
            ans = mid;
            high = mid - 1; int low = 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return ans;
}

int main(){
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h);
    return 0;
}
