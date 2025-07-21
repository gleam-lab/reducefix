#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    vector<pair<m_int, m_int>> queries(n);

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read queries and store them along with the index of B_j
    for (m_int j = 0; j < q; ++j) {
        m_int b, k; cin >> b >> k;
        queries[j] = {b, k};
    }

    // Sort queries by B_j because we want to find the closest A_i to each B_j
    std::sort(queries.begin(), queries.end());

    // Sort A in case we need to find the closest A_i to different B_j in a single iteration
    std::sort(a.begin(), a.end());

    vector<m_int> distances(q);
    m_int j = 0; // Index for queries

    for (auto dist : a) {
        // Move to the next query where B_j is greater than or equal to current A_i
        while (j < q && queries[j].first <= dist) {
            m_int b, k; b = queries[j].first; k = queries[j].second;
            auto it = std::lower_bound(a.begin(), a.end(), b + dist);
            // It could be that A_i is outside the [b - dist, b + dist] range, so we adjust it
            it = std::min(it, std::upper_bound(a.begin(), a.end(), b - dist));
            // Find the k-th closest A_i to B_j
            m_int kth_dist = b - it->distance(b);
            distances[j++] = kth_dist;
        }
    }

    // Output the results for each query
    for (auto d : distances) {
        cout << d << "\n";
    }

    return 0;
}