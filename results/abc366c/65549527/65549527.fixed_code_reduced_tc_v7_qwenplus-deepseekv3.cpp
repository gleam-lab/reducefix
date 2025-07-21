#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> count; // To keep track of the count of each ball
    set<int> distinct; // To keep track of distinct integers
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
                distinct.insert(x);
            }
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            count[y]--;
            if (count[y] == 0) {
                distinct.erase(y);
            }
        }
        else if (a == 3)
        {
            cout << distinct.size() << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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