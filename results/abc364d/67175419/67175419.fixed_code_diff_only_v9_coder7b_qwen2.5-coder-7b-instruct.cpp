#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the kth smallest distance
int findKthSmallestDistance(int b, vector<int>& distances) {
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y;
    cin >> n >> m;
    for (i = 1; i <= n; i++) 
        cin >> a[i];
    
    // Process each query
    while (m--) {
        cin >> x >> k;
        vector<int> distances;
        
        // Calculate all distances from current B_j to all A_i
        for (i = 1; i <= n; i++) {
            distances.push_back(abs(a[i] - x));
        }
        
        // Find the k-th smallest distance
        int result = findKthSmallestDistance(x, distances);
        cout << result << "\n";
    }

    return 0;
}