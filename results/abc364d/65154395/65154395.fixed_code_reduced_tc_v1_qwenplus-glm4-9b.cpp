#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 200000; // Since the coordinate values range up to 10^8, we need a large array to store distances.

int a[N + 1]; // Array to keep track of distances, +1 for 1-based indexing.

// Function to calculate the distance between a point A and B
int dist(int A, int B) {
    return abs(A - B);
}

// Function to perform binary search to find the k-th closest point to B
int binary_search(int B, int k) {
    int left = 0, right = N;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= k) {
            right = mid; // k-th closest point can be at mid or before mid
        } else {
            left = mid + 1; // k-th closest point must be after mid
        }
    }
    return left; // left and right should be the same at the end
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j < N; ++j) {
            a[dist(A, j)]++; // Increment the count of distance j
        }
    }
    for (int i = 1; i <= q; ++i) {
        int B, k;
        cin >> B >> k;
        int result = binary_search(B, k);
        cout << result << endl; // Print the k-th closest distance
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}