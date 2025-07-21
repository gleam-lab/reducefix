#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.end());

    int minDiff = numeric_limits<int>::max();
    for (int i = 0; i + (N - K) <= N; ++i) {
        int currentDiff = A[i + (N - K)] - A[i];
        minDiff = min(minDiff, currentDiff);
    }

    cout << minDiff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}