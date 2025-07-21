#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN], b[MAXN], k[MAXN];

// Function to find the k-th smallest element in an array
int findKthSmallest(vector<int>& arr, int k) {
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
    return arr[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    // Read coordinates of points A_i
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Process each query
    for (int j = 1; j <= q; ++j) {
        cin >> b[j] >> k[j];
        
        // Calculate distances from B_j to all points A_i
        vector<int> distances(n);
        for (int i = 1; i <= n; ++i) {
            distances[i - 1] = abs(a[i] - b[j]);
        }
        
        // Find the k-th smallest distance
        int result = findKthSmallest(distances, k[j]);
        cout << result << "\n";
    }

    return 0;
}