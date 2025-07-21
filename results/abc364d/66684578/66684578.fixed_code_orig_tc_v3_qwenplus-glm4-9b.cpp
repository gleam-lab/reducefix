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
    
    vector<vector<pair<int, int>>> dist(n);
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        dist[k - 1].emplace_back(abs(b - a[i]), b);
    }
    
    // Step 1: Sort distances for each point in A with respect to each point in B
    for (int i = 0; i < n; ++i) {
        sort(dist[i].begin(), dist[i].end());
    }
    
    // Step 2: Answer each query
    for (int i = 0; i < q; ++i) {
        int k = dist[i][k - 1].first; // k-th smallest distance
        cout << k << endl;
    }
    
    return 0;
}