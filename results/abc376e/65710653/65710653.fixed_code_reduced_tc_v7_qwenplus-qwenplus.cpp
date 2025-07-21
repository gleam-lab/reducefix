#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define rrep(i, a, b) for(ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()

// Function to read input quickly
template<typename T>
inline void read(T& x) {
    x = 0; char c = getchar(); bool neg = false;
    while (!isdigit(c)) { if (c == '-') neg = true; c = getchar(); }
    while (isdigit(c)) { x = x * 10 + (c - '0'); c = getchar(); }
    if (neg) x *= -1;
}

void solve() {
    ll n, k;
    read(n), read(k);
    vector<pll> pairs(n);
    rep(i, 0, n) read(pairs[i].first);
    rep(i, 0, n) read(pairs[i].second);

    // Sort by A_i ascending
    sort(all(pairs));

    // We'll keep track of the smallest K B_i values seen so far
    multiset<ll> b_values;
    ll sum_b = 0;

    // Initialize with first K elements
    rep(i, 0, k) {
        b_values.insert(pairs[i].second);
        sum_b += pairs[i].second;
    }

    // Current best is max(A_i) in current set (pairs[k-1].first) times sum_b
    ll result = sum_b * pairs[k - 1].first;

    // Try to improve by adding better B values
    rep(i, k, n) {
        // If current B is better (smaller) than some in our set
        if (*b_values.rbegin() > pairs[i].second) {
            // Remove the largest B from our set
            sum_b -= *b_values.rbegin();
            b_values.erase(prev(b_values.end()));
            
            // Add the new B value
            b_values.insert(pairs[i].second);
            sum_b += pairs[i].second;
            
            // Update result: current A_i is the largest in the current set
            result = min(result, sum_b * pairs[i].first);
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    read(t);
    while (t--) solve();
    
    return 0;
}