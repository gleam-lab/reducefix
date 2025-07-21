#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> countMap;
    int Q;
    cin >> Q;
    int distinctCount = 0;

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
                ++distinctCount;
            }
            ++countMap[x];
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            --countMap[x];
            if (countMap[x] == 0)
            {
                --distinctCount;
            }
        }
        else if (type == 3)
        {
            cout << distinctCount << "\n";
        }
    }

    return 0;
}