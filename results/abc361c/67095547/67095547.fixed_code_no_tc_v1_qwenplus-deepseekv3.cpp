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
    int min_diff = LLONG_MAX;
    for (int x = 0; x <= K; ++x) {
        int y = K - x;
        int current_min = A[x];
        int current_max = A[N - 1 - y];
        min_diff = min(min_diff, current_max - current_min);
    }
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}