#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> A[MAXN];
int N, M;

// Function to perform binary search to find the k-th smallest element
int findKthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;
    vector<int> a(A[0].begin(), A[0].end()); // Collect all points into one array

    // Read input points
    for(int i = 1; i <= N; ++i) {
        cin >> a[i-1];
        A[0].push_back(a[i-1]);
    }

    // Process each query
    for(int j = 0; j < M; ++j) {
        int b, k;
        cin >> b >> k;
        vector<int> distances;

        // Calculate distances from point b to all other points
        for(auto &point : a) {
            distances.push_back(abs(b - point));
        }

        // Find the k-th smallest distance
        cout << findKthSmallest(distances, k) << "\n";
    }

    return 0;
}