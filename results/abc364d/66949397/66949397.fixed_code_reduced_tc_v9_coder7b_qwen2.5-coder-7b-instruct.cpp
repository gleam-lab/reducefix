#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

struct Distance {
    m_int dist;
    int index;
};

bool operator<(const Distance& a, const Distance& b) {
    return a.dist > b.dist;
}

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
        
        // Min-heap to store distances
        priority_queue<Distance> pq;
        
        for (m_int i = 0; i < n; ++i) {
            m_int dist = abs(a[i] - b);
            pq.push({dist, i});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The top of the heap contains the k-th smallest distance
        cout << pq.top().dist << "\n";
    }
    
    return 0;
}