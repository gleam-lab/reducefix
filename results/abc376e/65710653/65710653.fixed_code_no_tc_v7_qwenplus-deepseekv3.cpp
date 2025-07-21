#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].fi;
        rep(i, 0, n) cin >> ab[i].se;
        sort(all(ab));

        priority_queue<ll> pq;
        ll sum = 0;
        rep(i, 0, k - 1) {
            pq.push(ab[i].se);
            sum += ab[i].se;
        }

        ll ans = LLONG_MAX;
        rep(i, k - 1, n) {
            ll current_max_a = ab[i].fi;
            ll current_sum = sum + ab[i].se;
            ans = min(ans, current_max_a * current_sum);

            if (!pq.empty() && pq.top() > ab[i].se) {
                sum -= pq.top();
                pq.pop();
                sum += ab[i].se;
                pq.push(ab[i].se);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}