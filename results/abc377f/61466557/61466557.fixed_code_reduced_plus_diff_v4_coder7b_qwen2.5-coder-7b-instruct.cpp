#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

// Function to check if a position is within bounds
bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// Main function to solve the problem
void solve() {
    ll n, m; cin >> n >> m;
    vector<pll> q(m); for(auto &p : q) cin >> p.first >> p.second;

    // Sets to store occupied rows, columns, diagonals, and anti-diagonals
    set<ll> row, col, d1, d2;

    // Populate the sets with the positions of existing pieces
    for(auto &[i, j] : q) {
        row.insert(i); col.insert(j); d1.insert(i - j); d2.insert(i + j);
    }

    // Calculate the total number of empty squares
    ll ans = n * n;

    // Subtract the number of squares occupied by pieces in rows, columns, and diagonals
    ans -= (ll)row.size() * n;
    ans -= (ll)col.size() * n;
    ans += (ll)row.size() * (ll)col.size();

    // Adjust for intersections of diagonals and anti-diagonals
    set<pll> com;
    for(auto &d : d1) {
        com.clear();
        for(auto &r : row) {
            pll ints = {r, r - d};
            if(inBounds(ints, n)) com.insert(ints);
        }
        for(auto &c : col) {
            pll ints = {c + d, c};
            if(inBounds(ints, n)) com.insert(ints);
        }
        ll cnt = n - abs(d);
        ans -= cnt;
        ans += com.size();
    }
    for(auto &d : d2) {
        com.clear();
        for(auto &r : row) {
            pll ints = {r, d - r};
            if(inBounds(ints, n)) com.insert(ints);
        }
        for(auto &c : col) {
            pll ints = {d - c, c};
            if(inBounds(ints, n)) com.insert(ints);
        }
        for(auto &od : d1) {
            if((d + od) % 2 == 1) continue;
            pll ints = {(d + od) / 2, (d - od) / 2};
            if(inBounds(ints, n)) com.insert(ints);
        }
        ll cnt = d < n ? (d - 1) : (2 * n - d + 1);
        ans -= cnt;
        ans += com.size();
    }

    // Output the result
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}