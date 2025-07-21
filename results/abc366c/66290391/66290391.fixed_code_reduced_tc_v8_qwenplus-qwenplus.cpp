#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    unordered_map<int, int> countMap; // Tracks count of each number
    int distinctCount = 0;

    rep(i, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            if (countMap[x] == 0)
                distinctCount++;
            countMap[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0)
                distinctCount--;
        }
        else if (type == 3)
        {
            cout << distinctCount << endl;
        }
    }

    return 0;
}