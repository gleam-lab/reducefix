#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL(t);
    rep(_, 0, t) {
        LL(n, K);
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].fi;
        rep(i, 0, n) cin >> ab[i].se;

        sort(ab.begin(), ab.end());

        priority_queue<ll> pq;
        ll sum = 0;
        rep(i, 0, K - 1) {
            pq.push(ab[i].se);
            sum += ab[i].se;
        }

        ll min_val = LLONG_MAX;
        rep(i, K - 1, n) {
            sum += ab[i].se;
            min_val = min(min_val, ab[i].fi * sum);
            if (!pq.empty() && pq.top() > ab[i].se) {
                sum -= pq.top();
                pq.pop();
                sum += ab[i].se;
                pq.push(ab[i].se);
            } else {
                sum -= ab[i].se;
            }
        }
        cout << min_val << '\n';
    }
    return 0;
}