#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> ab(n);
        for (int i = 0; i < n; i++) cin >> ab[i].first;
        for (int i = 0; i < n; i++) cin >> ab[i].second;
        
        // Sort based on A in descending order
        sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
        
        ll ans = INF;
        for (int i = 0; i <= min(k, (int)n); ++i) {
            ll sumB = 0;
            ll maxA = ab[i - 1].first; // maxA for the current subset size i
            for (int j = 0; j < i; ++j) {
                sumB += ab[j].second;
            }
            ans = min(ans, maxA * sumB);
        }
        cout << ans << '\n';
    }
    return 0;
}