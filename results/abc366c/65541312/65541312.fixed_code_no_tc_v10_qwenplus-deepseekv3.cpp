#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> count;
    set<int> unique;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                unique.insert(x);
            }
        }
        else if (a == 2)
        {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                unique.erase(x);
            }
        }
        else if (a == 3)
        {
            cout << unique.size() << endl;
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
    while (t--)
    {
        solve();
    }
    return 0;
}