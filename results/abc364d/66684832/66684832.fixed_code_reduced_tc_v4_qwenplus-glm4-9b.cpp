#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
vector<int> a, b;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int b_j, k_j;
        cin >> b_j >> k_j;
        queries.emplace_back(b_j, k_j);
    }
    
    // Sort the points A based on their coordinate values
    sort(a.begin(), a.end());
    
    // Process each query
    for (auto& [b_j, k_j] : queries) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            // Check if the k-th smallest distance is within the range a[m] and a[m+1]
            if (a[m] <= b_j && a[m + 1] >= b_j) {
                break; // We have found the range where the k-th closest point is located
            } else if (a[m] < b_j) {
                l = m; // The k-th closest point is further to the right
            } else {
                r = m - 1; // The k-th closest point is further to the left
            }
        }
        
        // Now we need to find the k-th smallest distance
        // We use a vector to store the distances from each A_i to B_j
        vector<int> distances;
        for (int i = 0; i < n; ++i) {
            distances.push_back(abs(a[i] - b_j)); // Calculate distance
        }
        
        // Extract the k-th smallest distance
        nth_element(distances.begin(), distances.begin() + k_j - 1, distances.end());
        cout << distances[k_j - 1] << endl;
    }
    
    return 0;
}