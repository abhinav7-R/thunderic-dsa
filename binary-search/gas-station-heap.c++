#include <iostream>
#include <vector>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        long double length = arr[i + 1] - arr[i];
        pq.push({length, i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto top = pq.top();
        pq.pop();
        int segmentIndex = top.second;

        howMany[segmentIndex]++;
        long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
        long double newLen = totalDist / (howMany[segmentIndex] + 1);
        pq.push({newLen, segmentIndex});
    }

    return pq.top().first;
}

int main()
{
    vector<int> arr = {2, 3, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
