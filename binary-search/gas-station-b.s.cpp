#include <iostream>
#include <vector>
using namespace std;

int gtrequired(long double dist, vector<int> &stations)
{
    int count = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        long double gap =
            stations[i] - stations[i - 1];

        int numberInBetween = gap / dist;

        if ((gap / dist) == numberInBetween * dist)
        {
            numberInBetween--;
        }

        count += numberInBetween;
    }

    return count;
}

double minimiseMaxDistance(vector<int> &stations, int k)
{

    long double low = 0;
    long double high = 0;

    for (int i = 1; i < stations.size(); i++)
    {
        high = max(high,
                   (long double)(stations[i] - stations[i - 1]));
    }

    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid =
            (low + high) / 2.0;

        int required =
            gtrequired(mid, stations);

        if (required > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return (double)high;
}

int main()
{
    vector<int> arr = {2, 3, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "answer: " << ans << "\n";
    return 0;
}