#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath> // For std::abs

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Pair each a_i with the absolute distance to each b_j
    vector<std::pair<m_int, m_int>> dists;
    for (m_int i = 0; i < n; ++i) {
        for (m_int j = 0; j < q; ++j) {
            m_int b, k; cin >> b >> k;
            m_int distance = std::abs(a[i] - b);
            dists.emplace_back(distance, k);
        }
    }

    // Sort distances by the distance value
    std::sort(dists.begin(), dists.end());

    // For each b_j, find the k-th closest distance
    while (q--) {
        m_int b, k; cin >> b >> k;
        // k for sorting purposes is 1-based index, we need to access k-th element, which is k-1
        cout << dists[n * q - q + k - 1].first << "\n";
    }
}