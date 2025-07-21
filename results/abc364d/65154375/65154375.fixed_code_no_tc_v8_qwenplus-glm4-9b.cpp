#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;
int a[MAX_N + 1]; // Adjusted for 1-based indexing
int b[MAX_N + 1]; // Adjusted for 1-based indexing

// Function to perform binary search
int binarySearch(int x, int y) {
    int l = -1, r = 1000000000;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (a[mid + x] - a[mid - x] >= y) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x + MAX_N]++; // Increment frequency at offset to avoid negative indices
    }
    for (int i = 1; i <= MAX_N; i++) {
        a[i] += a[i - 1]; // Accumulate frequency
    }
    for (int j = 0; j < q; j++) {
        cin >> x >> y;
        // Adjust x to be within the range of the array
        x = max(0, min(MAX_N, x + MAX_N));
        // Perform binary search to find the closest point A_i
        int result = binarySearch(x, y);
        cout << result - x << endl;
    }
}

int main() {
    solve();
    return 0;
}