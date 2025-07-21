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
    
    unordered_map<long long, long long> freq; // Tracks count of each number
    long long distinctCount = 0;

    while (Q--)
    {
        long long type;
        cin >> type;

        if (type == 1 || type == 2)
        {
            long long x;
            cin >> x;

            if (type == 1)
            {
                if (freq[x] == 0)
                    distinctCount++;
                freq[x]++;
            }
            else // type == 2
            {
                freq[x]--;
                if (freq[x] == 0)
                    distinctCount--;
            }
        }
        else // type == 3
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