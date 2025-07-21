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

    int T;
    cin >> T;
    while (T--) {
        int N, K;
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

        ll min_val = LLONG_MAX;
        rep(i, K - 1, N) {
            ll current_max_A = pairs[i].first;
            ll current_sum = sum + pairs[i].second;
            min_val = min(min_val, current_max_A * current_sum);

            if (!max_heap.empty() && pairs[i].second < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                sum += pairs[i].second;
                max_heap.push(pairs[i].second);
            }
        }
        cout << min_val << '\n';
    }
    return 0;
}