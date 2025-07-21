#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n);

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        // Calculate distances from B_j to all A_i
        vector<m_int> dist(n);
        for (m_int i = 0; i < n; ++i) {
            dist[i] = std::abs(a[i] - b);
        }

        // Sort distances
        std::sort(dist.begin(), dist.end());

        // Output the k-th smallest distance
        cout << dist[k - 1] << "\n";
    }
}