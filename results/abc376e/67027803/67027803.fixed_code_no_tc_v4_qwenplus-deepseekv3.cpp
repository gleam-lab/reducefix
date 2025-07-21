#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    
    sort(ab.begin(), ab.end());
    
    if (k == 1) {
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    
    priority_queue<ll> pq; // max-heap to keep track of top k-1 smallest B's
    ll sum = 0;
    
    // Initialize with first k-1 elements
    for (int i = 0; i < k-1; i++) {
        pq.push(ab[i].second);
        sum += ab[i].second;
    }
    
    ll ans = inf;
    for (int i = k-1; i < n; i++) {
        // Current element's A is the max, and we pick it plus k-1 smallest B's before it
        ll current = ab[i].first * (sum + ab[i].second);
        ans = min(ans, current);
        
        // Maintain the k-1 smallest B's in the window [0, i]
        if (pq.top() > ab[i].second) {
            sum -= pq.top();
            pq.pop();
            sum += ab[i].second;
            pq.push(ab[i].second);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}