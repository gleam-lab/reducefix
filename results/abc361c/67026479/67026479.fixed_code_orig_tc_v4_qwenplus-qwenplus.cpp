#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int m = n - k; // Length of the resulting sequence B

    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Create prefix min and max arrays
    vector<int> minLeft(n), maxLeft(n);
    vector<int> minRight(n), maxRight(n);

    minLeft[0] = A[0];
    maxLeft[0] = A[0];
    for (int i = 1; i < n; ++i) {
        minLeft[i] = min(minLeft[i - 1], A[i]);
        maxLeft[i] = max(maxLeft[i - 1], A[i]);
    }

    minRight[n - 1] = A[n - 1];
    maxRight[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minRight[i] = min(minRight[i + 1], A[i]);
        maxRight[i] = max(maxRight[i + 1], A[i]);
    }

    // Now iterate over all possible windows of size m
    long long minDiff = numeric_limits<long long>::max();

    for (int i = 0; i + m <= n; ++i) {
        int left = i;
        int right = i + m - 1;

        int currMin, currMax;

        if (left == 0) {
            currMin = minRight[right];
            currMax = maxRight[right];
        } else if (right == n - 1) {
            currMin = minLeft[left + m - 1];
            currMax = maxLeft[left + m - 1];
        } else {
            currMin = min(minLeft[left + m - 1], minRight[right]);
            currMax = max(maxLeft[left + m - 1], maxRight[right]);
        }

        minDiff = min(minDiff, (long long)(currMax - currMin));
    }

    cout << minDiff << endl;
}