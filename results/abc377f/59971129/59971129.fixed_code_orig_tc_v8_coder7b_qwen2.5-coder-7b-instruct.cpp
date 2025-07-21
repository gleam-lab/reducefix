#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1000005;

set<int> rows, cols, diag1, diag2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll ans = (n - rows.size()) * (n - cols.size());

    for (auto& r : rows) {
        for (auto& c : cols) {
            if (!diag1.count(r + c) && !diag2.count(r - c)) {
                --ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}