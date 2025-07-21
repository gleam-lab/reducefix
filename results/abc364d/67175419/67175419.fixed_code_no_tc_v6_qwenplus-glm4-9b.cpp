#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N];
int k[N]; // To store the k_j values for each B_j

// Function to calculate the distance between A_i and B_j
int dist(int i, int j) {
    return abs(a[i] - k[j]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Precompute the distances for each A_i to each B_j
    vector<vector<int>> precomputed(n + 1, vector<int>(q + 1));
    for (int j = 1; j <= q; j++) {
        cin >> k[j];
        for (int i = 1; i <= n; i++) {
            precomputed[i][j] = dist(i, j);
        }
    }

    // Sort the distances for each B_j
    for (int j = 1; j <= q; j++) {
        sort(precomputed[1][j].begin(), precomputed[1][j].end());
    }

    // Answer the queries
    for (int j = 1; j <= q; j++) {
        // Find the k_j-th closest point among A_1, ..., A_N to B_j
        cout << precomputed[k[j]][j][k[j] - 1] << "\n";
    }

    return 0;
}