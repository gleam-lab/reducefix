#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N), B(Q), K(Q);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < Q; ++j) {
        cin >> B[j] >> K[j];
    }
    
    // Pair each A_i with the index j and sort by A_i
    vector<pair<long long, int>> points(N);
    for (int i = 0; i < N; ++i) {
        points[i] = {A[i], i};
    }
    sort(points.begin(), points.end());
    
    // Use a fenwick tree to store the counts of distances
    vector<vector<int>> fenwick_tree(N + 1, vector<int>(N + 1, 0));
    
    // Initialize the first level of the fenwick tree with counts of distances
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K[points[i].second] - 1; ++j) {
            fenwick_tree[j + 1][i + 1]++;
        }
    }
    
    // Function to add to fenwick tree
    auto add = [&](int delta, int x, int y) {
        for (; x <= N; x = x | (x + 1)) {
            fenwick_tree[x][y]++;
        }
    };
    
    // Function to get the sum from fenwick tree
    auto get = [&](int x, int y) {
        int s = 0;
        for (; x > 0; x = x & (x - 1)) {
            s += fenwick_tree[x][y];
        }
        return s;
    };
    
    // Process each query
    for (int j = 0; j < Q; ++j) {
        long long b = B[j];
        // For each k_j-th closest distance
        for (int k = 1; k <= K[j]; ++k) {
            // Adjust the fenwick tree counts
            // Decrease the count of the previous point
            add(-1, points[k - 1].second + 1, k);
            // Increase the count of the current point
            add(1, points[k].second + 1, k);
            // Find the k-th closest distance
            int distance = points[k].first - b;
            // Get the count of distances less than this
            long long count = get(k - 1, distance + 1);
            cout << distance << endl;
        }
    }
    
    return 0;
}