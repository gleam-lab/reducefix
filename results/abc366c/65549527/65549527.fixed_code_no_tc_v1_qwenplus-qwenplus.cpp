#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> countMap;  // To keep track of counts of each number
    int distinctCount = 0;             // To avoid calling size() repeatedly

    for (int i = 0; i < q; i++)
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
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}