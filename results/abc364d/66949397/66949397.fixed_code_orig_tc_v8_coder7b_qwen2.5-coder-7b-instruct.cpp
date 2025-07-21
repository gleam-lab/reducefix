#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

struct Point {
    m_int value;
    int index;
};

struct CompareDistances {
    vector<vector<m_int>>& distances;
    
    CompareDistances(vector<vector<m_int>>& dists) : distances(dists) {}
    
    bool operator()(const Point& p1, const Point& p2) {
        return distances[p1.index].back() > distances[p2.index].back();
    }
};

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Store all distances for each point
    vector<vector<m_int>> distances(n);

    while (q--) {
        m_int b, k; cin >> b >> k;
        
        // Calculate distances for each point
        for (m_int i = 0; i < n; ++i) {
            distances[i].push_back(abs(a[i] - b));
        }
        
        // Min-heap to keep track of the k-th smallest distance
        priority_queue<Point, vector<Point>, CompareDistances> pq(distances);
        
        // Extract the k-th smallest distance
        for (int i = 1; i < k; ++i) {
            pq.pop();
        }
        
        cout << pq.top().value << "\n";
    }
    
    return 0;
}