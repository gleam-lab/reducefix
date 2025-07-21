#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Sort points A
    sort(a.begin(), a.end());

    // For each query, find the k-th closest point from B_j to A
    for (auto &query : queries) {
        int b = query.first;
        int k = query.second;
        int smallestDistance = INT_MAX;
        
        // Use a min-heap to store distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Compute distances and add them to the min-heap
        for (int i = 0; i < n; ++i) {
            int distance = abs(a[i] - b);
            pq.push({distance, i});
            // Keep only k closest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The k-th closest element is at the top of the min-heap
        smallestDistance = pq.top().first;
        cout << smallestDistance << endl;
    }

    return 0;
}