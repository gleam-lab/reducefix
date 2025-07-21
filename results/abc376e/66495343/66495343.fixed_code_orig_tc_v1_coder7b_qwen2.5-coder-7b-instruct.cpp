#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

const ll INF = 1e18 + 7;

void solve() {
    ll n, k; cin >> n >> k;
    vector<pl> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0, ans = INF;
    for (ll i = 0; i < n; ++i) {
        if (pq.size() < k - 1) {
            pq.push(a[i].second);
            sum += a[i].second;
        } else {
            sum += a[i].second;
            if (pq.size() > k - 1) {
                sum -= pq.top(); pq.pop();
            }
            pq.push(a[i].second);
            ans = min(ans, a[i].first * sum);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll tc; cin >> tc;
    while (tc--) solve();
    return 0;
}