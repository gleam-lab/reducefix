#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(q);
    vector<int> k(q);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
    }
    
    // Prepare the distance array
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = abs(a[i] - b[i]);
    }
    
    // Sort distances to find the k-th closest for each B_j
    sort(dist.begin(), dist.end());
    
    // Answer the queries
    for (int i = 0; i < q; i++) {
        int k_j = k[i] - 1; // Convert to 0-based index
        if (k_j >= n) {
            cout << 0 << endl; // If k_j is out of bounds, output 0
        } else {
            cout << dist[k_j] << endl;
        }
    }
    
    return 0;
}