#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    int n, q;
    cin >> n >> q;
    vi a(n), b(q), k(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> b[i] >> k[i];

    // Precompute the sorted distances and their indices
    vector<pair<int, int>> distances; // pair<distance, index>
    rep(i, n) {
        for (int j = 0; j < q; j++) {
            int dist = abs(a[i] - b[j]);
            distances.push_back({dist, i});
        }
    }

    // Sort the distances (compare by distance first, then by index)
    sort(distances.begin(), distances.end());

    // Use a Fenwick tree (Binary Indexed Tree) to efficiently find the k-th smallest distance
    vector<ll> fenwickTree(n + 1, 0); // Fenwick Tree to keep track of counts
    function<ll(int)> query = [&](int idx) -> ll {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += fenwickTree[idx];
        return sum;
    };
    function<void(int, ll)> update = [&](int idx, ll val) -> void {
        for (; idx <= n; idx += idx & -idx) fenwickTree[idx] += val;
    };

    // Process each query
    rep(i, q) {
        int targetIndex = k[i] - 1; // Convert to 0-based index
        int current = 0;
        while (targetIndex >= 0) {
            if (query(current + 1) > targetIndex) {
                // We found our answer
                cout << distances[targetIndex].first << endl;
                break;
            }
            current = distances[targetIndex].second;
            targetIndex--;
        }
        // Update the Fenwick Tree with the current index
        update(distances[current].second + 1, 1);
    }

    return 0;
}