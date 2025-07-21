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
    int min_diff = A.back() - A.front();
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        if (j < i) break;
        min_diff = min(min_diff, A[j] - A[i]);
    }
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}