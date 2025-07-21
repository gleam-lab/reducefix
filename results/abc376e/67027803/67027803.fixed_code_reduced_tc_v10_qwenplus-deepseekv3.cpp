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
    if (k == 1) {
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }
    priority_queue<ll> q;
    ll sum = 0;
    for (int i = 0; i < k-1; i++) {
        q.push(ab[i].second);
        sum += ab[i].second;
    }
    ll ans = inf;
    for (int i = k-1; i < n; i++) {
        auto [a, b] = ab[i];
        ans = min(ans, (sum + b) * a);
        if (!q.empty() && q.top() > b) {
            sum -= q.top();
            sum += b;
            q.pop();
            q.push(b);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}