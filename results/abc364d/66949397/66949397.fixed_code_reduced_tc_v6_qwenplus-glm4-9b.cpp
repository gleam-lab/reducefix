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

        // Get the k-th closest point to B_j from A
        m_int closest_distance = abs(a[k - 1] - b);
        
        // Calculate the distance to the k-th closest point
        m_int answer = closest_distance * closest_distance;

        cout << answer << "\n";
    }
}