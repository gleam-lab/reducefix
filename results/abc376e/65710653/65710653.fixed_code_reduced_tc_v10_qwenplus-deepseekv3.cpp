#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        sort(all(ab));

        priority_queue<ll> pq;
        ll sum = 0;
        rep(i, 0, k - 1) {
            pq.push(ab[i].second);
            sum += ab[i].second;
        }

        ll ans = LLONG_MAX;
        rep(i, k - 1, n) {
            ll current_sum = sum + ab[i].second;
            ans = min(ans, ab[i].first * current_sum);
            if (!pq.empty() && ab[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += ab[i].second;
                pq.push(ab[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}