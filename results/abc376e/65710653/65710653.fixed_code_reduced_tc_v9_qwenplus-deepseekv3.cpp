#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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
            if (pq.size() < k) {
                pq.push(ab[i].second);
                sum += ab[i].second;
            } else if (pq.top() > ab[i].second) {
                sum -= pq.top();
                pq.pop();
                pq.push(ab[i].second);
                sum += ab[i].second;
            }
            if (pq.size() == k) {
                ans = min(ans, ab[i].first * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}