#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> countMap; // Tracks count of each number
    int distinctCount = 0; // Number of distinct integers

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            if (countMap[x] == 0) {
                distinctCount++;
            }
            countMap[x]++;
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            countMap[y]--;
            if (countMap[y] == 0) {
                distinctCount--;
            }
        }
        else if (a == 3)
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

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}