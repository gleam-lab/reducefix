#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()

// Function to check if a position is within bounds
bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// Main function to solve the problem
void solve() {
    ll n, m; cin >> n >> m;
    vector<pll> q(m); 
    for(ll i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }
    
    set<ll> row, col, d1, d2;
    for(auto &[i, j] : q) {
        row.insert(i); 
        col.insert(j); 
        d1.insert(i - j); 
        d2.insert(i + j);
    }
    
    ll ans = n * n;
    ans -= 1LL * row.size() * n;
    ans -= 1LL * col.size() * n;
    ans += 1LL * row.size() * col.size();
    
    for(auto &d: d1) {
        set<pll> com;
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
    
    for(auto &d: d2) {
        set<pll> com;
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
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}