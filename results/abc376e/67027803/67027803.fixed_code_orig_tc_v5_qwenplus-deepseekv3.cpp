#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i=0; i<n; i++) cin >> ab[i].first;
    for (int i=0; i<n; i++) cin >> ab[i].second;
    sort(ab.begin(), ab.end());
    
    if (k == 1) {
        ll ans = inf;
        for (int i=0; i<n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    
    priority_queue<ll> q;
    ll sum = 0;
    ll ans = inf;
    
    for (int i = 0; i < n; i++) {
        auto [a, b] = ab[i];
        if (i >= k-1) {
            ans = min(ans, a * (sum + b));
            if (!q.empty() && q.top() > b) {
                sum -= q.top();
                q.pop();
                sum += b;
                q.push(b);
            }
        } else {
            sum += b;
            q.push(b);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  cin >> t;
    while (t--) solve();
}