#include <iostream>
#include <vector>
#include <algorithm>
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

    // We need to remove exactly K elements such that the remaining N-K elements
    // form a sequence with the minimum possible (max - min)
    // Since order must be preserved, we're looking for a subsequence of length N-K

    // The key insight: the optimal subsequence will be a contiguous segment of N-K elements
    // in the original array, because only then can we preserve order and satisfy removal constraint.

    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i + window_size <= n; ++i) {
        int min_val = *min_element(A.begin() + i, A.begin() + i + window_size);
        int max_val = *max_element(A.begin() + i, A.begin() + i + window_size);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
}