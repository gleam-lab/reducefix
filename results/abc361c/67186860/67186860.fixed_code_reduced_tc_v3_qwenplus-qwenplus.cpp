#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the array to find tight clusters of N-K elements
    sort(A.begin(), A.end());

    long long min_diff = numeric_limits<long long>::max();
    int window_size = n - k;

    // Slide a window of size (n - k) over the sorted array
    for (int i = 0; i + window_size <= n; ++i) {
        min_diff = min(min_diff, 1LL * A[i + window_size - 1] - A[i]);
    }

    cout << min_diff << endl;
    return 0;
}