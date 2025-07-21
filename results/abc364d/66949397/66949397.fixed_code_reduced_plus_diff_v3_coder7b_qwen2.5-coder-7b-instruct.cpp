#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <limits>

using m_int = long long;
using std::cin;
using std::cout;
using std::priority_queue;
using std::make_pair;

struct Compare {
    bool operator()(const pair<m_int, m_int>& a, const pair<m_int, m_int>& b) {
        return a.first > b.first;
    }
};

int main() {
    
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    while (q--) {
        
        m_int b, k; cin >> b >> k;
        
        priority_queue<pair<m_int, m_int>, vector<pair<m_int, m_int>>, Compare> pq;
        
        for (m_int ai : a) {
            m_int dist = abs(b - ai);
            
            if (pq.size() < k) {
                pq.push(make_pair(dist, ai));
            } else if (dist < pq.top().first) {
                pq.pop();
                pq.push(make_pair(dist, ai));
            }
        }
        
        cout << pq.top().second << "\n";
    }
    
    return 0;
}