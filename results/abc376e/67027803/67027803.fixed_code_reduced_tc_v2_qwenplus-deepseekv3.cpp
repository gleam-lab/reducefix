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
    
    priority_queue<ll> heap; // max heap to store the smallest K-1 B_i's
    ll sum = 0;
    ll ans = inf;
    
    for (int i = 0; i < n; i++) {
        ll a = ab[i].first;
        ll b = ab[i].second;
        if (heap.size() < k - 1) {
            heap.push(b);
            sum += b;
        } else {
            ans = min(ans, a * (sum + b));
            if (!heap.empty() && heap.top() > b) {
                sum -= heap.top();
                heap.pop();
                sum += b;
                heap.push(b);
            }
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