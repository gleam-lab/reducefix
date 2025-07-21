#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the k-th smallest distance
int findKthSmallestDistance(int x, int y, int k) {
    vector<int> distances;
    // Calculate all distances from point y to any point in array a
    for(int i = 1; i <= n; ++i) {
        distances.push_back(abs(a[i] - y));
    }
    // Sort the distances
    sort(distances.begin(), distances.end());
    // Return the k-th smallest distance (index k-1 because of 0-based indexing)
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    while(m--) {
        int x, y;
        cin >> x >> y;
        // Find and print the k-th smallest distance
        cout << findKthSmallestDistance(x, y, y) << "\n"; // Note: k_j is the second value in the pair (x, y)
    }

    return 0;
}