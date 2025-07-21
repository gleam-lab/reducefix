#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()

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
        
        priority_queue<ll> max_heap;
        ll sum = 0;
        rep(i, 0, K - 1) {
            max_heap.push(pairs[i].second);
            sum += pairs[i].second;
        }
        
        ll ans = LLONG_MAX;
        rep(i, K - 1, N) {
            ll current_sum = sum + pairs[i].second;
            ans = min(ans, pairs[i].first * current_sum);
            if (!max_heap.empty() && pairs[i].second < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                sum += pairs[i].second;
                max_heap.push(pairs[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}