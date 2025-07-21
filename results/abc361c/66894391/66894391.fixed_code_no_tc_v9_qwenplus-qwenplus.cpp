#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to keep K elements
    // The window size is (n - k), because we remove exactly K elements
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // Sliding window over the sorted array to find minimum (max - min)
    sort(A.begin(), A.end());
    for (int i = 0; i + window_size - 1 < n; ++i) {
        int current_min = A[i];
        int current_max = A[i + window_size - 1];
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << endl;
    return 0;
}