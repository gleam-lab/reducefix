#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

#define x first
#define y second
#define all(x) x.begin(), x.end()

const int N = 4e5 + 10;

int H, W, Q;

void solve()
{
    cin >> H >> W >> Q;

    vector<set<int>> row(W + 1), col(H + 1);
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
            row[j].insert(i), col[i].insert(j);

    auto erase = [&](int r, int c) {
        if (col[r].count(c))
            col[r].erase(c);
        if (row[c].count(r))
            row[c].erase(r);
    };

    while (Q--)
    {
        int r, c;
        cin >> r >> c;

        if (col[r].empty() || *col[r].lower_bound(c) != c)
        {
            // Need to destroy in four directions

            // Left
            auto it = col[r].lower_bound(c);
            if (it != col[r].begin())
            {
                int pos = *prev(it);
                erase(r, pos);
            }

            // Right
            it = col[r].lower_bound(c);
            if (it != col[r].end())
            {
                int pos = *it;
                erase(r, pos);
            }

            // Up
            auto jt = row[c].lower_bound(r);
            if (jt != row[c].begin())
            {
                int pos = *prev(jt);
                erase(pos, c);
            }

            // Down
            jt = row[c].lower_bound(r);
            if (jt != row[c].end())
            {
                int pos = *jt;
                erase(pos, c);
            }
        }
        else
        {
            // Destroy current cell
            erase(r, c);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i)
        ans += col[i].size();
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}