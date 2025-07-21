#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    rep(qi, t) {
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> items(n);
        rep(i, n) {
            cin >> items[i].first; // A_i
        }
        rep(i, n) {
            cin >> items[i].second; // B_i
        }

        // Sort items by A_i ascending
        sort(items.begin(), items.end());

        ll sumB = 0;
        multiset<ll> b_values;

        // Initialize with first K elements
        rep(i, k) {
            sumB += items[i].second;
            b_values.insert(items[i].second);
        }

        ll ans = items[k - 1].first * sumB;

        // Try to improve answer using remaining elements
        for (int i = k; i < n; ++i) {
            // Remove the largest B value in the current set
            sumB -= *b_values.rbegin();
            b_values.erase(prev(b_values.end()));

            // Add the new B value
            sumB += items[i].second;
            b_values.insert(items[i].second);

            // Update answer
            ans = min(ans, items[i].first * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}