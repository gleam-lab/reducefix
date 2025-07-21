#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<pll> pairs(N);
        rep(i, 0, N) cin >> pairs[i].first;
        rep(i, 0, N) cin >> pairs[i].second;
        sort(all(pairs));

        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MAX;
        rep(i, 0, N) {
            sum += pairs[i].second;
            pq.push(pairs[i].second);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, pairs[i].first * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}