#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int result = A[N - 1] - A[0]; // Initialize with the entire range
    
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        if (j >= i) {
            result = min(result, A[j] - A[i]);
        }
    }
    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}