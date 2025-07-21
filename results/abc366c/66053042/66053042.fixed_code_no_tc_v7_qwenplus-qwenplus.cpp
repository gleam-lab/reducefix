#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> countMap;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (countMap[x] == 0)
            {
                countMap[x] = 1;
            }
            else
            {
                countMap[x]++;
            }
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            countMap[x]--;
        }
        else if (type == 3)
        {
            // Count how many keys have count > 0
            int distinctCount = 0;
            for (const auto& [key, val] : countMap)
            {
                if (val > 0) distinctCount++;
            }
            cout << distinctCount << endl;
        }
    }

    return 0;
}