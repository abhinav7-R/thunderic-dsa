#include <iostream>
#include <vector>
using namespace std;

bool canPlace(vector<int> &stalls, int k, int dist)
{
    int cows = 1;
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPlaced >= dist)
        {
            cows++;
            lastPlaced = stalls[i];
        }
    }

    return cows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 8, 4, 9, 11, 4, 13};
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
}
