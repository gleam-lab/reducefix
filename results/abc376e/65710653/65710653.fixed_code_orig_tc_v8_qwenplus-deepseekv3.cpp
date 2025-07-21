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
        rep(i, 0, K - 1) {
            pq.push(AB[i].second);
            sum += AB[i].second;
        }

        ll ans = LLONG_MAX;
        rep(i, K - 1, N) {
            sum += AB[i].second;
            ans = min(ans, AB[i].first * sum);
            if (!pq.empty() && pq.top() > AB[i].second) {
                sum -= pq.top();
                pq.pop();
                pq.push(AB[i].second);
                sum += AB[i].second;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}