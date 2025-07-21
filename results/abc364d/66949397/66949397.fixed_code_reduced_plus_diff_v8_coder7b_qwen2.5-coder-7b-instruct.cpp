#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    while (q--) {
        m_int b, k; cin >> b >> k;
        
        // Create a min heap to keep track of the k closest distances
        priority_queue<pair<m_int, m_int>, vector<pair<m_int, m_int>>, greater<pair<m_int, m_int>>> pq;
        
        for (const auto& ai : a) {
            m_int dist = abs(ai - b);
            if (pq.size() < k) {
                pq.push({dist, ai});
            } else if (dist < pq.top().first) {
                pq.pop();
                pq.push({dist, ai});
            }
        }
        
        cout << pq.top().second - b << "\n";
    }
    
    return 0;
}