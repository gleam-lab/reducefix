#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using vi = vector<int>;

template<typename T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(all(A));

    // We remove exactly K elements, so we keep (N - K) elements.
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Try all possible contiguous subarrays of length (N - K)
    int ans = A[N - 1] - A[0]; // worst case: no removal benefit
    int keep = N - K;

    for (int i = 0; i + keep - 1 < N; i++) {
        chmin(ans, A[i + keep - 1] - A[i]);
    }

    cout << ans << endl;
    return 0;
}