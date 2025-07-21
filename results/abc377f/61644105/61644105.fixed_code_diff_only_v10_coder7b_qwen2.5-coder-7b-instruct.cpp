#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e3 + 10;

ll n, m;
vector<ll> row[MAXN], col[MAXN], up[2], down[2];

bool exists(const vector<ll>& arr, ll val) {
    return binary_search(arr.begin(), arr.end(), val);
}

ll count(const vector<ll>& arr, ll l, ll r) {
    return upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l);
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll x, y; cin >> x >> y;
        --x, --y;
        row[y].push_back(x);
        col[x].push_back(y);
        up[(x + y) & 1].push_back(y - x);
        down[(x + y) & 1].push_back(x + y);
    }

    for (ll i = 0; i < n; ++i) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
        sort(up[i & 1].begin(), up[i & 1].end());
        sort(down[i & 1].begin(), down[i & 1].end());
    }

    ll total = n * n;
    ll covered = 0;

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (!exists(row[j], i) && !exists(col[i], j) &&
                !exists(up[0], j - i) && !exists(up[1], j + i) &&
                !exists(down[0], j - i) && !exists(down[1], j + i)) {
                ++covered;
            }
        }
    }

    cout << total - covered << endl;

    return 0;
}