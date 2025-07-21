#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> count_map;
    set<int> unique_set;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            count_map[x]++;
            if (count_map[x] == 1) {
                unique_set.insert(x);
            }
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            count_map[y]--;
            if (count_map[y] == 0) {
                unique_set.erase(y);
            }
        }
        else if (a == 3)
        {
            cout << unique_set.size() << endl;
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