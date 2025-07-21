#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

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
        
        auto distances = a;
        for (auto& x : distances) {
            x = abs(x - b);
        }
        
        std::nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        
        cout << distances[k - 1] << "\n";
    }

    return 0;
}