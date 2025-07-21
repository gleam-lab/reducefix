#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // Find the minimum possible value of the maximum value of B minus the minimum value of B
    int minDiff = abs(A[n - k] - A[k - 1]);
    for (int i = 0; i < k; ++i) {
        minDiff = min(minDiff, abs(A[n - k + i] - A[k - 1 - i]));
    }

    cout << minDiff << endl;

    return 0;
}