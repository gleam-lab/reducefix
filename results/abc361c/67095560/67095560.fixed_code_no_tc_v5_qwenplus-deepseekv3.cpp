#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define repn(i, x) for(int i = 1; i <= (int)(x); i++)
#define repo(i, x) for(int i = x - 1; i >= 0; i--)
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    
    int min_diff = LLONG_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = i + (N - K) - 1;
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