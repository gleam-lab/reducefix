#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the k-th smallest distance
int findKthSmallestDistance(int b, vector<int>& distances, int k) {
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Read input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Process each query
    while (m--) {
        int b, k;
        cin >> b >> k;

        vector<int> distances(n);
        for (int i = 1; i <= n; i++) {
            distances[i - 1] = abs(a[i] - b);
        }

        // Find and print the k-th smallest distance
        cout << findKthSmallestDistance(b, distances, k) << "\n";
    }

    return 0;
}