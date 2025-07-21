#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

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
        
        sort(pairs.begin(), pairs.end());
        
        multiset<ll> topK;
        ll sum = 0;
        rep(i, 0, K - 1) {
            topK.insert(pairs[i].second);
            sum += pairs[i].second;
        }
        
        ll ans = 1e18;
        rep(i, K - 1, N) {
            topK.insert(pairs[i].second);
            sum += pairs[i].second;
            if (topK.size() > K) {
                auto it = prev(topK.end());
                sum -= *it;
                topK.erase(it);
            }
            ans = min(ans, pairs[i].first * sum);
        }
        cout << ans << '\n';
    }
    return 0;
}