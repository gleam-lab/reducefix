#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<ll, ll>;
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
        vector<P> pairs(n);
        vector<ll> a(n), b(n);
        
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        // Pair A and B together and sort by A_i
        vector<pair<ll, ll>> items(n);
        rep(i, n) {
            items[i] = {a[i], b[i]};
        }
        sort(items.begin(), items.end());

        // Sorted list of B values among current K elements
        multiset<ll> b_values;
        ll sumB = 0;
        rep(i, k) {
            b_values.insert(items[i].second);
            sumB += items[i].second;
        }

        ll ans = items[k - 1].first * sumB;

        // Sliding window: add next item and remove the largest B in set
        rep2(i, k, n) {
            // Insert new B_i
            b_values.insert(items[i].second);
            sumB += items[i].second;

            // Remove the largest B in the set
            auto it = prev(b_values.end());
            sumB -= *it;
            b_values.erase(it);

            // Update answer
            ans = min(ans, items[i].first * sumB);
        }

        cout << ans << '\n';
    }
}