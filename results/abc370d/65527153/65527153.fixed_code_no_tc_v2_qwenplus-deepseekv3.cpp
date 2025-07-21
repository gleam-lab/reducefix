#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
const int N = 200020, INF = 0x3f3f3f3f;
int n, m;

void solve() {
    int q;
    cin >> n >> m >> q;
    vector<set<int>> row(n + 1), col(m + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                int j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
            }
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                int j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                int i = *it_down;
                row[i].erase(c);
                col[c].erase(i);
            }
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                int i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}