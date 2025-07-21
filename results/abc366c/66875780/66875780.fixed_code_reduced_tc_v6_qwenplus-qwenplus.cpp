#include <iostream>
#include <unordered_map>
using namespace std;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve()
{
    long long Q;
    cin >> Q;
    
    unordered_map<long long, int> countMap;
    int distinctCount = 0;

    while (Q--)
    {
        int queryType;
        cin >> queryType;

        if (queryType == 1)
        {
            long long x;
            cin >> x;
            if (countMap[x] == 0)
                distinctCount++;
            countMap[x]++;
        }
        else if (queryType == 2)
        {
            long long x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0)
                distinctCount--;
        }
        else // queryType == 3
        {
            cout << distinctCount << "\n";
        }
    }
}

int main()
{
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}