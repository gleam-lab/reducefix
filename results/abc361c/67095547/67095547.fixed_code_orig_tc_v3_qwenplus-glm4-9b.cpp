#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Calculate minimum difference by considering different removal strategies
    int minDifference = INT_MAX;
    int left = 0, right = n - 1;

    // Try removing k elements from the left
    for (int i = 0; i <= k; ++i) {
        if (right - left + 1 - i < 2) break; // Not enough elements to remove
        int maxVal = A[right - i], minVal = A[left];
        minDifference = min(minDifference, maxVal - minVal);
    }

    // Try removing k elements from the right
    for (int i = 0; i <= k; ++i) {
        if (right - left + 1 - i < 2) break; // Not enough elements to remove
        int maxVal = A[right], minVal = A[left + i];
        minDifference = min(minDifference, maxVal - minVal);
    }

    // Try removing k/2 elements from the left and k/2 from the right
    if (k % 2 == 1) {
        for (int i = 0, j = 0; i <= k / 2 && j <= k / 2; ++i, ++j) {
            if (right - left - i - j + 1 < 2) break; // Not enough elements to remove
            int maxVal = max(A[right - i], A[right - j]), minVal = min(A[left], A[left + j]);
            minDifference = min(minDifference, maxVal - minVal);
        }
    }

    cout << minDifference << endl;
    return 0;
}