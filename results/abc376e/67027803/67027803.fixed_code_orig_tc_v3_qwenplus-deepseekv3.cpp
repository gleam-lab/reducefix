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
    
    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 0; i < k-1; i++) {
        pq.push(ab[i].second);
        sum += ab[i].second;
    }
    
    ll ans = inf;
    for (int i = k-1; i < n; i++) {
        ll current = ab[i].first * (sum + ab[i].second);
        ans = min(ans, current);
        
        if (!pq.empty() && pq.top() > ab[i].second) {
            sum -= pq.top();
            sum += ab[i].second;
            pq.pop();
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
}