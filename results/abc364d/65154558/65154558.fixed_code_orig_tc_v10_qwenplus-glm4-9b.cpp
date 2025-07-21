#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1), b(q), k(q);
    
    // Input points A
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Input points B and k
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    // Calculate distances and store them
    vector<long long> distances;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            long long distance = abs(a[i] - b[j]);
            distances.push_back(distance);
        }
    }
    
    // Sort distances
    sort(distances.begin(), distances.end());
    
    // Output the k-th smallest distance for each query
    for (int i = 0; i < q; ++i) {
        cout << distances[k[i] - 1] << endl;
    }
    
    return 0;
}