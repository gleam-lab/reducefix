#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define INF 1000000007

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &ai : a) cin >> ai;
    vector<pair<ll, ll>> bq(q);
    for (ll i = 0; i < q; i++) {
        ll b, k; cin >> b >> k;
        bq[i] = {b, k};
    }

    // Sort points A and queries by B value
    sort(a.begin(), a.end());
    sort(bq.begin(), bq.end());

    // Pair the sorted A with sorted B, K
    vector<pair<ll, pair<ll, ll>>> indexed_a(n);
    for (ll i = 0; i < n; i++) {
        indexed_a[i] = {bq[i].first, {a[i], bq[i].second}};
    }
    sort(indexed_a.begin(), indexed_a.end());

    // Compute and print the answer for each query
    for (ll i = 0; i < q; i++) {
        ll b = bq[i].first;
        ll k = bq[i].second;

        // Binary search to find the k-th closest in A
        ll left = 0, right = n - 1, mid, ans = INF;
        while (left <= right) {
            mid = left + (right - left) / 2;
            ll diff = abs(indexed_a[mid].second.first - b);
            if (diff < ans) {
                ans = diff;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Output the k-th closest distance
        cout << ans << endl;
    }

    return 0;
}