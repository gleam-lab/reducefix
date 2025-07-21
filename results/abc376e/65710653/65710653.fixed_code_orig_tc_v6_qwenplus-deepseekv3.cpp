#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pll> pairs(N);
        rep(i, 0, N) cin >> pairs[i].first;
        rep(i, 0, N) cin >> pairs[i].second;
        sort(all(pairs));
        multiset<ll> b_values;
        ll sum = 0;
        ll ans = LLONG_MAX;
        rep(i, 0, N) {
            sum += pairs[i].second;
            b_values.insert(pairs[i].second);
            if (b_values.size() > K) {
                sum -= *b_values.rbegin();
                b_values.erase(--b_values.end());
            }
            if (b_values.size() == K) {
                ans = min(ans, pairs[i].first * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}