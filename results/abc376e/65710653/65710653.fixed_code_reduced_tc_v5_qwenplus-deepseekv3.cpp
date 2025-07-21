#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()

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
        rep(i, 0, k) {
            pq.push(ab[i].second);
            sum += ab[i].second;
        }
        ll res = sum * ab[k - 1].first;
        rep(i, k, n) {
            if (ab[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(ab[i].second);
                sum += ab[i].second;
            }
            res = min(res, sum * ab[i].first);
        }
        cout << res << "\n";
    }
    return 0;
}