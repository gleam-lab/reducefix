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
    
    while (q--) {
        m_int b, k; cin >> b >> k;
        vector<m_int> distances(n);
        
        // Calculate the distance between each point in A and B_j
        for (m_int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - b);
        }
        
        // Sort distances in ascending order
        std::sort(distances.begin(), distances.end());
        
        // The k_j-th closest point distance is the k_j-th smallest distance
        cout << distances[k - 1] << "\n";
    }

    return 0;
}