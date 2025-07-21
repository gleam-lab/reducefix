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
    int Q;
    cin >> Q;
    
    unordered_map<int, int> freq; // to store frequency of each number
    int distinctCount = 0; // to store current number of distinct integers
    
    while (Q--)
    {
        int type;
        cin >> type;
        
        if (type == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                distinctCount++;
            freq[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                distinctCount--;
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