#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2 * 100050;
int n, x[MAX_N], p[MAX_N], q, a[MAX_N];

// Function to perform binary search to find the first index greater than or equal to target
int binarySearchFirstGreaterOrEqual(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// Function to perform binary search to find the first index greater than target
int binarySearchFirstGreaterThan(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        a[i] = (i == 0 ? 0 : a[i - 1]) + p[i];
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // Find the range [l, r]
        int startIdx = binarySearchFirstGreaterOrEqual(x, n, l);
        int endIdx = binarySearchFirstGreaterThan(x, n, r);

        // Adjust endIdx to be within bounds
        if (endIdx >= n || x[endIdx] != r) endIdx--;

        // Calculate the result
        long long result = a[endIdx] - (startIdx == 0 ? 0 : a[startIdx - 1]);
        cout << result << endl;
    }

    return 0;
}