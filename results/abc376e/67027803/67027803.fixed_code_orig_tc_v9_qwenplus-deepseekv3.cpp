#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1LL<<60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    
    sort(ab.begin(), ab.end());
    
    ll ans = inf;
    
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    
    priority_queue<ll> q;
    ll sum = 0;
    
    for (int i = 0; i < n; i++) {
        ll a = ab[i].first;
        ll b = ab[i].second;
        
        if (i >= k-1) {
            ans = min(ans, a * (sum + b));
        }
        
        if (i < k-1) {
            q.push(b);
            sum += b;
        } else if (k > 1 && !q.empty() && q.top() > b) {
            sum -= q.top();
            q.pop();
            q.push(b);
            sum += b;
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