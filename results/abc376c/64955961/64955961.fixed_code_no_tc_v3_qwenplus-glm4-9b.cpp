#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinimumBoxSize(int n, vector<int>& a, vector<int>& b) {
    vector<int> maxOfLeft(n);
    maxOfLeft[0] = a[0];

    // Calculate max of the left part
    for (int i = 1; i < n; i++) {
        maxOfLeft[i] = max(maxOfLeft[i - 1], a[i]);
    }

    // Binary search for the smallest x
    int low = 0, high = 1e9 + 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        int i = 0, j = 0;
        int count = 0;
        // Check if all toys can be placed in boxes of size <= mid
        while (i < n && j < n - 1) {
            if (maxOfLeft[i] <= b[j] || a[i] <= mid) {
                i++;
            } else {
                count++;
                j++;
            }
        }
        // Adjust binary search bounds
        if (count <= n - 1) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (count <= n - 1) ? low : -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    int result = findMinimumBoxSize(n, a, b);
    cout << result << endl;
    return 0;
}