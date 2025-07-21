#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<pll> AB(N);
        rep(i, 0, N) cin >> AB[i].first;
        rep(i, 0, N) cin >> AB[i].second;
        sort(all(AB));

        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MAX;

        rep(i, 0, N) {
            sum += AB[i].second;
            pq.push(AB[i].second);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, sum * AB[i].first);
            }
        }
        cout << ans << el;
    }
    return 0;
}