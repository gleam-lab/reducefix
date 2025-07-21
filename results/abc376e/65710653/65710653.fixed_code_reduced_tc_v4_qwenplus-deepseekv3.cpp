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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        sort(ab.begin(), ab.end());

        multiset<ll> ms;
        ll sum = 0;
        rep(i, 0, k - 1) {
            ms.insert(ab[i].second);
            sum += ab[i].second;
        }
        ll ans = LLONG_MAX;
        rep(i, k - 1, n) {
            ms.insert(ab[i].second);
            sum += ab[i].second;
            if (ms.size() > k) {
                sum -= *ms.begin();
                ms.erase(ms.begin());
            }
            ans = min(ans, ab[i].first * sum);
        }
        cout << ans << '\n';
    }
    return 0;
}