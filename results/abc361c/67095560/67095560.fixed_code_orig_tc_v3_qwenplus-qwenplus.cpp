#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int& x : A) cin >> x;

    sort(A.begin(), A.end());

    int result = numeric_limits<int>::max();
    for (int i = 0; i + (N - K - 1) < N; ++i) {
        result = min(result, A[i + (N - K - 1)] - A[i]);
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}