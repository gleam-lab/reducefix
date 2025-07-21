#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Sort queries based on the position of B_j
    sort(queries.begin(), queries.end());

    vector<ll> results(q);
    vector<ll> dists(n);

    // Initialize pointers for each query
    vector<int> ptr(q, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = ptr[j]; j < q && queries[j].first == a[i]; ++j) {
            int k = queries[j].second - 1; // Convert to zero-based index
            dists[ptr[j]++] = abs(a[i] - queries[j].first);
        }

        // Sort distances for the current position
        sort(dists.begin(), dists.begin() + ptr[i]);

        // Assign results for the current position
        for (int j = 0; j < ptr[i]; ++j) {
            results[j] = dists[j];
        }
    }

    // Output results
    for (int i = 0; i < q; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}