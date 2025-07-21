#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    // We need to remove exactly K elements so that the remaining N-K elements form a subsequence
    // with minimum (max - min)

    // Strategy:
    // Since we want the smallest possible difference between max and min of any such subsequence,
    // we can consider all windows of size L = N - K in the sorted array.
    // The minimal value of (A[i+L-1] - A[i]) over i=0..n-L gives the answer

    int L = n - k;
    sort(A.begin(), A.end());

    long long min_diff = LLONG_MAX;
    for (int i = 0; i + L <= n; ++i) {
        min_diff = min(min_diff, (long long)(A[i + L - 1] - A[i]));
    }

    cout << min_diff << endl;
}