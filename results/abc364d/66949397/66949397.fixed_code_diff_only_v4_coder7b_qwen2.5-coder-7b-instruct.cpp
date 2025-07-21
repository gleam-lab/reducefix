#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;
using std::unordered_map;

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    while (q--) {
        m_int b, k; cin >> b >> k;
        
        // Priority queue to store the k smallest distances
        priority_queue<pair<m_int, int>, vector<pair<m_int, int>>, greater<>> pq;
        
        for (m_int i = 0; i < n; ++i) {
            m_int dist = abs(a[i] - b);
            if (pq.size() < k) {
                pq.push({dist, i});
            } else if (dist < pq.top().first) {
                pq.pop();
                pq.push({dist, i});
            }
        }
        
        cout << pq.top().first << "\n";
    }
    
    return 0;
}