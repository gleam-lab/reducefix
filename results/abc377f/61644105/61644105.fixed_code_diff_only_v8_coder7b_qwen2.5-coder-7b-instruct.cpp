#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_N = 1e3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> rows, cols, ups, downs;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.push_back(b);
        cols.push_back(a);
        ups.push_back(a + b);
        downs.push_back(a - b);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(ups.begin(), ups.end());
    sort(downs.begin(), downs.end());

    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    cols.erase(unique(cols.begin(), cols.end()), cols.end());
    ups.erase(unique(ups.begin(), ups.end()), ups.end());
    downs.erase(unique(downs.begin(), downs.end()), downs.end());

    ll total_squares = n * n;
    ll captured_by_rows = 0, captured_by_cols = 0, captured_by_ups = 0, captured_by_downs = 0;

    captured_by_rows = accumulate(rows.begin(), rows.end(), 0LL, [](ll acc, ll x) { return acc + x; });
    captured_by_cols = accumulate(cols.begin(), cols.end(), 0LL, [](ll acc, ll x) { return acc + x; });
    captured_by_ups = accumulate(ups.begin(), ups.end(), 0LL, [](ll acc, ll x) { return acc + x; });
    captured_by_downs = accumulate(downs.begin(), downs.end(), 0LL, [](ll acc, ll x) { return acc + x; });

    captured_by_rows *= n;
    captured_by_cols *= n;
    captured_by_ups *= n;
    captured_by_downs *= n;

    captured_by_rows /= 2;
    captured_by_cols /= 2;
    captured_by_ups /= 2;
    captured_by_downs /= 2;

    cout << total_squares - captured_by_rows - captured_by_cols - captured_by_ups - captured_by_downs << endl;

    return 0;
}