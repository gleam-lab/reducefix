#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// Function to calculate the number of valid positions
ll calculateValidPositions(ll n, ll m, vector<pll> &pieces) {
    set<ll> row, col, d1, d2;
    
    // Count pieces in rows, columns, and diagonals
    for (auto &[i, j] : pieces) {
        row.insert(i);
        col.insert(j);
        d1.insert(i - j);
        d2.insert(i + j);
    }
    
    ll total_positions = n * n;
    ll occupied_by_rows = row.size() * n;
    ll occupied_by_cols = col.size() * n;
    ll occupied_by_d1 = d1.size() * n;
    ll occupied_by_d2 = d2.size() * n;
    
    // Subtract positions captured by rows and columns
    total_positions -= occupied_by_rows;
    total_positions -= occupied_by_cols;
    
    // Add back positions captured by both rows and columns
    total_positions += row.size() * col.size();
    
    // Subtract positions captured by diagonals
    for (auto &d : d1) {
        ll cnt = n - abs(d);
        total_positions -= cnt;
    }
    for (auto &d : d2) {
        ll cnt = d < n ? (d - 1) : (2 * n - d + 1);
        total_positions -= cnt;
    }
    
    // Adjust for overcounting positions captured by both rows and columns and diagonals
    for (auto &d : d1) {
        set<pll> com;
        for (auto &r : row) {
            pll ints = {r, r - d};
            if (inBounds(ints, n)) com.insert(ints);
        }
        for (auto &c : col) {
            pll ints = {c + d, c};
            if (inBounds(ints, n)) com.insert(ints);
        }
        ll cnt = n - abs(d);
        total_positions += com.size();
    }
    for (auto &d : d2) {
        set<pll> com;
        for (auto &r : row) {
            pll ints = {r, d - r};
            if (inBounds(ints, n)) com.insert(ints);
        }
        for (auto &c : col) {
            pll ints = {d - c, c};
            if (inBounds(ints, n)) com.insert(ints);
        }
        for (auto &od : d1) {
            if ((d + od) % 2 == 1) continue;
            pll ints = {(d + od) / 2, (d - od) / 2};
            if (inBounds(ints, n)) com.insert(ints);
        }
        ll cnt = d < n ? (d - 1) : (2 * n - d + 1);
        total_positions += com.size();
    }
    
    return total_positions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    cout << calculateValidPositions(n, m, pieces) << endl;
    
    return 0;
}