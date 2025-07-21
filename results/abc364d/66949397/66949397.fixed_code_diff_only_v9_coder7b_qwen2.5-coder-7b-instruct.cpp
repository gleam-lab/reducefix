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

        // Calculate distances from point B_j to all points A_i
        vector<m_int> distances;
        for (const auto& ai : a) {
            distances.push_back(abs(ai - b));
        }

        // Sort the distances in ascending order
        std::sort(distances.begin(), distances.end());

        // The k-th closest point will have the k-th smallest distance
        cout << distances[k - 1] << "\n";
    }
}