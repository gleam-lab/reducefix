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

    // We will consider the minimum possible value of max(B) - min(B)
    // where B is formed by removing exactly K elements.

    // To minimize max(B) - min(B), we can think of choosing a subsequence of length N-K
    // with the smallest range.

    // One effective strategy:
    // Try all windows of size (n - k) in the sorted array and compute the minimal difference
    // between last and first element in window. This works because to minimize the range,
    // we must choose contiguous elements in the sorted array.

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    long long res = numeric_limits<long long>::max();

    // Sliding window of size (n - k)
    for (int i = 0; i + (n - k) <= n; ++i) {
        res = min(res, 1LL * sortedA[i + (n - k) - 1] - sortedA[i]);
    }

    cout << res << "\n";
    return 0;
}