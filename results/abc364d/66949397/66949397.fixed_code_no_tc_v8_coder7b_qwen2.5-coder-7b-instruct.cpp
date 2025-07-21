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

        // Calculate distances from b to all points a_i
        vector<m_int> distances(n);
        for (m_int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - b);
        }

        // Sort distances
        std::sort(distances.begin(), distances.end());

        // The k-th closest distance
        cout << distances[k-1] << "\n";
    }
}