#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000010; // Points range +1 for inclusive indices
int count[MAX_N]; // To store the prefix sum of counts

// Function to perform binary search for the k-th smallest distance
long long binarySearch(int left, int right, int target, int b_j) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        // Count of points within the range [a_i, a_i + mid]
        int countInRange = count[mid] - count[b_j - mid];
        if (countInRange >= target) {
            right = mid; // Continue searching in the left half
        } else {
            left = mid + 1; // Continue searching in the right half
        }
    }
    return b_j + left; // The k-th closest point to B_j
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x + 100000000]++; // Increment count of points at x + 100000000
    }

    for (int j = 0; j < q; j++) {
        int b_j, k_j;
        cin >> b_j >> k_j;
        // Binary search for the k-th closest point to B_j
        long long result = binarySearch(0, 200000000, k_j, b_j);
        cout << result - b_j << endl; // Output the distance
    }
}

int main() {
    solve();
    return 0;
}