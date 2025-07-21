#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, ll>> queries(q);
    for (ll i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }

    // Sort the array A to prepare for binary search
    sort(a.begin(), a.end());

    // Precompute the prefix sums of counts in A
    vector<ll> prefix(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + 1;
    }

    // Process each query
    for (auto& query : queries) {
        ll b = query.first;
        ll k = query.second;

        // Binary search to find the k-th closest point A to B
        ll l = 0, r = n;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (prefix[mid] < k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        // Calculate the distance to the k-th closest point
        ll distance = abs(a[l] - b);
        cout << distance << endl;
    }

    return 0;
}