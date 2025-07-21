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

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k; cin >> b >> k;

        // Calculate the distance from b to each point in a
        vector<m_int> distances(n);
        for (m_int i = 0; i < n; ++i) {
            distances[i] = std::abs(a[i] - b);
        }

        // Get the k-th closest distance
        m_int kth_closest_distance = distances[k - 1];

        // Output the distance between the k-th closest point and B_j
        cout << (distances[k - 1] + 1) * 2 << "\n";
    }
}