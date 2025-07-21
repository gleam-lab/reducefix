#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long long, long long>;

const int MAXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<pll> ab(n);
        for (int i = 0; i < n; ++i) {
            ab[i] = {a[i], b[i]};
        }

        sort(ab.begin(), ab.end());

        multiset<ll> ms;
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            ms.insert(ab[i].second);
            sum += ab[i].second;
        }

        ll ans = sum * ab[k - 1].first;

        for (int i = k; i < n; ++i) {
            sum -= *ms.rbegin();
            ms.erase(ms.find(ab[i - k].second));
            ms.insert(ab[i].second);
            sum += ab[i].second;
            ans = min(ans, sum * ab[i].first);
        }

        cout << ans << '\n';
    }

    return 0;
}