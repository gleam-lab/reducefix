#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int min_diff = LLONG_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = i + (N - K) - 1;
        min_diff = min(min_diff, A[j] - A[i]);
    }
    return min_diff;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solve() << endl;
    return 0;
}