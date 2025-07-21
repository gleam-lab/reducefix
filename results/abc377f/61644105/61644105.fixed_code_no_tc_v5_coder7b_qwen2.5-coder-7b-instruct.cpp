#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;

int n, m;
ll row[N], col[N], up[2][N], down[2][N];
bool exists_row[N], exists_col[N], exists_up[2][N], exists_down[2][N];
vector<ll> sorted_row, sorted_col, sorted_up[2], sorted_down[2];

void add(ll &cnt, vector<ll> &vec, bool &exists, ll x) {
    auto it = lower_bound(vec.begin(), vec.end(), x);
    if (it == vec.end() || *it != x) {
        vec.insert(it, x);
        cnt++;
        exists = true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        ll d = (x + y) & 1;
        row[i] = y, col[i] = x, up[d][i] = y - x, down[d][i] = x + y;
        add(exists_row[y], sorted_row, exists_row[y], y);
        add(exists_col[x], sorted_col, exists_col[x], x);
        add(exists_up[d][y - x], sorted_up[d], exists_up[d][y - x], y - x);
        add(exists_down[d][x + y], sorted_down[d], exists_down[d][x + y], x + y);
    }

    ll ans = n * n - m;
    for (int i = 0; i < m; i++) {
        ll x = row[i], y = col[i], d = (x + y) & 1;
        ans -= exists_row[y] + exists_col[x] + exists_up[d][y - x] + exists_down[d][x + y];
        ans += exists_row[y - 1] + exists_row[y + 1] + exists_col[x - 1] + exists_col[x + 1] +
               exists_up[d][y - x - 1] + exists_up[d][y - x + 1] + exists_down[d][x + y - 1] + exists_down[d][x + y + 1];
    }

    cout << ans << '\n';
    return 0;
}