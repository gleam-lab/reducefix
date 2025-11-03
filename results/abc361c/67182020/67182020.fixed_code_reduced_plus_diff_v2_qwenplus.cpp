#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We remove exactly K elements, so we keep N-K elements.
    // The remaining elements must be a contiguous subarray in the sorted array
    // to minimize (max - min). We try all possible contiguous subarrays of length N-K.

    int len = N - K;
    if (len == 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = A[len - 1] - A[0]; // first window
    for (int i = 1; i + len - 1 < N; ++i) {
        ans = min(ans, A[i + len - 1] - A[i]);
    }

    cout << ans << endl;

    return 0;
}