#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> leftMin(n), rightMax(n);

    leftMin[0] = A[0];
    for (int i = 1; i < n; ++i) {
        leftMin[i] = min(leftMin[i - 1], A[i]);
    }

    rightMax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], A[i]);
    }

    int minDiff = INT_MAX;

    // Try removing K elements from the left
    for (int i = 0; i <= n - k; ++i) {
        int maxVal = rightMax[i + k - 1];
        if (i > 0) {
            maxVal = max(maxVal, leftMin[i - 1]);
        }
        int minVal = leftMin[i];
        minDiff = min(minDiff, maxVal - minVal);
    }

    // Try removing K elements from the right
    for (int i = 0; i <= n - k; ++i) {
        int maxVal = rightMax[n - k - i];
        if (i > 0) {
            maxVal = max(maxVal, rightMax[i - 1]);
        }
        int minVal = rightMax[n - k - i];
        minDiff = min(minDiff, maxVal - minVal);
    }

    cout << minDiff << endl;

    return 0;
}