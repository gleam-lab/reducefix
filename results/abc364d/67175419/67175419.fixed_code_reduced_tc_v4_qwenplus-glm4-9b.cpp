#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200000; // Maximum number of points

// Function to compute the distance between points A_i and B_j
int dist(int a_i, int b_j) {
    return abs(a_i - b_j);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> distances(n);
    int b, k;
    for (int j = 0; j < q; j++) {
        cin >> b >> k;
        for (int i = 0; i < n; i++) {
            distances[i].emplace_back(dist(a[i], b), i);
        }
    }

    // Prepare to read output
    vector<int> results(q);

    // Find k-th closest for each query
    for (int j = 0; j < q; j++) {
        // Extract distances with indices
        vector<pair<int, int>> sorted_distances = distances[j];
        // Sort distances
        sort(sorted_distances.begin(), sorted_distances.end());
        // The k-th closest distance is the first element of the k-th pair
        int kth_closest = sorted_distances[k - 1].first;
        // The k-th closest index is the second element of the k-th pair
        int kth_closest_index = sorted_distances[k - 1].second;
        // Store the result
        results[j] = kth_closest;
    }

    // Output all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}