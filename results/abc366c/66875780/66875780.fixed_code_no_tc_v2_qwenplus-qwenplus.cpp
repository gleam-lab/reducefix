#include <iostream>
#include <unordered_map>
using namespace std;

// Fast IO setup
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

    unordered_map<int, int> freq; // Tracks count of each number in the bag
    int uniqueCount = 0;          // Number of distinct integers in the bag

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                uniqueCount++;
            freq[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                uniqueCount--;
        }
        else // type == 3
        {
            cout << uniqueCount << "\n";
        }
    }
}

int main()
{
    fastIO();
    int t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}