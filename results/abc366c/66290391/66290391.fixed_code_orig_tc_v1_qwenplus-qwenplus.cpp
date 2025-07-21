#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    unordered_map<int, int> countMap;
    int distinctCount = 0;

    while (q--)
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
            cout << distinctCount << '\n';
        }
    }

    return 0;
}