#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 200020; // Large enough array to handle shifts

int a[N]; // Array to store the cumulative counts of points

// Function to find the k-th smallest distance between a_i and b_j
int findKthSmallest(int b, int k) {
    int l = -1 * 1e8, r = 1e8;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        // Binary search for the smallest value of i such that there are at least k points of A within [a_i - mid, a_i + mid]
        int count = 0, left = max(b - mid, -1e8), right = min(b + mid, 1e8);
        for (int i = left; i <= right; ++i) {
            count += a[i + (N - 5) / 2];
        }
        if (count >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // Calculate the k-th smallest distance
    return b - l;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize the array to count occurrences
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x + (N - 5) / 2] = 1; // Increment the count at the shifted position
        if (x > -1e8 && x < 1e8) a[x + (N - 5) / 2] = 0; // Reset positions outside the range
    }
    
    // Compute the prefix sums
    for (int i = 1; i < N; ++i) {
        a[i] += a[i - 1];
    }
    
    // Process each query
    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << findKthSmallest(b, k) << endl;
    }
    
    return 0;
}