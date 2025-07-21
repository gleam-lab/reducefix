#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the k-th smallest distance
int findKthSmallestDistance(int x, int y, int k) {
    vector<int> distances;
    // Calculate all distances from point B_j to points A_i
    for (int i = 1; i <= n; ++i) {
        distances.push_back(abs(a[i] - y));
    }
    
    // Sort the distances
    sort(distances.begin(), distances.end());
    
    // Return the k-th smallest distance (1-based index)
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        cin >> x >> y;
        int result = findKthSmallestDistance(x, y, y);
        cout << result << "\n";
    }
    return 0;
}