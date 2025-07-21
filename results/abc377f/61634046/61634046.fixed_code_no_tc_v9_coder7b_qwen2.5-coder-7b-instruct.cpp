#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000000
#define ll long long

ll n, m;
vector<pair<ll, ll>> pieces;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces.push_back({x, y});
    }

    set<ll> rows, cols, diags1, diags2;
    for (auto& [x, y] : pieces) {
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x - y);
        diags2.insert(x + y);
    }

    ll total_squares = n * n;
    ll occupied_by_rows = rows.size() * n;
    ll occupied_by_cols = cols.size() * n;
    ll occupied_by_diags1 = diags1.size() * n;
    ll occupied_by_diags2 = diags2.size() * n;

    ll occupied_by_two_conditions = 0;
    for (auto& [x, y] : pieces) {
        occupied_by_two_conditions += (rows.count(x) && cols.count(y)) +
                                     (diags1.count(x - y) && diags2.count(x + y));
    }

    ll result = total_squares - occupied_by_rows - occupied_by_cols - 
                occupied_by_diags1 - occupied_by_diags2 + 
                2 * occupied_by_two_conditions;
    
    cout << result << endl;
    return 0;
}