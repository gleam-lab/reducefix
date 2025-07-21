#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i + (N - K) <= N; ++i) {
        min_diff = min(min_diff, A[i + (N - K)] - A[i]);
    }
    
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}