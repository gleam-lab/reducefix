#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> queries(q);
    
    // Read the points and queries
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    // Process each query
    for (const auto& [b, k] : queries) {
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(b - a[i]);
        }
        // Sort distances in ascending order
        sort(distances.begin(), distances.end());
        // Output the k-th smallest distance
        cout << distances[k - 1] << endl;
    }
    
    return 0;
}