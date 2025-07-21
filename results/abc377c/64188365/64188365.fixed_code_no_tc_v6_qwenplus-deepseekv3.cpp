#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> occupied;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});
    }
    
    set<pair<ll, ll>> capturable;
    for (auto p : occupied) {
        ll a = p.first;
        ll b = p.second;
        
        // All 8 possible moves
        if (a + 2 < n && b + 1 < n) capturable.insert({a + 2, b + 1});
        if (a + 1 < n && b + 2 < n) capturable.insert({a + 1, b + 2});
        if (a - 1 >= 0 && b + 2 < n) capturable.insert({a - 1, b + 2});
        if (a - 2 >= 0 && b + 1 < n) capturable.insert({a - 2, b + 1});
        if (a - 2 >= 0 && b - 1 >= 0) capturable.insert({a - 2, b - 1});
        if (a - 1 >= 0 && b - 2 >= 0) capturable.insert({a - 1, b - 2});
        if (a + 1 < n && b - 2 >= 0) capturable.insert({a + 1, b - 2});
        if (a + 2 < n && b - 1 >= 0) capturable.insert({a + 2, b - 1});
    }
    
    // Safe squares are those not in occupied and not in capturable
    ll total_squares = n * n;
    ll unsafe_squares = occupied.size() + capturable.size();
    // Need to subtract overlaps where a square is both occupied and capturable (but in set, duplicates are auto-handled)
    // So no need to subtract since set ensures uniqueness
    
    cout << total_squares - unsafe_squares << endl;
}