#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(auto& x: a) cin >> x, x %= m;
    
    ll prefix_sum = 0, count = 0;
    unordered_map<ll, int> freq{{0, 1}};
    
    for(ll x: a) {
        prefix_sum = (prefix_sum + x) % m;
        count += freq[(prefix_sum * 2 - x) % m];
        freq[prefix_sum]++;
    }
    
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t = 1; cin >> t;
    while(t--) solve();
    
    return 0;
}