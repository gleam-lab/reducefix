#include <bits/stdc++.h>
using namespace std;

vector<long long> a, b;

// Function to find the k-th smallest distance for each B_j
void process_queries(int n, int q) {
    for (int j = 0; j < q; ++j) {
        int b_val, k_val;
        cin >> b_val >> k_val;
        
        // Calculate distances from B_val to all points A_i
        vector<long long> distances;
        for (int i = 0; i < n; ++i) {
            distances.push_back(abs(a[i] - b_val));
        }
        
        // Use a min-heap to find the k-th smallest distance
        nth_element(distances.begin(), distances.begin() + k_val - 1, distances.end());
        
        // The k-th smallest distance
        long long kth_smallest_distance = distances[k_val - 1];
        cout << kth_smallest_distance << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    process_queries(n, q);

    return 0;
}